#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include "sprites.h"

class Scenery
{
    sf::RenderWindow* window;
    long long* clock;
    public:
    Scenery(sf::RenderWindow* window,long long* clock):window{window},clock{clock}{};
    void makeGrass()
    {
    for(float posx=-80;posx<1000;posx+=50)
       {
        sprites[GRASS].setPosition(sf::Vector2f(posx,600.0));
        window->draw(sprites[GRASS]);
       }
    }

    void addWater()
    {
    for(float posy=900;posy>800;posy-=30)
    for(float posx=-50;posx<1000;posx+=40)
       {
        sprites[WATER].setPosition(sf::Vector2f(posx,posy));
        window->draw(sprites[WATER]);
       }
    }

   void addSun()
   {
    sprites[SUN].setPosition(sf::Vector2f(-15,-15));
    window->draw(sprites[SUN]);
   }

    void addClouds()
    {
    float angle=10*sin((*clock)*0.001);
    for(float posx=200;posx<800;posx+=200)
       {
         sprites[CLOUD].setPosition(sf::Vector2f(posx,-10));
         sprites[CLOUD].setRotation(sf::degrees(angle));
          window->draw(sprites[CLOUD]);  
       }
    }

};