#include "Phoenix.h"

#include <iostream>

Phoenix::Phoenix(const AirShipType type,
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
                   shipId) {

}

void Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  std::unique_ptr<AirShip>& enemyAirShip = enemyFleet.back();

  enemyAirShip->takeDamage(_damage);

  if (!enemyAirShip->isAlive()) {
    std::cout << "Phoenix with ID: " << _shipId
              << " killed enemy airship with ID: "
              << enemyAirShip->getAirShipId() << '\n';

    enemyFleet.pop_back();
  }
}

