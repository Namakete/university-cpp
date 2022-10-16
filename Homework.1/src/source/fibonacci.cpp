#include "../header/include.hpp"

namespace magic{
    int fibonacci(int value){
        int x = 1;
        int y = 1;

        while(x < value){
            x = x + y;
            y = x - y;
        }

        return x;
    }
}
