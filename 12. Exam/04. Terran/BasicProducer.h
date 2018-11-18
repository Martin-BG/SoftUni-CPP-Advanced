#ifndef BASIC_PRODUCER
#define BASIC_PRODUCER

#include "ProducerBase.h"
#include "Controllable.h"

#include "Worker.h"
#include "Marine.h"
#include "Depot.h"

class BasicProducer : public ProducerBase, public Controllable {
public:
  BasicProducer() { }

  Id getId() const override {
    return 0;
  }

  void handleCommand(const std::vector<std::string>& commandParts) override {
    if (commandParts[0] == "worker") {
      this->produced.push_back(new Worker(parseId(commandParts[1])));
    } else if (commandParts[0] == "marine") {
      this->produced.push_back(new Marine(parseId(commandParts[1])));
    } else if (commandParts[0] == "depot") {
      this->produced.push_back(new Depot());
    }
  }
};

#endif // !BASIC_PRODUCER
