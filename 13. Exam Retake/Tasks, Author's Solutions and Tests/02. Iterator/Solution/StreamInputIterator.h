#ifndef STREAM_INPUT_ITERATOR
#define STREAM_INPUT_ITERATOR

#include <string>
#include <istream>
#include <iostream>
#include <sstream>

class StreamInputIterator {
	std::string current;
	std::istream& input;

	StreamInputIterator(std::istream& in, std::string current) : input(in), current(current) {
	}

	StreamInputIterator(std::istream& in) : input(in) {
		this->input >> current;
	}
public:
	static StreamInputIterator begin(std::istream& in) {
		return StreamInputIterator(in);
	}

	static StreamInputIterator end(std::istream& in, std::string endStr) {
		return StreamInputIterator(in, endStr);
	}

	StreamInputIterator& operator++() {
		this->input >> current;
		return *this;
	}

	int operator*() const {
		std::istringstream currentStream(this->current);
		int inputItem;
		currentStream >> inputItem;
		return inputItem;
	}

	bool operator!=(const StreamInputIterator& other) const {
		// NOTE: the address check for the streams is not necessary for this task, but it is good practice to do it for a more general task
		return &(this->input) != &(other.input) || this->current != other.current;
	}
};

#endif // !STREAM_INPUT_ITERATOR

