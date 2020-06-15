#include "DesertEagle.h"

DesertEagle::DesertEagle(const int damagePerRound,
                         const int clipSize,
                         const int remainingAmmo) :
    Pistol(damagePerRound, clipSize, remainingAmmo) { }

bool DesertEagle::fire(PlayerVitalData& enemyPlayerData) {
  if (_currClipBullets <= 0) {
    reload();
    return false;
  }

  --_currClipBullets;

  enemyPlayerData.health -= (enemyPlayerData.armor > 0) ?
                            int(_damagePerRound * 0.75) : _damagePerRound;

  enemyPlayerData.armor -= (enemyPlayerData.armor > 0) ?
                           int(_damagePerRound * 0.25) : 0;

  if (enemyPlayerData.armor < 0) {
    enemyPlayerData.health -= -enemyPlayerData.armor;
    enemyPlayerData.armor = 0;
  }

  std::cout << "Enemy left with: "
            << enemyPlayerData.health << " health and "
            << enemyPlayerData.armor << " armor" << std::endl;

  return enemyPlayerData.health <= 0;
}
