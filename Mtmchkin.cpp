#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
{
    Player tmp(playerName);
    this->m_player = tmp;    
    this->m_cardsArray = new Card[numOfCards];
    this->m_size = numOfCards;
    for (int i = 0; i < m_size; i++)
    {
        this->m_cardsArray[i] = cardsArray[i];
    }
    this->m_gameStatus = GameStatus::MidGame;

}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cardsArray;
}

void Mtmchkin::playNextCard()
{
    this->m_cardsArray[this->m_currCard].printInfo();
    this->m_cardsArray[this->m_currCard].applyEncounter(this->m_player);
    this->m_player.printInfo();
    this->m_currCard++;
    if(this->m_currCard == this->m_size){
        this->m_currCard = 0;
    }

    if(isOver())
    {
        if(this->m_player.isKnockedOut())
        {
            this->m_gameStatus = GameStatus::Loss;
        }
        else if(this->m_player.getLevel() == MAX_LEVEL)
        {
            this->m_gameStatus = GameStatus::Win;
        }
    }
    
    return;
}

bool Mtmchkin::isOver() const
{
    if(this->m_player.isKnockedOut())
    {
        return true;
    }
    else if(this->m_player.getLevel() == MAX_LEVEL)
    {
        return true;
    }

    return false;
}

GameStatus Mtmchkin::getGameStatus() const
{    
    return this->m_gameStatus;
}
