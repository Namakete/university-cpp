#include <iostream>

template<typename T>
class Iterator : public std::iterator<std::input_iterator_tag, T> {

    friend class Container;

public:
    Iterator(const Iterator &it);

    typename Iterator::reference operator*() const;

    Iterator &operator++();

    Iterator &operator--();

private:
    Iterator(T *p);

    T *p;
};

template<typename T>
Iterator<T>::Iterator(T *p) : p(p) {}

template<typename T>
Iterator<T>::Iterator(const Iterator &it) : p(it.p) {}

template<typename T>
typename Iterator<T>::reference Iterator<T>::operator*() const {
    return *p;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++() {
    ++p;
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator--() {
    --p;
    return *this;
}

class Container {
private:
    typedef Iterator<int> _iterator;
    typedef Iterator<const int> _constIterator;

private:
    void _fillItems();

    int _factorial(int n);

private:
    const size_t _size = 10;
    std::unique_ptr<int[]> _items;

public:
    Container();

    _iterator begin();

    _iterator end();
};

Container::Container() : _items(new int[_size]) {
    _fillItems();
}

void Container::_fillItems() {
    for (int i = 1; i <= _size; ++i) {
        _items[i - 1] = _factorial(i);
    }
}

int Container::_factorial(int n) {
    return (n == 1) ? 1 : _factorial(n - 1) * n;
}

Container::_iterator Container::begin() {
    return _items.get();
}

Container::_iterator Container::end() {
    return _items.get() + _size - 1;
}

int main() {
    auto factorials = Container();

    auto iterBegin = factorials.begin();

    for (int i = 0; i < 5; ++i) {
        ++iterBegin;
        std::cout << *iterBegin << std::endl;
    }

    auto iterEnd = factorials.end();

    for (int i = 0; i < 8; ++i) {
        --iterEnd;
        std::cout << *iterEnd << std::endl;
    }

    return 0;
}