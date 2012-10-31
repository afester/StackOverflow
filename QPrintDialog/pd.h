/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12723993/how-to-extend-the-qt-print-dialog/12724933#12724933
 */

#include <QPrintDialog>

class MyPrintDialog : public QPrintDialog {
    Q_OBJECT

public:
    MyPrintDialog(QPrinter* p, QWidget* parent);
};
