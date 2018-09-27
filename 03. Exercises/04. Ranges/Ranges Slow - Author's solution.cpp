#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

class Range {
    int index;
    int from;
    int to;
public:
    Range() {
    }

    Range(int index, int from, int to)
    : index(index)
    , from(from)
    , to(to) {
    }

    int getIndex() {
        return this->index;
    }

    int getFrom() {
        return this->from;
    }

    int getTo() {
        return this->to;
    }

    bool contains(int value) {
        return this->from <= value && value <= this->to;
    }
};

bool inARange(int value, vector<Range>& ranges) {
    for (Range range : ranges) {
        if (range.getFrom() <= value && value <= range.getTo()) {
            return true;
        }
    }

    return false;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    vector<Range> ranges;
    string line;
    int index = 0;
    while(getline(cin, line) && line != ".") {
        istringstream lineIn(line);

        int from, to;
        lineIn >> from >> to;

        ranges.push_back({index++, from, to});
    }

    ostringstream output;

    while(getline(cin, line) && line != ".") {
        istringstream lineIn(line);
        int value;
        lineIn >> value;

        if (inARange(value, ranges)) {
            output << "in";
        } else {
            output << "out";
        }

        output << endl;
    }

    cout << output.str() << endl;

    return 0;
}
