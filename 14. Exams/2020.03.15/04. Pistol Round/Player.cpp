#include "Player.h"
#include "DesertEagle.h"
#include "Glock.h"

void Player::buyPistol(PistolType pistolType,
                       const int damagePerRound,
                       const int clipSize,
                       const int remainingAmmo) {
  switch (pistolType) {
  case PistolType::DESERT_EAGLE:
    _pistol = new DesertEagle(damagePerRound, clipSize, remainingAmmo);
    break;
  case PistolType::GLOCK:
    _pistol = new Glock(damagePerRound, clipSize, remainingAmmo);
    break;
  }
}
