#ifndef CPP_ADVANCED_INPUT_H
#define CPP_ADVANCED_INPUT_H

#include <string>
#include <map>
#include <iostream>
#include <sstream>


template<typename T>
void read(std::map<size_t, T> &container, istream &istr) {
    std::string line;
    while (std::getline(istr >> std::ws, line) && line != "end") {
        size_t id{std::stoull(line)};
        container[id] = T(id, istr);
    }
}

template<typename T>
void print(T &t, ostream &ostr) {
    ostr << "book " << t.getId() << " \"" << t.getTitle() << "\" by \""
         << t.getAuthor() << "\" is \"";

    if (t.getBorrower() == "") {
        ostr << "available\"";
    } else {
        ostr << "borrowed by " << t.getBorrower() << '"';
    }

    ostr << '\n';
}

template<typename T>
void borrow(T &t, std::string &borrower) {
    t.setBorrowed(borrower);
    print(t, std::cout);
}

template<typename T>
void borrow(T &t) {
    std::string empty;
    borrow(t, empty);
}

template<typename T>
void print(const T &container, ostream &ostr) {
    ostr << "-----\ntotal books: " << container->size() << '\n';
    for (auto &book: *container) {
        print(book.second, ostr);
    }
}

#endif //CPP_ADVANCED_INPUT_H
