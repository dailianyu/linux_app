#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include "qt1.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);


	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")) ;
	//app.setFont(QFont("wenquanyi", 10));
	app.setFont(QFont("simsun", 10));

	Qt1 MD;
    MD.show();

	return app.exec();
}
