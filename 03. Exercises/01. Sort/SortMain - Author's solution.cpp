#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Company.h"

int main() {
	using namespace std;

	vector<Company> companies;
	string line;
	while (getline(cin, line) && line != "end") {
		istringstream lineIn(line);

		string name;
		int id;
		lineIn >> name >> id ;
		companies.push_back(Company{id, name});
	}

	string sortBy;
	cin >> sortBy;

	bool(*lessThan)(const Company&, const Company&) = nullptr;
	if (sortBy == "name") {
		lessThan = [](const Company& a, const Company& b) {
			return a.getName() < b.getName();
		};
	}
	else if (sortBy == "id") {
		lessThan = [](const Company& a, const Company& b) {
			return a.getId() < b.getId();
		};
	}

	sort(companies.begin(), companies.end(), lessThan);

	for (Company c : companies) {
		cout << c.toString() << endl;
	}

	return 0;
}