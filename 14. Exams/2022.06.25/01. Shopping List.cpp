#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct City {
  std::string name{ };
  float price{ };

  constexpr auto operator<=>(const City& other) const noexcept {
    return price <=> other.price;
  }

  constexpr bool operator==(const City& other) const noexcept = default;

  friend float operator+(const float sum, const City& item) {
    return sum + item.price;
  }

  friend std::istream& operator>>(std::istream& in, City& item) {
    getline(in >> std::ws, item.name);
    float quantity;
    float singlePrice;
    in >> singlePrice >> quantity;
    item.price = singlePrice * quantity;
    return in;
  }

  friend std::ostream& operator<<(std::ostream& out, const City& item) {
    std::cout << item.name << ' ' << item.price << std::endl;
    return out;
  }
};

int main() {
  size_t itemsCount;
  std::cin >> itemsCount;
  std::vector<City> items(itemsCount);

  std::ranges::for_each(items.begin(), items.end(), [](City& item) { std::cin >> item; });
  std::ranges::stable_sort(items.begin(), items.end(), std::greater<>());
  std::cout << "The total sum is: " << std::accumulate(items.cbegin(), items.cend(), 0.0f) << " lv." << std::endl;
  std::ranges::for_each(items.cbegin(), items.cend(), [](const City& item) { std::cout << item; });

  return 0;
}
