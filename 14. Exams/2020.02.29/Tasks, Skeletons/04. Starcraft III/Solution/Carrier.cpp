#include "Carrier.h"

#include <iostream>

Carrier::Carrier(const AirShipType type,
                 const int health,
                 const int damage,
                 const int maxShield,
                 const int shieldRegenerateRate,
                 const int shipId) :
    ProtossAirShip(type,
                   health,
                   damage,
                   maxShield,
                   shieldRegenerateRate,
                   shipId),
    _activeInterceptors(MAX_INTERCEPTORS) {

}

void Carrier::takeDamage(const int damage) {
  ProtossAirShip::takeDamage(damage);

  if (_currHealth != _maxHealth) {
    _activeInterceptors = DAMAGED_STATUS_INTERCEPTORS;
  }
}

void Carrier::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  for (int i = 0; i < _activeInterceptors; ++i) {
    std::unique_ptr<AirShip>& enemyAirShip = enemyFleet.back();

    enemyAirShip->takeDamage(_damage);

    if (!enemyAirShip->isAlive()) {
      std::cout << "Carrier with ID: " << _shipId
                << " killed enemy airship with ID: "
                << enemyAirShip->getAirShipId() << '\n';

      enemyFleet.pop_back();

      //no need to continue -> no enemy airships left
      if (enemyFleet.empty()) {
        break;
      }
    }
  }
}
