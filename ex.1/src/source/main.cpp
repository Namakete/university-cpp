// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#include "../header/include.hpp"
#include "../header/pow.hpp"
#include <cmath>

int main(int argc, char **argv){
    std::cout << math::pow(2, 3) << std::endl;
    std::cout << math::pow(2.5, 3) << std::endl;
    std::cout << math::pow(2.5, -3) << std::endl;
    return 0;
}