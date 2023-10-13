#pragma once

#include "coordinates.hh"
#include "math.h"

namespace fourier {

class FourierCoordinate {
  int x_input;
  double y_input;
  Coordinates<double> fourier_transformed;

 public:
  double x(void) { return fourier_transformed.value().first; }
  double y(void) { return fourier_transformed.value().second; }

  friend std::ostream& operator<<(std::ostream& out,
                                  const FourierCoordinate& c) {
    return out << c.fourier_transformed;
  }
  fourier::Coordinates<double> e_alpha_i(double alpha, double frequency) {
    alpha *= frequency;
    return Coordinates<double>(cos(alpha), sin(alpha));
  }

  Coordinates<double> calculateFourierCoordinates(int x, double y,
                                                  double frequency = 1) {
    return e_alpha_i(x, frequency) * y;
  }

  FourierCoordinate(int x, double y, double frequency)
      : x_input(x), y_input(y) {
    fourier_transformed = calculateFourierCoordinates(x, y, frequency);
  }

  FourierCoordinate(std::pair<int, double> i, double frequency)
      : x_input(i.first), y_input(i.second) {
    fourier_transformed =
        calculateFourierCoordinates(i.first, i.second, frequency);
  }
};
}  // namespace fourier