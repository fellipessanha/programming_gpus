#include <cstdio>
#include <iostream>
#include <vector>

#include "fourier_point.hh"
#include "utils.cc"

int main() {
  auto vals = fourier::get_2x_sample(11, 10);
  std::vector<fourier::FourierPoint> fouriered;
  for (double i = 1; i < 130; i++) {
    auto f = i / 10.0;
    auto point = fourier::FourierPoint(vals, f);
    std::cout << "for frequency " << f << ": value =\t" << point << "\n";
    fouriered.push_back(point);

    fourier::printToFile(fouriered);
  }
}