#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in("input.txt");

    if (!in.is_open()){
        std::cerr << "File can not be opened\n";
        return 1;
    }else{œ
        int n;
        in >> n;
        std::cout << n * 2 << '\n';
    }

    while (!in.eof()){
        int n;
        in >> n;
        std::cout << n * 2 << '\n';
    }
    in.close();

    return 0;
}
