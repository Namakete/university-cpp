// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#include <algorithm>
#include <iostream>
#include <vector>

class Factory {
   private:
    long long _begin;
    long long _max;
    long long _min;
    size_t _numbPositive;
    size_t _numbNegative;
    size_t _numbZero;
    long long _sumOdd;
    long long _sumEven;
    bool _beginEqualEnd;
    bool _emptyData;

   public:
    Factory();

    void operator()(long long);

    long long getMax() const;

    long long getMin() const;

    double getAverage() const;

    size_t getNumbPositive() const;

    size_t getNumbNegative() const;

    long long getSumOdd() const;

    long long getSumEven() const;

    bool checkFirstEqLast() const;
};

Factory::Factory() : _begin(0),
                     _max(0),
                     _min(0),
                     _numbPositive(0),
                     _numbNegative(0),
                     _numbZero(0),
                     _sumOdd(0),
                     _sumEven(0),
                     _beginEqualEnd(false),
                     _emptyData(true) {}

void Factory::operator()(long long int i) {
    if (_emptyData) {
        _begin = i;
        _max = i;
        _min = i;
        _emptyData = false;
    }

    if (i > _max) {
        _max = i;
    } else if (i < _min) {
        _min = i;
    }

    i > 0 ? ++_numbPositive : i == 0 ? ++_numbZero
                                     : ++_numbNegative;

    i % 2 == 0 ? _sumEven += i : _sumOdd += i;

    _beginEqualEnd = i == _begin;
}
/*
 * @brief - The maximum number in the sequence.
 */
long long Factory::getMax() const {
    return _max;
}
/*
 * @brief - The minimum number in the sequence.
 */
long long Factory::getMin() const {
    return _min;
}
/*
 * @brief - The average number in the sequence.
 */
double Factory::getAverage() const {
    return static_cast<double>(_sumOdd + _sumEven) / (_numbNegative + _numbPositive + _numbZero);
}
/*
 * @brief - The number of positive numbers.
 */
size_t Factory::getNumbPositive() const {
    return _numbPositive;
}
/*
 * @brief - The number of negative numbers.
 */
size_t Factory::getNumbNegative() const {
    return _numbNegative;
}
/*
 * @brief - The sum of the odd elements of a sequence.
 */
long long Factory::getSumOdd() const {
    return _sumOdd;
}
/*
 * @brief - The sum of even elements of a sequence.
 */
long long Factory::getSumEven() const {
    return _sumEven;
}
/*
 * @brief - Whether the first and last elements of the .sequence match.
 */
bool Factory::checkFirstEqLast() const {
    return _beginEqualEnd;
}

int main() {
    const int N = 15;
    std::vector<int> vec(N);

    for (int i = 0; i < N; i++) {
        vec[i] = std::rand() % 1000 - 500;
    }

    Factory analysis = std::for_each(vec.begin(), vec.end(), Factory());
    std::cout << "Max: " << analysis.getMax() << std::endl
              << "Min: " << analysis.getMin() << std::endl
              << "Mean: " << analysis.getAverage() << std::endl
              << "Positive: " << analysis.getNumbPositive() << std::endl
              << "Negative: " << analysis.getNumbNegative() << std::endl
              << "Odd Sum: " << analysis.getSumOdd() << std::endl
              << "Even Sum: " << analysis.getSumEven() << std::endl
              << "First/Last Equal: " << (analysis.checkFirstEqLast() ? "yes" : "no") << std::endl;
}