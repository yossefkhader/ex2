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
        printBattleResult(true);
    }
    else
    {
      player.damage(this->m_stats.hpLossOnDefeat);
      printBattleResult(false);
    }
  }
  if(this->m_effect == CardType::Treasure)
  {
    player.addCoins(this->m_stats.loot);
  }
}

void Card::printInfo() const
{
  
  switch (this->m_effect)
  {
  case CardType::Heal:
    printHealCardInfo(m_stats);
    break;
  
  case CardType::Buff:
    printBuffCardInfo(m_stats);
    break;

  case CardType::Battle:
    printBattleCardInfo(m_stats);
    break;

  case CardType::Treasure:
    printTreasureCardInfo(m_stats);
    break;
  }
  
  return;
}