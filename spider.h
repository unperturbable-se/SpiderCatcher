#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "sprites.h"
#include "man.h"

class Spider
{
  float posy=0;
  float posx=200;
  Man* man;
  long long* score;
  long long* clock;
  sf::RenderWindow* window;
  bool isDead{false};
  public:
  Spider(Man* man,long long* score,long long* clock,sf::RenderWindow* window):
  man{man},score{score},clock{clock},window{window} {srand(time(0));}

  void move()
  {
    if(posx<=0)posx=0;
    else if(posx>=1000)posx=900;
    if(posy>=700){posy=0;posx=(rand()%1920)+40;isDead=false;} //40-1960
    if((*clock)%200==1)posx+=(rand()%200)-100;
    posy+=0.3;
  }
  void draw()
  {
    float yrange=posy-man->posy;
    float xrange=posx-man->posx;
    if(abs(yrange)<50 && abs(xrange)<50)
    {
      (*score)++;
      isDead=true;
    }
    else if(!isDead)
    {
      sprites[SPIDER].setPosition({posx,posy});
      window->draw(sprites[SPIDER]);
    }
    if(isDead)
    {
      sprites[INSECT].setPosition({posx,posy});
      window->draw(sprites[INSECT]);
    }
  }
  
};
