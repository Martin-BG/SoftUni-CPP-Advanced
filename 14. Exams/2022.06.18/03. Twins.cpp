#include <iostream>
#include <utility>
#include <vector>

struct Client {
  std::string name;
  int time{ };
};

struct Cashier {
  const std::string name;
  std::vector<Client> clients{ };
  size_t currentClient{0};

  explicit Cashier(char const* name) : name(name) { }

  void tick() {
    if (currentClient < clients.size()) {
      --clients[currentClient].time;
      if (clients[currentClient].time < 0) {
        currentClient++;
        tick();
      }
    }
  }

  void printStatus() {
    if (currentClient < clients.size()) {
      std::cout << name << " processing " << clients[currentClient].name << std::endl;
    } else {
      std::cout << name << " Idle" << std::endl;
    }
  }
};

int main() {
  size_t commands;
  std::cin >> commands;

  Cashier pepi(R"(Pepi)");
  Cashier mimi(R"(Mimi)");

  for (size_t i = 0; i < commands; ++i) {
    std::string cashierName;
    Client client;
    std::cin >> cashierName >> client.name >> client.time;
    Cashier& cashier = (cashierName == "Mimi") ? mimi : pepi;
    cashier.clients.push_back(std::move(client));
  }

  int timeToTrack;
  std::cin >> timeToTrack;

  while (--timeToTrack >= 0) {
    pepi.tick();
    pepi.printStatus();
    mimi.tick();
    mimi.printStatus();
  }

  return 0;
}
