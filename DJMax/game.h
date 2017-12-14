#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "note.h"
#include <queue>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:

    explicit Game(QWidget *parent = 0);
    ~Game();

public slots:
    void createNote();

private:
    Ui::Game *ui;
    QGraphicsScene* scene;
    QTimer *timer;
    std::queue<Note*> notes;
    int scores;


    void updatemissgrade();
    void updatescoregrade(int y);
    void keyPressEvent(QKeyEvent * event);

};

#endif // GAME_H
