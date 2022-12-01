#ifndef __PLAYER__H__
#define __PLAYER__H__

#include <string>
#include "utilities.h"

const int MAX_LEVEL = 10;
const int DEF_MAXHP = 100;
const int DEF_FORCE = 5;

class Player
{
private:
    std::string m_playerName;
    int m_level = 1;     
    int m_force; 
    int m_hp;
    int m_MAXHP;
    int m_coins = 0;
public:
    Player() = default;
    Player(const char* name);
    Player(const char* name, int hp);
    Player(const char* name, int hp,int force);
    ~Player() = default;
    Player(Player const&) = default;
    Player& operator=(Player const&) = default;
    void levelUp();
    int getLevel() const; 
    void buff(int num);
    void heal(int num);
    void damage(int num);
    bool isKnockedOut() const;
    void addCoins(int num);
    bool pay(int num);
    int getAttackStrength() const;
    void printInfo();

};


#endif