#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(show_instruction()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(start_game()));

}

void MainWindow::show_instruction(){
    QMessageBox::information(
        this,
        "Instructions",
        "Instructions <br /><br />"
        "This is a demo game of DJMax.<br />"
        "Hit the notes when they hit the bar<br /> " );

}

void MainWindow::start_game(){
    game= new Game(this);
    this->setCentralWidget(game);
}



MainWindow::~MainWindow()
{
    delete ui;
}
