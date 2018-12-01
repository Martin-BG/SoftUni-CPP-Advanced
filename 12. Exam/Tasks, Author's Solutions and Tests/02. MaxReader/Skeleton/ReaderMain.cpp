#include <iostream>
#include <vector>
#include <set>

#include "Reader.h"
#include "Max.h"

int main() {
	int numArrays;
	std::cin >> numArrays;
	std::cin.ignore();

	Reader reader(std::cin);

	std::set<VectorMax> maximums;
	for (int i = 0; i < numArrays; i++) {
		std::vector<int> arr;
		reader >> arr;
		VectorMax m;
		arr >> m;
		maximums.insert(m);
	}

	for (auto m : maximums) {
		std::cout << m << std::endl;
	}

	return 0;
}