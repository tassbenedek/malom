#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QMenu>


#include "board.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    auto* mainWindow = new QMainWindow();
	auto* board = new Board(mainWindow);

    mainWindow->setCentralWidget(board);
    
    // Display
    mainWindow->show();
    
    // Event loop
    return app.exec();
}


