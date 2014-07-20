/** Class that governs the majority of the UI
  *
  * @author Richard Szeto
  *
  *
  *
  */

#include <iostream>
#include <string>
#include "Game.h"
#include "ActionQueue.h"
#include "Action.h"

namespace CheckersSzeto
{
    Game::Game()
    {

    }

    Game::~Game()
    {

    }

    void Game::startGame()
    {
        showMainMenu();
    }

    void Game::showMainMenu()
    {
        using std::cout;
        using std::endl;
        using std::cin;

        int selection;

        bool invalidSelection;

        while(true)
        {
            selection = 0;

            invalidSelection = true;

            cout << "-------------------------------------------\n";

            cout << "|             1. Play Checkers            |\n";

            cout << "|             2. Change Settings          |\n";

            cout << "|             3. Exit Checkers            |\n";

            cout << "-------------------------------------------\n";

            cout << endl;

            while(invalidSelection)
            {
                cout << "Enter a number from 1 - 3: ";

                cin >> selection;

                invalidSelection = false;

                switch(selection)
                {
                    case 1:
                        invalidSelection = false;
                        playCheckers();
                        break;

                    case 2:
                        invalidSelection = false;
                        changeSettings();
                        break;

                    case 3:
                        invalidSelection = false;
                        return;
                        break;

                    default:
                        invalidSelection = true;
                        cout << "Invalid selection\n";
                        selection = 0;
                        break;
                }
            }
        }
    }

    void Game::playCheckers()
    {
        using std::cout;
        using std::endl;
        using std::cin;

        int selection;

        bool invalidSelection;

        while(true)
        {
            selection = 0;

            invalidSelection = true;

            cout << "-------------------------------------------\n";

            cout << "|             1. 1 Player                 |\n";

            cout << "|             2. 2 Players                |\n";

            cout << "|             3. Main Menu                |\n";

            cout << "-------------------------------------------\n";

            cout << endl;

            while(invalidSelection)
            {
                cout << "Enter a number from 1 - 3: ";

                cin >> selection;

                invalidSelection = false;

                switch(selection)
                {
                    case 1:
                        invalidSelection = false;
                        onePlayerGame();
                        break;

                    case 2:
                        invalidSelection = false;
                        twoPlayerGame();
                        break;

                    case 3:
                        invalidSelection = false;
                        return;
                        break;

                    default:
                        invalidSelection = true;
                        cout << "Invalid selection\n";
                        selection = 0;
                        break;
                }
            }
        }
    }

    void Game::showBeginningGame()
    {
        using std::cout;
        using std::endl;

        checkerBoard.printBoard();
        checkerBoard.printTurn();

        cout << endl;

        cout << "To exit, type -1\n";
        cout << "To reset the game, type -2\n";
    }

