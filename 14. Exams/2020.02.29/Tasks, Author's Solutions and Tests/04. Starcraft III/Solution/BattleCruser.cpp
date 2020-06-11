#include "BattleCruser.h"

#include <iostream>

BattleCruser::BattleCruser(const AirShipType type,
                           const int health,
                           const int damage,
                           const int shipId) :
    TerranAirShip(type, health, damage, shipId) {

}

void BattleCruser::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  std::unique_ptr<AirShip>& enemyAirShip = enemyFleet.back();

  if (YAMATO_CANNON_LOADING_TIME == _passedTurns) {
    enemyAirShip->takeDamage(_damage * 5);

    _passedTurns = -1; //make turn -1, because ::finishTurn() will make it 0
  } else {
    enemyAirShip->takeDamage(_damage);
  }

  if (!enemyAirShip->isAlive()) {
    std::cout << "BattleCruser with ID: " << _shipId
              << " killed enemy airship with ID: "
              << enemyAirShip->getAirShipId() << '\n';

    enemyFleet.pop_back();
  }
}
