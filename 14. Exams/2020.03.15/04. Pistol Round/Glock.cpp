#include "Glock.h"

Glock::Glock(const int damagePerRound,
             const int clipSize,
             const int remainingAmmo) :
    Pistol(damagePerRound, clipSize, remainingAmmo) { }

bool Glock::fire(PlayerVitalData& enemyPlayerData) {

  for (int i = 0; i < ROUNDS_PER_FIRE; ++i) {
    if (_currClipBullets <= 0) {
      reload();
      break;
    }

    --_currClipBullets;

    enemyPlayerData.health -= (enemyPlayerData.armor > 0) ?
                              int(_damagePerRound * 0.5) : _damagePerRound;

    enemyPlayerData.armor -= (enemyPlayerData.armor > 0) ?
                             int(_damagePerRound * 0.5) : 0;

    if (enemyPlayerData.armor < 0) {
      enemyPlayerData.health -= -enemyPlayerData.armor;
      enemyPlayerData.armor = 0;
    }

    std::cout << "Enemy left with: "
              << enemyPlayerData.health << " health and "
              << enemyPlayerData.armor << " armor" << std::endl;

    if (enemyPlayerData.health <= 0) {
      return true;
    }
  }

  return false;
}
