#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

class Range {
    int from;
    int to;
public:
    Range() {
    }

    Range(int from, int to)
    : from(from)
    , to(to) {
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

bool inARange(int value, const map<int, shared_ptr<Range> >& rangesByStart, const map<int, shared_ptr<Range> >& rangesByEnd) {
    auto fromIt = rangesByStart.upper_bound(value); /// find first range start higher than value
    if (fromIt == rangesByStart.begin()) {
        return false; /// no range starting before value
    }

    fromIt--; /// go back to the first range that starts at or before value

    auto toIt = rangesByEnd.lower_bound(value);
    if (toIt == rangesByEnd.end()) {
        return false; /// no range ending at or after value
    }

    /// if both iterators point to the same range, then value is inside that range
    return fromIt->second == toIt->second;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    map<int, shared_ptr<Range> > rangesByFrom;
    map<int, shared_ptr<Range> > rangesByTo;

    string line;
    while(getline(cin, line) && line != ".") {
        istringstream lineIn(line);

        int from, to;
        lineIn >> from >> to;

        shared_ptr<Range> r = make_shared<Range>(from, to);
        rangesByFrom[from] = r;
        rangesByTo[to] = r;
    }

    ostringstream output;

    while(getline(cin, line) && line != ".") {
        istringstream lineIn(line);
        int value;
        lineIn >> value;

        if (inARange(value, rangesByFrom, rangesByTo)) {
            output << "in";
        } else {
            output << "out";
        }

        output << endl;
    }

    cout << output.str() << endl;

    return 0;
}
