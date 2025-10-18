#include "gui/mainwindow.hpp"
#include "core/filesearcher.hpp"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	FileSearcher fileSearch;
	MainWindow w;
	w.show();
	return app.exec();
}
