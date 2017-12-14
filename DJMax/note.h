#ifndef NOTE_H
#define NOTE_H
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <queue>
#include <QKeyEvent>

class Note : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Note(int pos, QGraphicsScene *parent,std::queue<Note*>& notes);
    int x;
    int y;
    int type;


public slots:
    void move();

private:

    QGraphicsRectItem *rect;
    QTimer *timer;
    QGraphicsScene *parent;
    std::queue<Note*>& notesinparent;
};

#endif // NOTE_H
