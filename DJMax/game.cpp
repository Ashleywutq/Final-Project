#include "game.h"
#include "ui_game.h"
#include <cstdlib>
#include <QBrush>
#include <QPen>
#include <QLabel>
#include <QKeyEvent>
#include <iostream>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game),
    scores(0)
{
    ui->setupUi(this);

    //create scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,240,360);
    ui->graphicsView->setScene(scene);
    QBrush redbrush (Qt::red);
    QPen redpen (Qt::red);
    scene->addRect(0,340,240,10,redpen,redbrush);

    //create timer to create nodes every second
    timer= new QTimer();
    timer->start(500);
    connect(timer,SIGNAL(timeout()),this,SLOT(createNote()));

}

Game::~Game()
{
    delete ui;
}

void Game::createNote(){
    int position = rand()%4;
    Note *mynote= new Note(position, scene, notes);
    notes.push(mynote);
    return;
}

void Game::updatemissgrade(){
    ui->label_2->setText("Miss");
}

void Game::updatescoregrade(int y){
    if (y<330){
        updatemissgrade();
    }else if (y>350){
        updatemissgrade();
    }else if (y>=335 && y<=345){
        scores+=10;
        ui->label_2->setText("Perfect");
        ui->lcdNumber->display(scores);
    }else{
        scores+=5;
        ui->label_2->setText("Great");
        ui->lcdNumber->display(scores);
    }

}


void Game::keyPressEvent(QKeyEvent *event){


    if(notes.size()==0){return;}

    bool missed = true;

    if (event->key() == Qt::Key_D){
        if(notes.front()->type==0){
            missed = false;
        }
    } else if (event->key() == Qt::Key_F){
        if(notes.front()->type==1){
            missed = false;
        }
    } else if (event->key() == Qt::Key_J){
        if(notes.front()->type==2){
            missed = false;
        }
    } else if (event->key() == Qt::Key_K){
        if(notes.front()->type==3){
            missed = false;
        }
    }

    int pos = notes.front()->y;

    if(!missed){
        updatescoregrade(pos);
    }else{
        updatemissgrade();
    }

}
