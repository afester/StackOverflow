#!/usr/bin/env python

import pythoncom
import win32com.client

def folderTree(folders, indent = 0):
    """Displays all available folders in a tree structure.

    Keyword arguments:
    folders    --  The current Folders iterator
    indent     --  The current indent level
    """
    prefix = ' ' * (indent*2)
    i = 0
    for folder in folders:
        print("{0}{1}. {2} ({3})".format(prefix, i, folder.Name, folder.DefaultItemType))
        folderTree(folder.Folders, indent + 1)
        i = i + 1


def findFolder(folders, searchPath, level = 0):
    """Find a folder by following a given  folder path.

    Keyword arguments:
    folders    --  The Folders iterator
    searchPath --  The search path - a string array with the folder names 
    level      --  The current search level
    """
    for folder in folders:
        if folder.Name == searchPath[level]:
            if level < len(searchPath)-1:
                # Search sub folder
                folder = findFolder(folder.folders, searchPath, level+1)
            return folder
    return None


def getItemProperty(item, propertyName):
    """Gets a property from an AppointmentItem by name.
       If access to the property is denied, the error text from the exception
       is returned instead.  

    Keyword arguments:
    item          --  The AppointmentItem for which to return a property.
    propertyName  --  The name of the property to return. 
    """
    try:
        result = getattr(item, propertyName)
    except pythoncom.com_error as ce:   # TODO: should further investigate the error code
        result = ce.excepinfo[2]
    return result


def printCalendar(folder):
    """Prints calendar events during the next 30 days.

    Keyword arguments:
    folder    --  The Calendar folder to use.
    """
    import datetime

    # Get the AppointmentItem objects
    # http://msdn.microsoft.com/en-us/library/office/aa210899(v=office.11).aspx
    items = folder.Items

    # Restrict to items in the next 30 days
    begin = datetime.date.today()
    end = begin + datetime.timedelta(days = 30);
    restriction = "[Start] >= '" + begin.strftime("%m/%d/%Y") + "' AND [End] <= '" +end.strftime("%m/%d/%Y") + "'"
    restrictedItems = items.Restrict(restriction)

    # Print items - Note that Outlook might prevent access to individual 
    # item attributes, such as "Organizer", while access to other attributes of
    # the same item is granted.
    for appointmentItem in restrictedItems:
        startDate = getItemProperty(appointmentItem, "Start")
        endDate = getItemProperty(appointmentItem, "End")
        subject = getItemProperty(appointmentItem, "Subject")
        organizer = getItemProperty(appointmentItem, "Organizer")
        print("{0} - {1}: {2} ({3})".format(
                    startDate, endDate, subject, organizer))


if __name__ == "__main__":
    # get Outlook application object
    Outlook = win32com.client.Dispatch("Outlook.Application")
    print("Outlook version: {}".format(Outlook.Version))
    print("Default profile name: {}".format(Outlook.DefaultProfileName))

    # get the Namespace / Session object
    # namespace = Outlook.GetNamespace("MAPI") 
    namespace = Outlook.Session         # identical to GetNameSpace("MAPI") (starting with Outlook 98)
    print("Current profile name: {}".format(namespace.CurrentProfileName))

##### Show tree of all available folders
    print("\nFolders")
    print("-------")
    folderTree(namespace.Folders)

##### get own calendar and print all entries in the next 30 days
    print("\nMy calendar")
    print("---------------")
    myCalendar = namespace.GetDefaultFolder(9)
    printCalendar(myCalendar)

##### get shared calendar and print all entries in the next 30 days
    # Should work, but could not get it to work actually - "Object not found" ...
    #recipient = namespace.createRecipient("Change Me")
    #print(recipient)
    #resolved = recipient.Resolve()
    #print(resolved)
    #print(recipient.resolved)
    #sharedCalendar = namespace.GetSharedDefaultFolder(recipient, 9)
    #printCalendar(sharedCalendar)

##### get shared calendar through folder tree
    print("\nShared calendar")
    print("---------------")
    sharedCalendar = findFolder(namespace.Folders, ["Internet Calendars", "Norfeld@so.com"])
    printCalendar(sharedCalendar)
