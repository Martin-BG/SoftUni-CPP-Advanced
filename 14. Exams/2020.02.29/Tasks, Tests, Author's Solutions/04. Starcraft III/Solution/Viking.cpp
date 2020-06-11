#include "Viking.h"

#include <iostream>

Viking::Viking(const AirShipType type,
               const int health,
               const int baseDamage,
               const int shipId) :
    TerranAirShip(type, health, baseDamage, shipId) {

}

void Viking::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  std::unique_ptr<AirShip>& enemyAirShip = enemyFleet.back();

  if (AirShipType::PHOENIX == enemyAirShip->getAirShipType()) {
    enemyAirShip->takeDamage(_damage * 2);
  } else {
    enemyAirShip->takeDamage(_damage);
  }

  if (!enemyAirShip->isAlive()) {
    std::cout << "Viking with ID: " << _shipId
              << " killed enemy airship with ID: "
              << enemyAirShip->getAirShipId() << '\n';

    enemyFleet.pop_back();
  }
}
