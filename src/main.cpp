#include <QApplication>
#include <QMainWindow>
#include "board.h"


int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	auto* mainWindow = new QMainWindow();
	auto* board = new Board(mainWindow);
	mainWindow->setCentralWidget(board);
	mainWindow->show();
	return app.exec();
}
