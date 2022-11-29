#include "card.h"
const int maxhp
Card::Card(CardType::CardType effect ,CardStats stats);
{
    this->m_effect = effect;
    this->m_force = stats.force;
    this->m_hpLossOnDefeat = stats.hpLoss;
    this->m_cost = stats.cost;
    this->m_heal = stats.heal;
    this->m_buff = stats.buff;
    this->m_loot = stats.loot;
}    
void Card::applyEncounter(player)
{
  if(this->m_effect == Heal)
  {
     if (!player.pay(this->m_cost))
     {
        printBattleResult(false);
     }
    player.heal(this->heal);
  } 
  if(this->m_effect == Buff)
  {
    if (!player.pay(this->m_cost))
    {
        printBattleResult(false);
    }
    player.buff(this->m_buff)
  } 
  if(this->m_effect == Battle)
  {
    if(player.getAttackStrength() >= this->m_force)
    {
        player.addCoins(this->m_loot);
        if(player.getLevel()<=9)
        {
        player.levelUp();
        }
        player.buff(1);
    }
    else
    {
      player.damage(this->m_force);
    }
  }
  if(this->m_effect == Treasure)
  {
    player.addCoins(this->m_loot);
  }
}
void Card::printInfo()
{
    
}