#include "../header/include.hpp"

namespace magic{
    int fibonacci(int value){
        if (value <= 1)
            return value;
        return fibonacci(value - 1) + fibonacci(value - 2);
    }
}
