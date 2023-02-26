#include <iostream>
#include <vector>
#include <algorithm>

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

    double getMean() const;

    size_t getNumbPositive() const;

    size_t getNumbNegative() const;

    long long getSumOdd() const;

    long long getSumEven() const;

    bool checkFirstEqLast() const;
};

Factory::Factory() :
        _begin(0),
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

    i > 0 ? ++_numbPositive
          : i == 0 ? ++_numbZero : ++_numbNegative;

    i % 2 == 0 ? _sumEven += i : _sumOdd += i;

    _beginEqualEnd = i == _begin;
}

long long Factory::getMax() const {
    return _max;
}

long long Factory::getMin() const {
    return _min;
}

double Factory::getMean() const {
    return static_cast<double>(_sumOdd + _sumEven) / (_numbNegative + _numbPositive + _numbZero);
}

size_t Factory::getNumbPositive() const {
    return _numbPositive;
}

size_t Factory::getNumbNegative() const {
    return _numbNegative;
}

long long Factory::getSumOdd() const {
    return _sumOdd;
}

long long Factory::getSumEven() const {
    return _sumEven;
}

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
    std::cout << "Max: " << analysis.getMax() << '\n'
              << "Min: " << analysis.getMin() << '\n'
              << std::fixed
              << "Mean: " << analysis.getMean() << '\n'
              << "Positive: " << analysis.getNumbPositive() << '\n'
              << "Negative: " << analysis.getNumbNegative() << '\n'
              << "Odd Sum: " << analysis.getSumOdd() << '\n'
              << "Even Sum: " << analysis.getSumEven() << '\n'
              << "First/Last Equal: " << (analysis.checkFirstEqLast() ? "yes" : "no") << '\n';
}