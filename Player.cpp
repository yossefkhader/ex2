#include "Player.h"

Player::Player(const char* name, int force=DEF_FORCE, 
               int hp=DEF_MAXHP)
{
    this->m_playerName = name;
 
    if(force < 0)
    {
        force=DEF_FORCE;
    }
    this->m_force = force; 
    
    if(hp < 0)
    {
        hp=DEF_MAXHP;
    }
    this->m_MAXHP = hp;
    this->m_hp = this->m_MAXHP;
}

Player& Player::operator=(const Player& p)
{
    if(this == &p)
    {
        return *this;
    }

    m_level = p.m_level;
    m_force = p.m_force;
    m_MAXHP = p.m_MAXHP;
    m_hp = p.m_hp;

    return *this;
}

void Player::levelUp()
{
    if(this->m_level == MAX_LEVEL){
        return;
    }
    this->m_level++;
}

int Player::getLevel() const
{
    return this->m_level;
}

void Player::buff(int num)
{
    if(num<0)
    {
        num=0;
    }
    this->m_force += num;
}

void Player::heal(int num)
{
    if(num<0)
    {
        num=0;
    }
    else if(this->m_hp == this->m_MAXHP)
    {
        return;
    }
    this->m_hp += num;
    if(this->m_hp > this->m_MAXHP)
    {
        this->m_hp = this->m_MAXHP;
    }
    return;
}

void Player::damgae(int num)
{
    if(num<0)
    {
        num=0;
    }
    this->m_hp -= num;
    if(this->m_hp <0)
    {
        this->m_hp = 0;
    }
    return;
}

bool Player::isKnockedOut() const
{
    if(this->m_hp ==0)
    {
        return false;
    }
    return true;
}

void Player::addCoins(int num)
{
    if(num<0)
    {
        num=0;
    }
    this->m_coins += num;
    return;
}

bool Player::pay(int num)
{
    if(num<0)
    {
        num=0;
    }
    else if(this->m_coins - num < 0)
    {
        return false;
    }   

    this->m_coins -= num;
    return true;
}

int Player::getAttackStregth() const
{
    return this->m_force + this->m_level;
}