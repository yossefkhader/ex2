#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
{
    Player tmp(playerName);
    this->player = tmp;    
    this->cardsArray = new Card[numOfCards];
    this->size = numOfCards;
    for (int i = 0; i < size; i++)
    {
        this->cardsArray[i] = cardsArray[i];
    }

}

void Mtmchkin::playNextCard()
{
    this->cardsArray[this->currCard].printInfo();
    this->cardsArray[this->currCard].applyEncounter(this->player);
    this->player.printInfo();
    this->currCard++;
    if(this->currCard == this->size){
        this->currCard = 0;
    }
    return;
}

bool Mtmchkin::isOver() const
{
    if(this->player.isKnockedOut())
    {
        return true;
    }
    else if(this->player.getLevel() == MAX_LEVEL)
    {
        return true;
    }

    return false;
}

GameStatus Mtmchkin::getGameStatus() const
{
    if(!isOver())
    {
        if(this->player.isKnockedOut())
        {
        return GameStatus::Loss;
        }
    else if(this->player.getLevel() == MAX_LEVEL)
        {
        return GameStatus::Win;
        }
    }
    return GameStatus::MidGame;
}

