/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/21390859/is-it-possible-for-qvalidator-to-show-a-popup
 */

#include <QDebug>
#include <QApplication>
#include "validator.h"


QIntValidatorReporter::QIntValidatorReporter(int minimum, int maximum, QObject * parent) : QIntValidator(minimum, maximum, parent) {
}


QValidator::State QIntValidatorReporter::validate(QString& input, int& pos ) const {
   QValidator::State result = QIntValidator::validate(input, pos);

   if (result == QValidator::Invalid) {
      emit setError(QString("Allowed range: %1 to %2").arg(bottom()).arg(top()));
   } else {
      emit setError("");
   }

   return result;
}


SampleDialog::SampleDialog(QWidget* parent, Qt::WindowFlags f) : QDialog(parent, f) {
   myUi.setupUi(this);

   // set up the validator - we can connect the setError signal directly to the error label
   // alternatively the signal can be connected to any appropriate slot
   validator = new QIntValidatorReporter(0, 50);
   QObject::connect(validator,  SIGNAL(setError(const QString&)),
                    myUi.label, SLOT(setText(const QString&)));
   myUi.lineEdit->setValidator(validator);
}


int main(int argc, char ** argv) {
   QApplication app( argc, argv );

   QDialog* dlg = new SampleDialog(0,0);
   dlg->exec();

   return 0;
}
