#include "note.h"
#include <QTimer>
#include <QKeyEvent>

Note::Note(int pos,QGraphicsScene *ptr, std::queue<Note*>& notes):notesinparent(notes),x(pos*60),y(0){


    QBrush blackbrush (Qt::black);
    QPen blackpen (Qt::black);
    parent=ptr;
    rect=parent->addRect(x,y,60,10,blackpen,blackbrush);

    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

void Note::move(){
    y+=2;
    rect->moveBy(0,2);
    if (y>350){
        parent->removeItem(rect);
        timer->stop();
        notesinparent.pop();
        delete this;
    }
}
