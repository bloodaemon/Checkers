/** Class that governs the majority of the UI
  *
  * @author Richard Szeto
  *
  *
  *
  */

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "GameTree.h"

namespace CheckersSzeto
{
    class Game
    {
    public:
        Game();
        virtual ~Game();
        void startGame();

    protected:
        void gobbleAll();
        void setNextDigit(int &number, int digit);
        int getNextNumber();
        void showMainMenu();
        void playCheckers();
        void showBeginningGame();
        void onePlayerGame();
        void twoPlayerGame();
        void changeSettings();

        Board checkerBoard;
        GameTree gameTree;
    };
}

#endif