#include <iostream>
#include <map>

int main() {
  size_t citiesCount;
  std::cin >> citiesCount;

  std::map<std::string, int, std::less<>> totalPriceByCity{ };

  while (citiesCount > totalPriceByCity.size()) {
    std::string cityName;
    getline(std::cin >> std::ws, cityName);

    int productPrice;
    int quantity;
    std::cin >> std::ws >> productPrice >> quantity;
    const int totalPrice = productPrice * quantity;

    auto [it, isNew] = totalPriceByCity.try_emplace(std::move(cityName), totalPrice);
    if (!isNew) {
      it->second += totalPrice;
    }
  }

  for (const auto& [cityName, totalPrice]: totalPriceByCity) {
    std::cout << cityName << ' ' << totalPrice << std::endl;
  }

  return 0;
}
