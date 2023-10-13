#pragma once

#include <math.h>

#include <cstdio>
#include <utility>
#include <vector>

#include "fourier_point.hh"

namespace fourier {

std::vector<std::pair<int, double>> get_2x_sample(int sample_size,
                                                  int frequency = 1) {
  std::vector<std::pair<int, double>> ret;
  for (int i = 0; i < sample_size; i++) {
    double j = i * 2 * 3.1415 / frequency;
    auto val =
        std::make_pair(i, cos(j) + cos(j / 2) + cos(j / 5) + cos(j / 10));
    ret.push_back(val);
  }
  return ret;
}

void printToFile(std::vector<fourier::FourierPoint> data) {
  FILE* f = fopen("fourier_plot_data.csv", "w");
  fprintf(f, "frequency,x,y\n");
  for (auto i : data) {
    fprintf(f, "%f,%f,%f\n", i.getFrequency(), i.getValue().first,
            i.getValue().second);
  }
  fclose(f);
}
}  // namespace fourier