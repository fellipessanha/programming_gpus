#include "coordinates.hh"

namespace fourier {

class FourierPoint {
    int x_input;
    double y_input;
    Coordinates<double> fourier_transformed;

    fourier::Coordinates<double> e_alpha_i(double alpha){
        return Coordinates<double>(cos(alpha), sin(alpha));
    }

    Coordinates<double> calculateFourierCoordinates(int x, double y){
        return e_alpha_i(x) * y;
    }

    FourierPoint(int x, double y) : x_input(x), y_input(y) {
        fourier_transformed = calculateFourierCoordinates(x, y);
    }
};
}