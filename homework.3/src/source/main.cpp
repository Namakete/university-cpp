#include <iostream>

bool isOrdered(const int *parr, const int amount) {
    bool isOrdered = true;

    for (int i = 0; i < amount - 1; i++) {
        if (*(parr + i) > *((parr + i) + 1))
            isOrdered = false;
    }

    return isOrdered;
}

void insertionSort(int *parr, const int amount) {
    int current;
    int key;

    for (int i = 1; i < amount; i++) {
        current = i - 1;
        key = *(parr + i);

        while ((key < *(parr + current)) && (current >= 0)) {
            *((parr + current) + 1) = *(parr + current);
            current -= 1;
        }
        *((parr + current) + 1) = key;
    }
}

int partition(int *parr, int low, int high){
    int pivot = parr[low];

    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (*(parr + i) <= pivot)
            count++;
    }

    int pivotkey = low + count;

    std::swap(parr[pivotkey], parr[low]);

    int i = low, j = high;

    while (i < pivotkey && j > pivotkey) {
        while (*(parr + i) <= pivot)
            i++;
        while (*(parr + j) > pivot)
            j--;
        if (i < pivotkey && j > pivotkey)
            std::swap(parr[i++], parr[j--]);
    }

    return pivotkey;
}

void quickSort(int *parr, int low, int high){
    if (low >= high)
        return;

    int p = partition(parr, low, high);

    quickSort(parr, low, p - 1);
    quickSort(parr, p + 1, high);
}

int findValue(const int *parr, const int value, const int low, const int high) {
    if (low > high)
        return -1;

    int middle = ((low + high) / 2);

    if (value == *(parr + middle))
        return middle;
    else if (value < *(parr + middle))
        return findValue(parr, value, low, middle - 1);
    else
        return findValue(parr, value, middle + 1, high);
}

bool isVarNameChar(const char c) {
    return std::isdigit(c) || std::isalpha(c) || c != '_';
}

bool isVarname(const std::string &name) {
    bool isvarname = false;

    for (std::string::const_iterator i = name.begin(); i != name.end(); i++) {
        if (!isVarNameChar(*i))
            isvarname = true;
    }

    return isvarname;
}

int main() {
    int arr[] = {6, 1, 2, 6, 7, 8, 6};
    int size = sizeof(arr) / sizeof(*arr); 

    //quickSort(arr, 0, size - 1);

    insertionSort(arr, size);

    for (int i = 0; i < size; i++) {
        std::cout << i << "| " << arr[i] << std::endl;
    }

    if (!(isOrdered(arr, size)))
        std::cout << "array is unordered!" << std::endl;
    else
        std::cout << "array is ordered!" << std::endl;

    int key = findValue(arr, 6, *arr, size - 1);

    if (key <= -1)
        std::cout << "key of array is not found " << std::endl;
    else
        std::cout << "key of array is " << key << std::endl;

    std::cout << isVarname("_hello8") << std::endl;
    std::cout << isVarname("8hello") << std::endl;
    std::cout << isVarname("hello_world") << std::endl;
    std::cout << isVarname("hello world") << std::endl;
    std::cout << isVarname(" hello") << std::endl;
    std::cout << isVarname("") << std::endl;

    return 0;
}
