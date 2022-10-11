#include <iostream>
#include <vector>

// Given the coordinates of the rook standing on the square of the
// chessboard (row number and column number). Write a loop (or loops)
// for displaying the coordinates of all cells under attack. Rook
// moves on any number of fields horizontally or vertically.
void rook(int DESK_SIZE, int x = 0, int y = 0){
    for(int i = 1; i <= DESK_SIZE; i++){
        for(int j = 1; j <= DESK_SIZE; j++){
            if((i == x || j == y) && (i != x || j != y)){
                std::cout << i << " - " << j << std::endl;
            }
        }
    }
}

// Given the coordinates of the bishop standing on the square of
// the chessboard (row number and column number). Write a loop (or loops)
// for displaying the coordinates of all cells under attack. Bishop
// moves to any number of squares diagonally.
void bishop(int DESK_SIZE, int x = 0, int y = 0){
    for(int i = 1; i <= DESK_SIZE; i++){
        for(int j = 1; j <= DESK_SIZE; j++){
            if(abs(i - y) == abs(j - x))
                std::cout << i << " - " << j <<std::endl;
        }
    }
}

// Write a program that displays a series of Fibonacci numbers on the screen.
// where each number is the sum of the previous two (1, 2, 3, 5, 8,
// 13, 21, ...)
int fibonacci(int value){
    int x = 1;
    int y = 1;

    while(x < value){
        x = x + y;
        y = x - y;
    }

    return x;
}

// Write a program that takes an integer (< 400) and
// displays it in Roman numerals.
std::string intToRoman(int number) {
    std::vector<std::string> romans ({"I","IV","V","IX","X","XL","L","XC","C"});
    std::vector<int> value({1,4,5,9,10,40,50,90,100});

    int index = romans.size() - 1;

    std::string ans="";

    if(number <! 400)
        return 0;

    while(number > 0){
        while(value[index] <= number){
            ans += romans[index];
            number -= value[index];
        }
        index--;
    }

    return ans;
}

// Write a program that accepts two numbers `a` and `b` from the keyboard
// and deriving to the power b. The degree must be given as an integer
// number and can be negative.
double pow(double base, int exponent){
    double result = 1;

    if(exponent > 0)
        for (int i = 0; i < exponent; i++)
            result *= base;

    for (int i = 0; i > exponent; i--)
        result /= base;

    return result;
}

// Write a program that takes an integer and outputs
// the sum of its digits.
int sumOfNumber(int number){
    if(number != 0)
        return ((number % 10) + sumOfNumber(number / 10));

    return 0;
}

int main() {
    rook(8, 3, 4);
    bishop(8, 3, 4);
    std::cout << fibonacci(5) << std::endl;
    std::cout << pow(2, 3) << std::endl;
    std::cout << pow(2.5, 3) << std::endl;
    std::cout << pow(2.5, -3) << std::endl;
    std::cout << pow(1, 0) << std::endl;
    std::cout << intToRoman(100) << std::endl;
    std::cout << sumOfNumber(2345) << std::endl;
    return 0;
}
