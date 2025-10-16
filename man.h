#pragma once
#include <SFML/Graphics.hpp>
#include "sprites.h"

class Spider;
class Man
{
    friend class Spider;
    float posy = 660.0;
    float posx = 0;
    long long clock1 = 0;
    bool jumped = false;
    sf::RenderWindow* window;
    long long* clock;

public:
    Man(sf::RenderWindow* window,long long* clock):window{window},clock{clock}{};
    void poll(int key)
    {
        if (key == 1) posx -= 20;
        else if (key == 2) posx += 20;
        else if (key == 3 && !jumped)
        {
            jumped = true;
            clock1 = *clock; 
        }

        if (posx <= -60) posx = -60;
        else if (posx >= 830) posx = 830;
    }

    void draw()
    {
        if (jumped) jump();
        sprites[WITCH].setPosition({ posx, posy });
        window->draw(sprites[WITCH]);
    }

    void jump()
    {
        float t = float(*clock - clock1)/100;
        float u=-50;
        float a=9.81;
        float displacement=(u*t)+(0.5*a)*(t*t);  //ut+0.5at^2
        posy=660+displacement;
        if(posy>660)
        {
            posy = 660;
            jumped = false;
        }
    }
};
