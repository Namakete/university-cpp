#include "../header/include.hpp"

namespace cnvrt {

    std::string intToRoman(int number) {
        std::vector<std::string> romans ({"I","IV","V","IX","X","XL","L","XC","C"});
        std::vector<int> value({1,4,5,9,10,40,50,90,100});
        
        int index=romans.size() - 1;
        
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
}
