#ifndef CPP_ADVANCED_WORD_H
#define CPP_ADVANCED_WORD_H

#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> words{ };

class Word {
private:
  std::string word;
  bool removeFromWordsOnDestruct;
public:
  explicit Word(std::string word) : word(std::move(word)), removeFromWordsOnDestruct(false) {
    ++words[this->word];
  }

  Word(const Word& other) : word(other.word), removeFromWordsOnDestruct(true) { }

  ~Word() {
    if (this->removeFromWordsOnDestruct) {
      words.erase(this->word);
    }
  }

  std::string getWord() const {
    return this->word;
  }

  int getCount() const {
    return words[this->word];
  }

  Word& operator=(const Word& other) = delete;

  bool operator<(const Word& other) const {
    return this->word < other.word;
  }

  friend std::ostream& operator<<(std::ostream& out, const Word& w);
};

#endif //CPP_ADVANCED_WORD_H
