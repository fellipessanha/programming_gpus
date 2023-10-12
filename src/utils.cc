#include <math.h>

#include <utility>
#include <vector>

#include "coordinates.hh"

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
}  // namespace fourier
