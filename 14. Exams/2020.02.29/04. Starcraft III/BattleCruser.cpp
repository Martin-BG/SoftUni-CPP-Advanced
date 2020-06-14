#include "BattleCruser.h"
#include "ConsolePrinter.h"

BattleCruser::BattleCruser(const AirShipType type,
                           const int health,
                           const int damage,
                           const int shipId) :
    TerranAirShip(type, health, damage, shipId) { }

void BattleCruser::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  if (enemyFleet.empty()) {
    return;
  }

  auto& enemyAirShip = enemyFleet.back();

  int damage = (_passedTurns % 5 == YAMATO_CANNON_LOADING_TIME) ?
               _damage * 5 : _damage;

  enemyAirShip->takeDamage(damage);

  if (!enemyAirShip->isAlive()) {
    printKill(*this, enemyAirShip->getAirShipId());
    enemyFleet.pop_back();
  }
}
