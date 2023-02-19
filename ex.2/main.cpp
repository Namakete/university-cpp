// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <utility>

class IFilter {
public:
    explicit IFilter();

    /*
    * @brief Remove all unnecessary spaces in text.
    * sorted String - `&str`
    */
    static void removeSpaces(std::string &str);

    /*
    * @brief Put a space after each punctuation mark.
    * sorted String - `&str`
    */
    static void checkPunctuation(std::string &str);

    /*
    * @brief Replace every 10-letter word with the word "Vau!!!".
    * sorted String - `&str`
    */
    static void replaceWord(std::string &str);

    /*
    * @brief Move text to new line if length is 40 char.
    * sorted String - `&str`
    */
    static void splitString(std::string &str);
};

IFilter::IFilter() = default;

void IFilter::removeSpaces(std::string &str) {
    std::regex spaces("\\s+");
    std::string temp = str;
    str = std::regex_replace(temp, spaces, "");
}

void IFilter::checkPunctuation(std::string &str) {
    std::regex punctuation("[.!?]");
    for (std::sregex_iterator it(str.begin(), str.end(), punctuation), end; it != end; ++it) {
        str.insert(it->position() + 1, " ");
    }
}

void IFilter::replaceWord(std::string &str) {
    std::regex word("([a-zA-Z-]){10,}");
    std::string tmp = str;
    str = regex_replace(tmp, word, "Vau!!!");
}

void IFilter::splitString(std::string &str) {
    for (int i = 40; i < str.size(); i += 40) {
        while (!isspace(str.at(i)) && i > 0) {
            --i;
        }

        if (i <= 0) {
            break;
        }

        str.replace(i, 1, 1, '\n');
        ++i;
    }
}

int main() {
    std::ifstream in("input.txt");
    std::string str((std::istreambuf_iterator<char>(in)),
                    std::istreambuf_iterator<char>());

    IFilter use;
    use.removeSpaces(str);
    use.checkPunctuation(str);
    use.replaceWord(str);
    use.splitString(str);

    std::cout << str;

    return 0;
}
