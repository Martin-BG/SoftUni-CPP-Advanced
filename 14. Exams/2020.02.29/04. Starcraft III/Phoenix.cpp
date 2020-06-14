#include "Phoenix.h"
#include "ConsolePrinter.h"

Phoenix::Phoenix(const AirShipType type,
                 const int health,
                 const int damage,
                 const int maxShield,
                 const int shieldRegenerateRate,
                 const int shipId) :
    ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId) { }

void Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  if (enemyFleet.empty()) {
    return;
  }

  auto& enemyAirShip = enemyFleet.back();
  enemyAirShip->takeDamage(_damage);

  if (!enemyAirShip->isAlive()) {
    printKill(*this, enemyAirShip->getAirShipId());
    enemyFleet.pop_back();
  }
}
