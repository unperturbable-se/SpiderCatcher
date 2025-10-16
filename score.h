#include <fstream>
#include <filesystem>

#pragma once

class Score
{
    long long* currentScore;
    long long highScore;
    public:
    Score(long long* currentScore):currentScore{currentScore}
    {
      std::ifstream in("assets/score.txt");
      if(!in)highScore=0;
      else in>>highScore;
    }
    long long getHighScore()
    {
        highScore=((*currentScore<highScore)? highScore:*currentScore);
        return highScore;
    }
    ~Score()
    {
      std::ofstream out("assets/score.txt",std::ios::ate);
      out<<highScore;
    }
};