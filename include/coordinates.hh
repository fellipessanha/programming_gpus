#pragma once

#include <ostream>
#include <utility>

namespace fourier {

template <typename T>
class Coordinates {
 public:
  std::pair<T, T> coords;

  Coordinates& operator+=(const Coordinates& rhs) {
    coords.first += rhs.coords.first;
    coords.second += rhs.coords.second;
    return *this;
  }
  friend Coordinates operator+(Coordinates& lhs, const Coordinates& rhs) {
    lhs += rhs;
    return lhs;
  }

  Coordinates& operator*=(const double& rhs) {
    coords.first *= rhs;
    coords.second += rhs;
    return *this;
  }
  friend Coordinates operator*(Coordinates& lhs, const double& rhs) {
    lhs *= rhs;
    return lhs;
  }
  friend Coordinates operator*(Coordinates&& lhs, const double& rhs) {
    lhs *= rhs;
    return lhs;
  }

  friend std::ostream& operator<<(std::ostream& out, const Coordinates& c) {
    return out << '(' << c.coords.first << ", " << c.coords.second << ")";
  }

  Coordinates() : coords(std::make_pair(0, 0)) {}

  Coordinates(T x, T y) : coords(std::make_pair(x, y)) {}
};
}  // namespace fourier