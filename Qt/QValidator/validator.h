/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/21390859/is-it-possible-for-qvalidator-to-show-a-popup
 */

#include <QDialog>
#include <QIntValidator>

#include "ui_validator.h"


/**
 * The class QIntValidatorReporter extends QIntValidator with the 
 * possibility to report through a signal whether the current value has
 * been validated as valid or not.
 */
class QIntValidatorReporter : public QIntValidator {
   Q_OBJECT;

public:
   /**
    * @see QIntValidator::QIntValidator(int minimum, int maximum, QObject * parent = 0)
    */
   QIntValidatorReporter(int minimum, int maximum, QObject * parent = 0);

   // @Override
   virtual QValidator::State validate(QString& input, int& pos ) const;

signals:
   /**
    * This signal is emitted whenever the string is validated.
    * If the string is valid, an empty string is passed.
    * If the string is not valid, an appropriate error message is passed.
    */
   void setError(const QString& msg) const;
};

/**
 * A simple sample dialog to show the usage of the QIntValidatorReporter class.
 */
class SampleDialog : public QDialog {
   Ui_Dialog myUi;
   QValidator* validator;

public:
   SampleDialog(QWidget* parent = 0, Qt::WindowFlags f = 0);
};
