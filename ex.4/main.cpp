// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#include <iostream>

template <typename T>
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

template <typename T>
Iterator<T>::Iterator(T *p) : p(p) {}

template <typename T>
Iterator<T>::Iterator(const Iterator &it) : p(it.p) {}
/*
 * @brief - Overloading the operator `*`.
 */
template <typename T>
typename Iterator<T>::reference Iterator<T>::operator*() const {
    return *p;
}
/*
 * @brief - Overloading the operator `++`.
 */
template <typename T>
Iterator<T> &Iterator<T>::operator++() {
    ++p;
    return *this;
}
/*
 * @brief - Overloading the operator `--`.
 */
template <typename T>
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
    // We overload our operator using smart pointers. This is necessary 
    // to access elements in our structure using ordinary pointers.
    std::unique_ptr<int[]> _items;

   public:
    Container();

    _iterator begin();

    _iterator end();
};
/*
 * @brief - Constructor, creates an empty queue.
 */
Container::Container() : _items(new int[_size]) {
    _fillItems();
}
/*
 * @brief - Getting values from our operator.
 */
void Container::_fillItems() {
    for (int i = 1; i <= _size; ++i) {
        _items[i - 1] = _factorial(i);
    }
}
/*
 * @brief - We carry out a recursive operation of calculating the factorial.
 */
int Container::_factorial(int n) {
    return (n == 1) ? 1 : _factorial(n - 1) * n;
}
/*
 * @brief - Native function __begin__ to get the initial element of the list.
 */
Container::_iterator Container::begin() {
    return _items.get();
}
/*
 * @brief - Native function __end__ to get the initial element of the list.
 */
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