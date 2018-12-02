#ifndef GAME_H
#define GAME_H
#include "mainwindow.h"


class Game{
public:
    static Game& Instance();
    void move(QMouseEvent *e);
    void start(MainWindow &wind);
    Gameobject getgameobject(int x,int y);
private:
    Game();
    static Game gInstance;
    MainWindow *window;
    Gameobject gameobject[21][21];
    int Xfoc=0;
    int Yfoc=0;
};
#endif // GAME_H
