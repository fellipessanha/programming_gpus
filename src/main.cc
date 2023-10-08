#include <iostream>
#include <vector>
#include "coordinates.hh"
#include "utils.cc"

int main(){
    auto vals = fourier::get_2x_sample(11, 10);
    std::vector<fourier::Coordinates<double>> fouriered;
    for(auto k: vals){
        std::cout << "(" << k.first << ", " << k.second << ")\n";
        auto treated = fourier::e_alpha_i<double>(k.first);
        fouriered.push_back(treated * k.second);
    }

    std::cout << "\n agora fourierizado:\n";
    for(auto k: fouriered){
        std::cout << k << "\n";
    }
    return 0;
}