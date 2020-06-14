#include "Carrier.h"
#include "ConsolePrinter.h"

Carrier::Carrier(const AirShipType type,
                 const int health,
                 const int damage,
                 const int maxShield,
                 const int shieldRegenerateRate,
                 const int shipId) :
    ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId),
    _activeInterceptors(MAX_INTERCEPTORS) { }

void Carrier::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  for (int i = 0; i < _activeInterceptors && !enemyFleet.empty(); ++i) {
    auto& enemyAirShip = enemyFleet.back();
    enemyAirShip->takeDamage(_damage);

    if (!enemyAirShip->isAlive()) {
      printKill(*this, enemyAirShip->getAirShipId());
      enemyFleet.pop_back();
    }
  }
}

void Carrier::takeDamage(const int damage) {
  ProtossAirShip::takeDamage(damage);

  if (_currHealth < _maxHealth) {
    _activeInterceptors = DAMAGED_STATUS_INTERCEPTORS;
  }
}
