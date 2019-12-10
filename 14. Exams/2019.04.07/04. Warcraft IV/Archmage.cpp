#include <iostream>
#include "Archmage.h"

Archmage::Archmage(const std::string& name,
                   const int maxMana,
                   const int baseManaRegenRate,
                   const int manaRegenModifier)
    : Hero(name, maxMana, baseManaRegenRate),
      _manaRegenModifier(manaRegenModifier) { }

void Archmage::regenerateMana() {
  this->_currMana += this->_manaRegenRate * this->_manaRegenModifier;
  if (this->_currMana > this->_maxMana) {
    this->_currMana = this->_maxMana;
  }
}

void Archmage::castSpell(const enum SpellType spell) {
  Spell toCast = this->_spells[spell];

  if (toCast.manaCost <= this->_currMana) {
    this->_currMana -= toCast.manaCost;
    if (spell == SpellType::ULTIMATE) {
      this->regenerateMana();
    }
    std::cout << this->_name << " casted " << toCast.name << " for " << toCast.manaCost << " mana" << std::endl;
  } else {
    std::cout << this->_name << " - not enough mana to cast " << toCast.name << std::endl;
  }
}
