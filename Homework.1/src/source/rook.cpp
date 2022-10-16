#include "../header/include.hpp"

namespace chess{
    void rook(int DESK_SIZE, int x = 0, int y = 0){
        for(int i = 1; i <= DESK_SIZE; i++){
            for(int j = 1; j <= DESK_SIZE; j++){
                if((i == x || j == y) && (i != x || j != y)){
                    std::cout << i << " - " << j << std::endl;
                }
            }
        }
    }
}
