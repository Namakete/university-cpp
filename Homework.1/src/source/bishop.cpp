#include "../header/include.hpp"

namespace chess {
    void bishop(int DESK_SIZE, int x = 0, int y = 0){
        for(int i = 1; i <= DESK_SIZE; i++){
            for(int j = 1; j <= DESK_SIZE; j++){
                if(abs(i - y) == abs(j - x))
                    std::cout << i << " - " << j <<std::endl;
            }
        }
    }
}
