#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <set>

#include "Unit.h"
#include "Producer.h"
#include "Controllable.h"
#include "BasicProducer.h"

template<typename PtrContainer>
void deleteAll(PtrContainer container) {
	for (auto ptr : container) {
		delete ptr;
	}
	container.clear();
}

std::vector<std::string> getWords(std::istream& in) {
	std::vector<std::string> words;

	std::string word;
	while (in >> word) {
		words.push_back(word);
	}

	return words;
}

std::list<UnitPtr> getProducedUnits(const std::set<ProducerPtr> producers) {
	std::list<UnitPtr> producedFromAll;

	for (auto p : producers) {
		std::list<UnitPtr> produced = p->extractProduced();
		producedFromAll.insert(producedFromAll.end(), produced.begin(), produced.end());
	}

	return producedFromAll;
}

int main() {
	std::list<UnitPtr> objects;

	std::set<ProducerPtr> producers;
	std::map<Id, ControllablePtr> controllables;

	BasicProducer initialProducer;
	producers.insert(&initialProducer);

	std::string action;
	while (std::getline(std::cin, action) && action != "end") {
		std::istringstream actionIn(action);
		std::string type;
		actionIn >> type;

		int time;
		if (type == "idle") {
			actionIn >> time;
		}
		else if (type == "create") {
			initialProducer.handleCommand(getWords(actionIn));

			time = 1;
		}
		else if (type == "command") {
			Id id;
			actionIn >> id;

			controllables[id]->handleCommand(getWords(actionIn));

			time = 1;
		}

		for (int i = 0; i < time; i++) {
			for (auto o : objects) {
				o->update();
			}

			for (auto o : getProducedUnits(producers)) {
				ProducerPtr asProducer = dynamic_cast<ProducerPtr>(o);
				if (asProducer) {
					producers.insert(asProducer);
				}

				ControllablePtr asControllable = dynamic_cast<ControllablePtr>(o);
				if (asControllable) {
					controllables[asControllable->getId()] = asControllable;
				}

				objects.push_back(o);
			}
		}
	}

	std::cout << "---" << std::endl;

	for (auto o : objects) {
		std::cout << o->getInfo() << std::endl;
	}

	deleteAll(objects);

	return 0;
}