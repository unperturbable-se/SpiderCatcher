#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "sprites.h"
#include "scenery.h"
#include "man.h"
#include "spider.h"
#include "text.h"
#include "score.h"
#include <iostream>


sf::Vector2u screenSize{1000,1000};
int getWindowInput()
{
 #define kp sf::Keyboard::isKeyPressed
 #define kk sf::Keyboard::Key
    if(kp(kk::Left)||kp(kk::A))return 1;
    if(kp(kk::Right)||kp(kk::D))return 2;
    if(kp(kk::Up)||kp(kk::W)||kp(kk::Space))return 3;
    return 0;
 #undef kp
 #undef kk
}

void game()
{
   sf::RenderWindow window(sf::VideoMode(screenSize),"Spider Catcher");
   sf::Clock time;
   long long clock=0;
   long long score=0;
   Score highScore(&score);
   Man man(&window,&clock);
   Spider spider(&man,&score,&clock,&window);
   sf::Music music("assets/gameSong.wav");
   Scenery scenery(&window,&clock);
   Text text(&score,&time,&window,&highScore);
   music.play();
   time.start();
  while(window.isOpen())
   {
    music.play();
    while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())window.close();
            man.poll(getWindowInput());
        }
    window.clear(sf::Color(105, 191, 227));
    scenery.makeGrass();
    scenery.addWater();
    scenery.addSun();
    scenery.addClouds();
    man.draw();
    spider.move();
    spider.draw();
    text.drawScore();
    text.drawTime();
    window.display();
    clock++;
    music.pause();
    if(time.getElapsedTime().asSeconds()>=60){window.close();time.reset();}
   }
}

bool gameOver()
{
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "Spider Catcher");
    const sf::Font times("assets/dodot.ttf");
    sf::Text text(times,"GAME OVER!",100);
    text.setFillColor({123,34,51});
    text.setPosition({200,100});
    sf::Music introMusic("assets/intro-song.wav");
    while (window.isOpen())
    {
       introMusic.play();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) window.close();
            sprites[RESTART].setTexture(textures[RESTART]);
            sprites[QUIT].setTexture(textures[QUIT]);
            float mousex=sf::Mouse::getPosition(window).x;
            float mousey=sf::Mouse::getPosition(window).y;
            if(mousey>=350&&mousey<=650)
            {
                if(mousex>=200&&mousex<=500&&sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                  {
                    window.close();
                    return 0;
                  }
                else if(mousex>=550&&mousex<=850&&sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                  {
                    window.close();
                    return 1;
                  }
                if(mousex>=200&&mousex<=500)sprites[RESTART].setTexture(textures[RESTART_H]);
                else if(mousex>=550&&mousex<=850)sprites[QUIT].setTexture(textures[QUIT_H]);
                sprites[RESTART].setScale({20,20});
                sprites[QUIT].setScale({20,20});
            }
        }

        window.clear({150,75,0});
        sprites[RESTART].setPosition({200,350}); //X(200-500) Y(350-650)
        sprites[QUIT].setPosition({550,350}); //X(550-850) Y(350-650)
        window.draw(sprites[RESTART]);
        window.draw(sprites[QUIT]);
        window.draw(text);
        window.display();
        introMusic.pause();
    }
    return 1;
}

bool startScreen()
{
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "Spider Catcher");
    const sf::Font times("assets/dodot.ttf");
    sf::Text text(times,"SPIDER CATCHER",100);
    text.setFillColor({123,34,51});
    text.setOrigin(text.getLocalBounds().getCenter());
    text.setPosition({490,190});
    //text.setOrigin({900,110});
    long long clock=0;
    Scenery scene(&window,&clock);
    sf::Music introMusic("assets/intro-song.wav");
    while (window.isOpen())
    {
        introMusic.play();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) window.close();
            sprites[PLAY].setTexture(textures[PLAY]);
            sprites[QUIT].setTexture(textures[QUIT]);
            float mousex=sf::Mouse::getPosition(window).x;
            float mousey=sf::Mouse::getPosition(window).y;
            if(mousey>=350&&mousey<=650)
            {
                if(mousex>=200&&mousex<=500&&sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                  {
                    window.close();
                    return 1;
                  }
                else if(mousex>=550&&mousex<=850&&sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                  {
                    window.close();
                    return 0;
                  }
                if(mousex>=200&&mousex<=500)sprites[PLAY].setTexture(textures[PLAY_H]);
                else if(mousex>=550&&mousex<=850)sprites[QUIT].setTexture(textures[QUIT_H]);
                sprites[RESTART].setScale({20,20});
                sprites[QUIT].setScale({20,20});
            }
        }

        window.clear({132,211,255});
        sprites[PLAY].setPosition({200,350}); //X(200-500) Y(350-650)
        sprites[QUIT].setPosition({550,350}); //X(550-850) Y(350-650)
        window.draw(sprites[PLAY]);
        window.draw(sprites[QUIT]);
        text.setRotation(sf::degrees(2.5*sin(clock/400))); //-10 to 10 degrees
        window.draw(text);
        window.display();
        clock++;
        introMusic.pause();
    }
    return 0;
}

int main()
{
   loadTexturesAndSprites();
   setScales();
   while(startScreen())
   {
     game();
     if(gameOver())break;
   }
   //game();
   return 0;
}




/*
PENDING:
POLISHING STUFF UP
ADDING NEW FEATURES
*/