// Copyright (c) Namakete (Ilya Oberemok полубог педиков) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#include "../header/include.hpp"
#include "../header/rook.hpp"
#include "../header/bishop.hpp"
#include "../header/fibonacci.hpp"
#include "../header/pow.hpp"
#include "../header/intToRoman.hpp"
#include "../header/sumOfNumber.hpp"

int main(int argc, char **argv){

    //все еще не нашел

    chess::rook(8, 3, 4);
    chess::bishop(8, 3, 4);
    std::cout << magic::fibonacci(5) << std::endl;
    std::cout << math::pow(2, 3) << std::endl;
    std::cout << math::pow(2.5, 3) << std::endl;
    std::cout << math::pow(2.5, -3) << std::endl;
    std::cout << math::pow(1, 0) << std::endl;
    std::cout << cnvrt::intToRoman(100) << std::endl;
    std::cout << math::sumOfNumber(2345) << std::endl;

    return EXIT_SUCCESS;
}
