#include "Viking.h"
#include "AirShip.h"
#include "ConsolePrinter.h"

Viking::Viking(const AirShipType type,
               const int health,
               const int baseDamage,
               const int shipId) :
    TerranAirShip(type, health, baseDamage, shipId) { }

void Viking::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  if (enemyFleet.empty()) {
    return;
  }

  auto& enemyAirShip = enemyFleet.back();

  int damage = (enemyAirShip->getAirShipType() == AirShipType::PHOENIX) ?
               _damage * 2 : _damage;

  enemyAirShip->takeDamage(damage);

  if (!enemyAirShip->isAlive()) {
    printKill(*this, enemyAirShip->getAirShipId());
    enemyFleet.pop_back();
  }
}
