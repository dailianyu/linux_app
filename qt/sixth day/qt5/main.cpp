#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include <QTranslator>
#include <QWidget>

#include "qt5.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);


//	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")) ;
	//app.setFont(QFont("wenquanyi", 10));
	app.setFont(QFont("simsun", 10));
        
 //    QTranslator translator;
 //    translator.load(QString(argv[1]));
  //   app.installTranslator(&translator);


	Menu MD;
    MD.show();

	return app.exec();
}
