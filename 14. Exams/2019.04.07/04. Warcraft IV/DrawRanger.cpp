#include <iostream>
#include "DrawRanger.h"

DrawRanger::DrawRanger(const std::string& name,
                       const int maxMana,
                       const int baseManaRegenRate)
    : Hero(name, maxMana, baseManaRegenRate) { }

void DrawRanger::regenerateMana() {
  this->_currMana += this->_manaRegenRate;
  if (this->_currMana > this->_maxMana) {
    this->_currMana = this->_maxMana;
  }
}

void DrawRanger::castSpell(const enum SpellType spell) {
  Spell toCast = this->_spells[spell];

  if (toCast.manaCost <= this->_currMana) {
    this->_currMana -= toCast.manaCost;
    std::cout << this->_name << " casted " << toCast.name << " for " << toCast.manaCost << " mana" << std::endl;
    if (spell == SpellType::BASIC) {
      std::cout << this->_name << " casted " << toCast.name << " for " << 0 << " mana" << std::endl;
    }
  } else {
    std::cout << this->_name << " - not enough mana to cast " << toCast.name << std::endl;
  }
}
