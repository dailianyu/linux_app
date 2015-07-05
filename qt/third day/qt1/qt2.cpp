#include "qt2.h"


Qt2::Qt2(QWidget *parent):QDialog(parent)
{
	setupUi(this);
	qt1 = (Qt1 *)parent;
	connect(lineEdit,SIGNAL(textEdited(const QString &)),this,SLOT(sendmessage(QString)));

}

void Qt2::sendmessage(QString value)
{
	qt1->le1->setText(value);
}