/*
 * GameSettings.h
 *
 *  Created on: May 25, 2017
 *      Author: msaun
 */

#ifndef GAMESETTINGS_H_
#define GAMESETTINGS_H_

#include <string>
#include "RuntimeException.h"
#include <vector>
#include "Map.h"

namespace std
{

class GameSettings
{
  public:
    GameSettings();
    static GameSettings* getInstance();
    enum GAME_STATE { GAME_INIT, MENU_RUNNING, GAME_RUNNING, GAME_OVER };

    inline int getNumberOfHumanPlayers()
    {
      int human = 0;
      for(int i = 0; i < numPlayers; i++)
      {
        if(! playerAIs.at(i))
        {
          ++human;
        }
      }
      return human;
    }

    inline int getNumberOfPlayers()
    {
      return numPlayers;
    }
    inline int getBlockSpawnPercentage()
    {
      return blockPercentage;
    }
    inline std::vector<bool>* getPlayerGenders()
    {
      return &genders;
    }
    inline bool getPlayerGender(int playerIndex)
    {
      return genders.at(playerIndex);
    }
    inline std::vector<bool>* getPlayerAIs()
    {
      return &playerAIs;
    }
    inline int getMapWidth()
    {
      return mapWidth;
    }
    inline int getMapHeight()
    {
      return mapHeight;
    }

    inline void setNumberOfPlayers(int allPlayers)
    {
      if(MAX_PLAYERS >= allPlayers && allPlayers > 0)
      {
        numPlayers = allPlayers;
        genders.resize(allPlayers+1);
        playerAIs.resize(allPlayers, true);
      }
    }
    inline void setBlockSpawnPercentage(int blockSpawnPercentage)
    {
      this->blockPercentage = blockSpawnPercentage;
    }
    inline void setPlayerGender(int playerIndex, bool isMale)
    {
      genders.at(playerIndex) = isMale;
    }
    inline void setPlayerAI(int playerIndex, bool isAI)
    {
      playerAIs.at(playerIndex) = isAI;
    }

    inline GAME_STATE getGameState()
    {
      return gameState;
    }
    inline void setGameState(GAME_STATE state)
    {
      this->gameState = state;
    }

    static const int MAX_PLAYERS = 4; // TODO 6;
    static const int MIN_PLAYERS = 1; // a player vs the default purple non player PC.

    static const int MAX_BLOCK_PCT = 75;
    static const int MIN_BLOCK_PCT = 20;

  private:
    ~GameSettings();
    GAME_STATE gameState;

    int numPlayers = 4;
    int blockPercentage = 55;
    std::vector<bool> genders;
    std::vector<bool> playerAIs;

    int mapWidth = Map::MAP_WIDTH;   // not changeable outside of runtime flags for now
    int mapHeight = Map::MAP_HEIGHT; // not changeable outside of runtime flags for now

    float mapRatio = 1.3077;

};

} /* namespace std */
#endif /* GAMESETTINGS_H_ */
