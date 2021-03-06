#include "game.h"
#include <iostream>
#include "math.h"
#include "infantry.h"
#include "gameobject.h"
#include "unite.h"

Game Game::gInstance=Game();
Game::Game()
{


}
Game &Game::Instance()
{
    return gInstance;
}

void Game::move(QMouseEvent *e)
{

    if(gameobject[Xfoc][Yfoc].getFocused()){

        float x=floorf(e->x()/40);
        float y=floorf(e->y()/40);
        int m= (int)x-7;
        int t= (int)y-2;

        int distx = abs(Xfoc-m);
        int disty = abs(Yfoc-t);

        if( distx + disty <=3){

        gameobject[Xfoc][Yfoc].setPosX(m);
        gameobject[Xfoc][Yfoc].setPosY(t);
        if((m!=Xfoc || t!=Yfoc) && gameobject[m][t].getId()!=7){
             gameobject[m][t]=gameobject[Xfoc][Yfoc];
             gameobject[Xfoc][Yfoc] = *new Gameobject((int) Xfoc,(int) Yfoc,444);}
        std::cout<< "gameobject[posXselec][posYselec]="<< gameobject[Xfoc][Yfoc].getId()  <<std::endl;


        gameobject[m][t].setFocused(false);
        window->redraw();
        }
        else{
            gameobject[Xfoc][Yfoc].setFocused(false);
        }
    }
    else{
        float x=(e->x()/40);
        float y=(e->y()/40);
        int m= (int)x-7;
        int t= (int)y-2;
       if( gameobject[m][t].getId()==7 ){

             gameobject[m][t].setFocused(true);

             Xfoc=m;
             Yfoc=t;
       }
    }
}

void Game::start(MainWindow &wind)
{
    window = &wind ;
    Infantry inf(5,0,7,true);
    Infantry inf2(6,0,7,false);
    gameobject[5][0]= inf;
    gameobject[6][0]= inf2;
    window->redraw();
}

Gameobject Game::getgameobject(int x, int y)
{
    return gameobject[x][y];

}
