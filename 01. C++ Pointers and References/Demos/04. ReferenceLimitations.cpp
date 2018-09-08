#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

class LetterFilter {
	const std::string& s;
	int index;
public:
	LetterFilter(const std::string& s)
		: s(s), index(0) { }

	char nextLetterOrNull() {
		while (index < s.size() && !isalpha(s[this->index])) {
			this->index++;
		}

		if (this->index == s.size()) {
			return 0;
		}

		return s[this->index++];
	}
};

int main() {
    using namespace std;

	string text = "abc 32 a98c";
	LetterFilter filter(text);
	char c;
	while (c = filter.nextLetterOrNull()) {
		cout << c;
	}

	return 0;
}
