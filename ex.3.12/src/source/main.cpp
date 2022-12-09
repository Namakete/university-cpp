#include <iostream>
#include <fstream>

int getLength(std::ifstream &in) {
    int length;
    in >> length;
    in.ignore();

    return length;
}

char *mergeCharArray(char *dest, const char *src1, const char *src2) {
    int i = 0;
    while (*src1 && *src2) {
        dest[i++] = *src1++;
        dest[i++] = *src2++;
    }
    dest[i] = '\0';

    return dest;
}

std::string mergeString(const std::string &src1, const std::string &src2) {
    std::string result;

    int size = src1.size() < src2.size() ? src1.size() : src2.size();
    for (int i = 0; i < size; ++i) {
        result += src1[i];
        result += src2[i];
    }

    return result;
}

int main() {
    int clen1;
    int clen2;
    int clen3;

    std::string str1;
    std::string str2;
    std::string str3;

    std::ifstream in("infile.txt");
    if (!in.is_open()) {
        std::cout << "File can not be opened" << std::endl;
        return 1;
    }

    while (!in.eof()) {
        clen1 = getLength(in) + 1;
        char *char1 = new char[clen1];
        in.getline(char1, clen1);

        clen2 = getLength(in) + 1;
        char *char2 = new char[clen2];
        in.getline(char2, clen2);

        clen3 = (clen1 < clen2 ? clen1 : clen2);
        char *char3 = new char[clen3];
        mergeCharArray(char3, char1, char2);
        std::cout << "Char: " << char3 << std::endl;

        str1 = char1;
        str2 = char2;
        str3 = mergeString(str1, str2);
        std::cout << "String: " << str3 << std::endl;

        delete[] char1;
        delete[] char2;
        delete[] char3;
    }
    in.close();
}
