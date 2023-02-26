// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

namespace Model {
template <class T>
class ISorterModels {
   private:
    std::vector<T> _data;
    std::string _file;

   public:
    /*
     * @param - Vector array - `_data`.
     */
    explicit ISorterModels(std::vector<T> &_data);

    /*
     * @brief - Gets and returns the size of an array.
     */
    std::vector<T> getData();

    /*
     * @brief - Sorting a vector array using the insertion algorithm.
     */
    void insertionSort();

    /*
     * @brief - Sorting a vector array using the STL function.
     */
    void sortSTL();

    /*
     * @brief - Sorting a vector array using a selection algorithm. The array
     * elements are sorted using the `at()` function.
     */
    void selectionSort();

    /*
     * @brief - Sorting a vector array using a selection algorithm. The array
     * elements are sorted using the `iterator`.
     */
    void insertionSortVector();
};
}  // namespace Model

template <class T>
Model::ISorterModels<T>::ISorterModels(std::vector<T> &_data)
    : _data(std::move(_data)) {}

template <class T>
std::vector<T> Model::ISorterModels<T>::getData() {
    return _data;
}

template <class T>
void Model::ISorterModels<T>::insertionSort() {
    for (std::size_t i = 0; i < _data.size(); ++i) {
        std::size_t key = _data[i];
        std::size_t j = i - 1;

        while ((j >= 0) && (_data[j] > key)) {
            _data[j + 1] = _data[j];
            j = j - 1;
        }
        _data[j + 1] = key;
    }
}

template <class T>
void Model::ISorterModels<T>::sortSTL() {
    std::sort(_data.begin(), _data.end());
}

template <class T>
void Model::ISorterModels<T>::selectionSort() {
    for (std::size_t i = 0; i < _data.size() - 1; ++i) {
        std::size_t minIndex = i;

        for (std::size_t j = i + 1; j < _data.size(); ++j) {
            if (_data.at(j) < _data.at(minIndex)) {
                minIndex = j;
            }

            int temp = _data.at(minIndex);

            _data.at(minIndex) = _data.at(i);
            _data.at(i) = temp;
        }
    }
}

template <class T>
void Model::ISorterModels<T>::insertionSortVector() {
    int temp;

    for (std::vector<int>::iterator i = _data.begin() + 1, j; i != _data.end();
         ++i) {
        temp = *i;

        for (j = i - 1; j >= _data.begin() && *j > temp; --j) {
            *(j + 1) = *j;
        }
        *(j + 1) = temp;
    }
}

class IReader {
   public:
    explicit IReader();

    /*
     * @brief - A function that reads data from a file as type char.
     * @param - Empty vector array - `item`.
     * @param - Name or path to the file - `file`.
     */
    static void readDataFromFile(std::vector<char> &item,
                                 const std::string &file);
};

IReader::IReader() = default;

void IReader::readDataFromFile(std::vector<char> &item,
                               const std::string &file) {
    std::ifstream in(file);

    size_t capacity = 1;
    size_t size = 0;

    auto *data = new char[capacity];

    if (!in.is_open()) {
        std::cout << "File can not be opened" << std::endl;
    }

    while (!in.eof()) {
        in.read(data + size, capacity - size);
        size += in.gcount();

        if (size == capacity) {
            capacity *= 2;
            char *temp = new char[capacity];
            std::move(data, data + size, temp);
            data = temp;
        }
    }
    in.close();
    item.clear();
    item = std::vector<char>(data, data + size);
}

template <class T>
class IInputEdit {
   public:
    explicit IInputEdit();

    /*
     * @brief - A function that collects the values entered from the keyboard into
     * the stream.
     * @param - Empty vector array - `item`.
     */
    static void inputEditor(std::vector<T> &item);
};

template <class T>
IInputEdit<T>::IInputEdit() = default;

template <class T>
void IInputEdit<T>::inputEditor(std::vector<T> &item) {
    item.clear();

    int in;

    std::cout << "Enter multiple values:" << std::endl;

    while (std::cin >> in && in != 0) {
        item.push_back(in);
    }

    if (item.back() == 1) {
        for (auto itr = item.begin(); itr != item.end(); ++itr) {
            if ((*itr % 2) == 0) {
                item.erase(itr);
            }
        }
    } else if (item.back() == 2) {
        for (auto itr = item.begin(); itr != item.end(); ++itr) {
            if ((*itr % 3) == 0) {
                item.insert(itr + 1, 3, 1);
            }
        }
    }
}

