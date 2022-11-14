#include <iostream>
#include <string>
#include <map>

struct Temperature {
  int min{ };
  int max{ };

  void update(const Temperature& other) {
    min = std::min(min, other.min);
    max = std::max(max, other.max);
  }
};

struct CityData {
  std::string name{ };
  Temperature temperature{ };

  friend std::istream& operator>>(std::istream& in, CityData& cityData) {
    getline(in >> std::ws, cityData.name);
    in >> std::ws >> cityData.temperature.min >> cityData.temperature.max;
    return in;
  }
};

int main() {
  std::map<std::string, Temperature, std::less<>> temperaturesByCities{ };

  size_t citiesCount{ };
  std::cin >> citiesCount;

  while (citiesCount > temperaturesByCities.size()) {
    CityData cityData;
    std::cin >> cityData;

    auto [it, isNew] = temperaturesByCities.try_emplace(std::move(cityData.name), cityData.temperature);
    if (!isNew) {
      it->second.update(cityData.temperature);
    }
  }

  for (const auto& [city, temperature]: temperaturesByCities) {
    std::cout << city << ' ' << temperature.min << ' ' << temperature.max << std::endl;
  }

  return 0;
}
