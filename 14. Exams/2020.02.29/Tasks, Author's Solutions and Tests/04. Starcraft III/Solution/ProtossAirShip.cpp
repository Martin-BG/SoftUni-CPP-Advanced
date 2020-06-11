#include "ProtossAirShip.h"

ProtossAirShip::ProtossAirShip(const AirShipType type,
                               const int health,
                               const int damage,
                               const int maxShield,
                               const int shieldRegenerateRate,
                               const int shipId) :
    AirShip(type, health, damage, shipId),
    _maxShield(maxShield),
    _currShield(maxShield),
    _shieldRegenerateRate(shieldRegenerateRate) {

}

void ProtossAirShip::takeDamage(const int damage) {
  _currShield -= damage;

  if (0 > _currShield) {
    _currHealth += _currShield;
    _currShield = 0;
  }
}

void ProtossAirShip::finishTurn() {
  _currShield += _shieldRegenerateRate;

  if (_currShield > _maxShield) {
    _currShield = _maxShield;
  }
}
