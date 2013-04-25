/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/16102523/qt-c-qmap-function
 */

#include <qdebug.h>

class Textbook {
};

class TextbookMap : public QMap<QString, Textbook*> {
public:
    bool foundTextBook(const QString& isbn) const;
};

bool TextbookMap::foundTextBook(const QString& isbn) const {
    return contains(isbn);
#if 0
    bool found = false;
    ConstIterator itr = constBegin();
    for ( ; itr != constEnd(); ++itr)
    {
         if (itr.contains(isbn))
             found = true;
    }
    return found;
#endif
}

int main(int argc, char ** argv) {
	TextbookMap map;
        map.insert("1234", new Textbook());
        map.insert("5678", new Textbook());
        qDebug() << map.foundTextBook("01234");
        qDebug() << map.foundTextBook("1234");

	return 0;
}