template <class T>
class IRandom {
   public:
    explicit IRandom();

    /*
     * @brief - Random number generation function.
     * @param - Empty vector array - `item`.
     * @param - Size of array - `size`.
     * @param - From - `a`.
     * @param - To - `b`.
     */
    static void fillRandom(std::vector<T> &item, int size, T a, T b);
};

template <class T>
IRandom<T>::IRandom() = default;

template <class T>
void IRandom<T>::fillRandom(std::vector<T> &item, int size, T a, T b) {
    item.clear();
    item.resize(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(a, b);
    std::generate_n(item.begin(), item.size(), [&]() { return dis(gen); });
}

namespace View {
template <class T>
class IPrintViews {
   public:
    /*
     * @brief - Array output function.
     * @param - Vector array - `_data`.
     */
    void out(std::vector<T> _data);
};
}  // namespace View

template <class T>
void View::IPrintViews<T>::out(std::vector<T> _data) {
    for (auto &item : _data) {
        std::cout << std::setw(10) << item;
    }
    std::cout << std::endl;
}

namespace Controller {
template <class T>
class ISorterControllers {
   private:
    Model::ISorterModels<T> _sorterModels;
    View::IPrintViews<T> _printViews;

   public:
    explicit ISorterControllers(std::vector<T> _data);

    void insertionSort();

    void sortSTL();

    void selectionSort();

    void insertionSortVector();
};
}  // namespace Controller

template <class T>
Controller::ISorterControllers<T>::ISorterControllers(std::vector<T> _data)
    : _sorterModels(_data) {}

template <class T>
void Controller::ISorterControllers<T>::insertionSort() {
    auto start = std::chrono::high_resolution_clock::now();
    _sorterModels.insertionSort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = (end - start);
    _printViews.out(_sorterModels.getData());
    std::cout << "Time: " << duration.count() << "s" << std::endl;
}

template <class T>
void Controller::ISorterControllers<T>::sortSTL() {
    auto start = std::chrono::high_resolution_clock::now();
    _sorterModels.sortSTL();
    auto end = std::chrono::high_resolution_clock::now();
    _printViews.out(_sorterModels.getData());
    std::chrono::duration<float> duration = (end - start);
    std::cout << "Time: " << duration.count() << "s" << std::endl;
}

template <class T>
void Controller::ISorterControllers<T>::selectionSort() {
    auto start = std::chrono::high_resolution_clock::now();
    _sorterModels.selectionSort();
    auto end = std::chrono::high_resolution_clock::now();
    _printViews.out(_sorterModels.getData());
    std::chrono::duration<float> duration = (end - start);
    std::cout << "Time: " << duration.count() << "s" << std::endl;
}

template <class T>
void Controller::ISorterControllers<T>::insertionSortVector() {
    auto start = std::chrono::high_resolution_clock::now();
    _sorterModels.insertionSortVector();
    auto end = std::chrono::high_resolution_clock::now();
    _printViews.out(_sorterModels.getData());
    std::chrono::duration<float> duration = (end - start);
    std::cout << "Time: " << duration.count() << "s" << std::endl;
}

int main() {
    std::cout.precision(1);

    std::vector<int> in;
    IInputEdit<int>::inputEditor(in);

    Controller::ISorterControllers<int> u(in);
    u.insertionSort();
    u.sortSTL();
    u.selectionSort();
    u.insertionSortVector();

    std::vector<double> data;
    std::vector<int> size{3, 5, 7, 9, 11};

    for (auto &s : size) {
        IRandom<double>::fillRandom(data, s, -0.1, 1.0);
        Controller::ISorterControllers<double> m(data);
        m.sortSTL();
    }

    std::vector<char> str;
    IReader::readDataFromFile(str, "input.txt");

    for (auto &item : str) {
        std::cout << item;
    }
    std::cout << std::endl;

    return 0;
}