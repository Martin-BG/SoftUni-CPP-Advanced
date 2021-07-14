#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

std::string toText(const std::vector<std::string>& words,
                   const std::string& separator,
                   size_t maxLineLength);

int main() {
  const std::string& wordsSeparator = " ";
  const std::string& textEnd = "###";

  std::istream& in = std::cin;
  std::ostream& out = std::cout;

  std::vector<std::string> words{ };

  std::string line;
  while (std::getline(in, line) && line != textEnd) {
    std::istringstream ss(line);
    std::move(std::istream_iterator<std::string>(ss),
              std::istream_iterator<std::string>(),
              std::back_inserter(words));
  }

  int maxLineLength;
  in >> maxLineLength;

  const std::string& formattedText = toText(words, wordsSeparator, maxLineLength);
  out << formattedText;

  return 0;
}

std::string toText(const std::vector<std::string>& words,
                   const std::string& separator,
                   const size_t maxLineLength) {
  std::ostringstream out{ };

  size_t currentLineLength = 0;
  for (const auto& word : words) {
    const bool isNotNewLine = currentLineLength > 0;
    const size_t projectedLineLength = currentLineLength + (isNotNewLine ? separator.length() : 0) + word.length();
    const bool isNewLineRequired = isNotNewLine && projectedLineLength > maxLineLength;

    if (isNewLineRequired) {
      out << std::endl;
      currentLineLength = 0;
    } else if (isNotNewLine) {
      out << separator;
      currentLineLength += separator.length();
    }

    out << word;
    currentLineLength += word.length();
  }

  return out.str();
}
