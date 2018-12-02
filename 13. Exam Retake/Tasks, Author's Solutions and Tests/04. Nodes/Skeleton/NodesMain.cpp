#include <iostream>
#include <string>
#include <sstream>

#include <cstdlib>

#include "Node.h"

#include "NodeNetwork.h"

int main() {
	NodeNetwork network;

	std::string line;
	while (std::getline(std::cin, line) && line != "end") {
		std::istringstream lineIn(line);

		size_t id;
		std::string type;
		lineIn >> id >> type;

		Node* node = nullptr;
		if (type == "int") {
			node = new DigitsToIntNode(id);
		}
		else if (type == "reverse") {
			node = new ReverseNode(id);
		}
		else if (type == "sum") {
			node = new SumNode(id);
		}
		else if (type == "filter") {
			std::vector<byte> filtered;
			byte f;
			while (lineIn >> f) {
				filtered.push_back(f);
			}

			node = new FilterNode(id, filtered);
		}
		else if (type == "input") {
			node = new InputNode(id, std::cin);
		}
		else if (type == "output") {
			std::string outputType;
			lineIn >> outputType;
			node = new OutputNode(id, std::cout, outputType == "number");
		}

		network.addNode(node);
	}

	while (std::getline(std::cin, line) && line != "end") {
		std::istringstream lineIn(line);
		size_t fromId, toId;
		lineIn >> fromId >> toId;
		network.connect(fromId, toId);
	}

	network.compute();

	return 0;
}