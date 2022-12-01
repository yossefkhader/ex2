#include "Player.h"

Player::Player(const char* name)
{
    std::string str(name);
    this->m_playerName = str;
    this->m_force = DEF_FORCE; 
    this->m_MAXHP = DEF_MAXHP;
    this->m_hp = this->m_MAXHP;
}

Player::Player(const char* name, int hp)
{
    std::string str(name);
    this->m_playerName = str;
 
    if(hp < 0)
    {
        hp=DEF_MAXHP;
    }
    this->m_MAXHP = hp;
    this->m_hp = this->m_MAXHP;

    this->m_force = DEF_FORCE; 
}


Player::Player(const char* name, int hp, int force)
{
    std::string str(name);
    this->m_playerName = str;
 
    if(hp < 0)
    {
        hp=DEF_MAXHP;
    }
    this->m_MAXHP = hp;
    this->m_hp = this->m_MAXHP;

    if(force < 0)
    {
        force=DEF_FORCE;
    }
    this->m_force = force; 
    

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

void Player::damage(int num)
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
        return true;
    }
    return false;
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

int Player::getAttackStrength() const
{
    return this->m_force + this->m_level;
}

void Player::printInfo()
{
    printPlayerInfo(this->m_playerName.c_str(), this->m_level, this->m_force, this->m_hp, this->m_coins);
    return;
}
