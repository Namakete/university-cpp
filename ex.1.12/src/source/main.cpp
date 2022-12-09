#include <iostream>
#include <iomanip>

int *generateRandomArray(const int size){
    int *arr = new int[size];

    for (int i = 0; i < size; ++i){
        arr[i] = rand() % 100 - 50;
    }

    return arr;
}

void sortArray(int *pArr, int size){
    int temp;
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if ((pArr[i] >= 0) && (pArr[j] >= 0) && (pArr[i] > pArr[j])){
                temp = pArr[i];
                pArr[i] = pArr[j];
                pArr[j] = temp;
            }
        }
    }
}

void outputArray(const int *pArr, int size){
    for (int i = 0; i < size; ++i){
        std::cout << std::setw(4) << pArr[i];
    }
    std::cout << std::endl;
}

int main(){
    const int ARRAY_SIZE = 6;

    int *pArr = generateRandomArray(ARRAY_SIZE);

    std::cout << "Source array: " << std::endl;
    outputArray(pArr, ARRAY_SIZE);

    sortArray(pArr, ARRAY_SIZE);

    std::cout << "After sorted array: " << std::endl;
    outputArray(pArr, ARRAY_SIZE);

    delete[] pArr;

    return 0;
}
