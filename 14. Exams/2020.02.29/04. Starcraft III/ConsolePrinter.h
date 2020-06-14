#ifndef CPP_ADVANCED_CONSOLEPRINTER_H
#define CPP_ADVANCED_CONSOLEPRINTER_H

#include <iostream>
#include "AirShip.h"

inline void printKill(const AirShip& airShip, int enemyId) {
  std::string shipName{ };
  switch (airShip.getAirShipType()) {
  case AirShipType::BATTLE_CRUSER:
    shipName = "BattleCruser";
    break;
  case AirShipType::CARRIER:
    shipName = "Carrier";
    break;
  case AirShipType::PHOENIX:
    shipName = "Phoenix";
    break;
  case AirShipType::VIKING:
    shipName = "Viking";
    break;
  }

  std::cout << shipName << " with ID: " << airShip.getAirShipId()
            << " killed enemy airship with ID: " << enemyId << std::endl;
}

#endif //CPP_ADVANCED_CONSOLEPRINTER_H
