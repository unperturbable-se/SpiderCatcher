#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
//(width,height)=(1000,1000)
std::vector<sf::Texture> textures;
std::vector<sf::Sprite> sprites;
std::vector<sf::Vector2f>scales;
#define onePercent 10/12

enum SPRITES
{
    GRASS,WATER,MAN,INSECT,WITCH,SPIDER,SUN,CLOUD,PLAY,QUIT,RESTART,PLAY_H,QUIT_H,RESTART_H
};

void loadTexturesAndSprites()
{
  textures.push_back(sf::Texture("assets/grass.png"));
  textures.push_back(sf::Texture("assets/water.png"));
  textures.push_back(sf::Texture("assets/man.png"));
  textures.push_back(sf::Texture("assets/insect.png"));
  textures.push_back(sf::Texture("assets/witch.png"));
  textures.push_back(sf::Texture("assets/spider.png"));
  textures.push_back(sf::Texture("assets/sun3.png"));
  textures.push_back(sf::Texture("assets/cloud.png"));

  textures.push_back(sf::Texture("assets/play_button.png"));
  textures.push_back(sf::Texture("assets/quit_button.png"));
  textures.push_back(sf::Texture("assets/restart_button.png"));
  textures.push_back(sf::Texture("assets/play_button_hover.png"));
  textures.push_back(sf::Texture("assets/quit_button_hover.png"));
  textures.push_back(sf::Texture("assets/restart_button_hover.png"));

  for(int i=0;i<14;i++) sprites.push_back(sf::Sprite(textures[i]));
}

void setScales()
{
    scales.push_back({10*onePercent,20*onePercent}); //grass 
    scales.push_back({5*onePercent,5*onePercent}); //water 
    scales.push_back({10*onePercent,10*onePercent}); //man
    scales.push_back({5*onePercent,5*onePercent}); //insect 
    scales.push_back({10*onePercent,5*onePercent}); //witch 
    scales.push_back({5*onePercent,5*onePercent}); //spider 
    scales.push_back({10*onePercent,20*onePercent}); //sun
    scales.push_back({10*onePercent,15*onePercent}); //cloud

    scales.push_back({20,20}); //buttons
    scales.push_back({20,20}); //buttons
    scales.push_back({20,20}); //buttons
    scales.push_back({20,20}); //buttons
    scales.push_back({20,20}); //buttons
    scales.push_back({20,20}); //buttons
    
    for(int i=0;i<14;i++)sprites[i].setScale(scales[i]);
}