//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
 */
enum class GameStatus
{
    Win,
    Loss,
    MidGame
};

class Mtmchkin
{
public:
    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
     */
    Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards);
    ~Mtmchkin();

    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
     */
    void playNextCard();

    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;

    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;


private:
    GameStatus m_gameStatus;    //saves the current game status
    Player m_player;            //the playe that take part in the game
    Card *m_cardsArray;         //the cards we use in the game
    int m_size;                 //the size of the array
    int m_currCard = 0;         //the index of the current card
};

#endif // EX2_GAME_H
