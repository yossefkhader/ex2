#include "Card.h"

Card::Card(CardType type, const CardStats& stats)
{
    this->m_effect = type;
    this->m_stats = stats;
}    

void Card::applyEncounter(Player& player) const
{
  if(this->m_effect == CardType::Heal)
  {
     if (!player.pay(this->m_stats.cost))
     {
        return;    
     }
    player.heal(this->m_stats.heal);
    return;
  } 
  if(this->m_effect == CardType::Buff)
  {
    if (!player.pay(this->m_stats.cost))
    {
        return;
    }
    player.buff(this->m_stats.buff);
    return;
  } 
  if(this->m_effect == CardType::Battle)
  {
    if(player.getAttackStrength() >= this->m_stats.force)
    {
        player.addCoins(this->m_stats.loot);
        player.levelUp();
        player.buff(m_stats.buff);
    }
    else
    {
      player.damage(this->m_stats.force);
    }
  }
  if(this->m_effect == CardType::Treasure)
  {
    player.addCoins(this->m_stats.loot);
  }
}
void Card::printInfo() const
{
    
}