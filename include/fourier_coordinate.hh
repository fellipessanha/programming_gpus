#include "coordinates.hh"
#include "math.h"

namespace fourier {

class FourierCoordinate {
  int x_input;
  double y_input;
  Coordinates<double> fourier_transformed;

 public:
  friend std::ostream& operator<<(std::ostream& out,
                                  const FourierCoordinate& c) {
    return out << c.fourier_transformed;
  }
  fourier::Coordinates<double> e_alpha_i(double alpha) {
    return Coordinates<double>(cos(alpha), sin(alpha));
  }

  Coordinates<double> calculateFourierCoordinates(int x, double y) {
    return e_alpha_i(x) * y;
  }

  FourierCoordinate(int x, double y) : x_input(x), y_input(y) {
    fourier_transformed = calculateFourierCoordinates(x, y);
  }

  FourierCoordinate(std::pair<int, double> i)
      : x_input(i.first), y_input(i.second) {
    fourier_transformed = calculateFourierCoordinates(i.first, i.second);
  }

  FourierCoordinate(std::pair<int, double>& i)
      : x_input(i.first), y_input(i.second) {
    fourier_transformed = calculateFourierCoordinates(i.first, i.second);
  }
};
}  // namespace fourier