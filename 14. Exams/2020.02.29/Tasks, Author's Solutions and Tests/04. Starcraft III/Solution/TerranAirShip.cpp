#include "TerranAirShip.h"

TerranAirShip::TerranAirShip(const AirShipType type,
                             const int health,
                             const int damage,
                             const int shipId) :
    AirShip(type, health, damage, shipId),
    _passedTurns(0) {

}

void TerranAirShip::takeDamage(const int damage) {
  _currHealth -= damage;
}

void TerranAirShip::finishTurn() {
  ++_passedTurns;
}
