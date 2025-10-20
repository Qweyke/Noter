#include "gui/mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow), fileSearcher()
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{

	delete ui;
}

void MainWindow::doInitialConnects()
{
	connect(ui->actionSave, &QAction::triggered, &fileSearcher, &FileSearcher::saveFile)
}

void MainWindow::doSaveFile()
{
	auto text = ui->textEdit->toPlainText();

	FileSearcher::saveFile(text);
}