    void Game::onePlayerGame()
    {
        using std::cout;
        using std::endl;
        using std::cin;
        using std::string;

        const int maxDepth = 11;

        bool isPreGame = true;

        bool isFirstTurn = true;

        bool humanIsWhite = false;

        bool validMove = false;

        string color = "";

        int startX, startY, endX, endY;

        startX = 0;

        startY = 0;

        endX = 0;

        endY = 0;

        while(true)
        {
            if(isPreGame)
            {
                cout << "Do you want to play as white or black? (white/black): ";

                cin >> color;

                if(color == "white" || color == "White" ||
                    color == "WHITE")
                {
                    humanIsWhite = true;
                }

                showBeginningGame();

                isPreGame = false;
            }

            checkerBoard.scanCapture();

            checkerBoard.scanMove();

            if(checkerBoard.isEndGame())
            {
                string response = "";

                cout <<"Would you like to play again? (yes/no): ";

                cin >> response;

                if(response == "yes" || response == "YES" ||
                    response == "y" || response == "Y")
                {
                    checkerBoard.clear();

                    showBeginningGame();

                    isPreGame = true;

                    isFirstTurn = true;

                    humanIsWhite = false;

                    continue;
                }
                else
                {
                    break;
                }
            }

            if(!(humanIsWhite && isFirstTurn))
            {
                ActionQueue actionQueue;

                actionQueue = gameTree.alphaBetaSearch(checkerBoard, maxDepth);

                while(!actionQueue.isEmpty())
                {
                    Action action = actionQueue.removeFront();

                    checkerBoard.scanCapture();

                    checkerBoard.scanMove();

                    checkerBoard.move(action.getStartX(),
                        action.getStartY(),
                        action.getEndX(),
                        action.getEndY());

                    checkerBoard.printBoard();
                    checkerBoard.printTurn();

                    cout << endl;
                }
            }

            checkerBoard.scanCapture();

            checkerBoard.scanMove();

            if(checkerBoard.isEndGame())
            {
                string response = "";

                cout <<"Would you like to play again? (yes/no): ";

                cin >> response;

                if(response == "yes" || response == "YES" ||
                    response == "y" || response == "Y")
                {
                    checkerBoard.clear();

                    showBeginningGame();

                    isPreGame = true;

                    isFirstTurn = true;

                    humanIsWhite = false;

                    continue;
                }
                else
                {
                    break;
                }
            }

            validMove = false;

            isFirstTurn = false;

            while(!validMove || checkerBoard.getIsMultiJump())
            {

                cout << "Enter startX startY endX endY: ";
                
                cin >> startX;
                
                if(startX == -1)
                {
                    return;
                }
                else if(startX == -2)
                {
                    checkerBoard.clear();

                    showBeginningGame();

                    isPreGame = true;

                    isFirstTurn = true;

                    humanIsWhite = false;

                    validMove = false;

                    break;
                }
                
                cin >> startY;
                
                if(startY == -1)
                {
                    return;
                }
                else if(startY == -2)
                {
                    checkerBoard.clear();
                    
                    showBeginningGame();

                    isPreGame = true;

                    isFirstTurn = true;

                    humanIsWhite = false;

                    validMove = false;

                    break;
                }
                
                cin >> endX;
                
                if(endX == -1)
                {
                    return;
                }
                else if(endX == -2)
                {
                    checkerBoard.clear();
                    
                    showBeginningGame();

                    isPreGame = true;

                    isFirstTurn = true;

                    humanIsWhite = false;

                    validMove = false;

                    break;
                }
                
                cin >> endY;
                
                if(endY == -1)
                {
                    return;
                }
                else if(endY == -2)
                {
                    checkerBoard.clear();
                    
                    showBeginningGame();

                    isPreGame = true;

                    isFirstTurn = true;

                    humanIsWhite = false;

                    validMove = false;

                    break;
                }
                
                validMove = checkerBoard.move(startX, startY, endX, endY);
                checkerBoard.printBoard();
                checkerBoard.printTurn();

                cout << endl;
            }
        }
    }

    void Game::twoPlayerGame()
    {
        using std::cout;
        using std::endl;
        using std::cin;

        showBeginningGame();

        int startX, startY, endX, endY;
        
        startX = 0;
        startY = 0;
        endX = 0;
        endY = 0;
        
        while(true)
        {
            checkerBoard.scanCapture();

            checkerBoard.scanMove();

            if(checkerBoard.isEndGame())
            {
                using std::string;

                string response = "";

                cout <<"Would you like to play again? (yes/no): ";

                cin >> response;

                if(response == "yes" || response == "YES" ||
                    response == "y" || response == "Y")
                {
                    checkerBoard.clear();

                    showBeginningGame();

                    continue;
                }
                else
                {
                    break;
                }
            }

            cout << "Enter startX startY endX endY: ";
            
            cin >> startX;
            
            if(startX == -1)
            {
                break;
            }
            else if(startX == -2)
            {
                checkerBoard.clear();

                showBeginningGame();

                continue;
            }
            
            cin >> startY;
            
            if(startY == -1)
            {
                break;
            }
            else if(startY == -2)
            {
                checkerBoard.clear();
                
                showBeginningGame();

                continue;
            }
            
            cin >> endX;
            
            if(endX == -1)
            {
                break;
            }
            else if(endX == -2)
            {
                checkerBoard.clear();
                
                showBeginningGame();

                continue;
            }
            
            cin >> endY;
            
            if(endY == -1)
            {
                break;
            }
            else if(endY == -2)
            {
                checkerBoard.clear();
                
                showBeginningGame();

                continue;
            }
            
            checkerBoard.move(startX, startY, endX, endY);
            checkerBoard.printBoard();
            checkerBoard.printTurn();

            cout << endl;
        }
    }

    void Game::changeSettings()
    {
        // placeholder
    }
}