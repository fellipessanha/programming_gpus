#pragma once

#include <vector>

#include "fourier_coordinate.hh"

namespace fourier {
class FourierPoint {
  std::vector<FourierCoordinate> coords;
  Coordinates<double> value;
  double frequency;

  void calculateFourierPoint() {
    double x_value = 0, y_value = 0;
    for (auto v : coords) {
      x_value += v.x();
      y_value += v.y();
    }
    value = Coordinates<double>(x_value, y_value);
  }

 public:
  std::pair<double, double> getValue() { return value.value(); }
  double getFrequency() { return frequency; }

  friend std::ostream& operator<<(std::ostream& out, const FourierPoint& c) {
    return out << c.value;
  }

  FourierPoint(std::vector<std::pair<int, double>> inputs, double _frequency)
      : frequency(_frequency) {
    for (auto v : inputs) {
      coords.push_back(FourierCoordinate(v, _frequency));
    }
    calculateFourierPoint();
  }
};
}  // namespace fourier