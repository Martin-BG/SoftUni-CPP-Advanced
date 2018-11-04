#include <iostream>
#include <vector>
#include <string>

#include <thread>
#include <chrono>

#include "RenderingUtils.h"
#include "TomAndJerryFactory.h"

#include "mingw.thread.h"

const int WORLD_SIZE = 30;

int Position::MinPosition = 0;
int Position::MaxPosition = WORLD_SIZE - 1;

std::unique_ptr<OrganismFactory> getFactory() {
  return std::make_unique<TomAndJerryFactory>();
}

int main() {
  Renderer r(WORLD_SIZE);

  std::vector<std::shared_ptr<Organism> > organisms = getFactory()->buildOrganisms();

  while (true) {
    for (const auto& o : organisms) {
      o->act();
      r.render(o->getPosition(), o->getImage());
    }

    r.flushToScreen();

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
