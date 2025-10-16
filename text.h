#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <format>
#include "score.h"

class Text
{
 const sf::Font times;
 long long* score;
 sf::Clock* clock;
 sf::RenderWindow* window;
 Score* highScore;

 public:
 Text(long long* score,sf::Clock* clock,sf::RenderWindow* window,Score* highScore):
 times("assets/dodot.ttf"),clock{clock},window{window},score(score),highScore{highScore} {}
 void drawScore()
 {
   std::string scoreText="   Score:"+std::to_string((*score)/10)+" High Score:"+std::to_string(highScore->getHighScore()/10);
   sf::Text text(times,scoreText,40);
   text.setFillColor({0,0,0});
   window->draw(text);
 }

 void drawTime()
 {
    float remaining=61-clock->getElapsedTime().asSeconds();
    int remainingSec=remaining;
    int remainingMilisec=(remaining-remainingSec)*100;
    std::string remainingText= "0:"+std::to_string(remainingSec)+':'+std::to_string(remainingMilisec);
    sf::Text text(times,remainingText,40);
    text.setPosition({700,0});
    window->draw(text);
 }

};