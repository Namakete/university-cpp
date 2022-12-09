#include <iostream>
#include <fstream>

double **allocateMatrix(int size) {
    double **matrix = new double *[size];

    for (int i = 0; i < size; ++i) {
        matrix[i] = new double[size];
    }
    return matrix;
}

double **inputMatrix(double **matrix, int matrix_size, std::ifstream &in) {
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            in >> matrix[i][j];
        }
    }

    return matrix;
}

void outputMatrix(double **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(10) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(double **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

double smoothingMatrix(double **const arr, const int size) {
    double sum_abs = 0.0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            double sum = 0.0;
            int count = 0;

            for (int k = i - 1; k <= i + 1; k++)
                for (int l = j - 1; l <= j + 1; l++)
                    if ((k >= 0) && (k < size) && (l >= 0) && (l < size) && ((k != i) || (l != j))) {
                        sum += arr[k][l];
                        ++count;
                    }
            arr[i][j] = sum / count;
            sum_abs += abs(arr[i][j]);
        }
    }

    return sum_abs;
}

int main() {
    int matrix_size;

    std::cout.precision(3);

    std::ifstream in("infile.txt");
    if (!in.is_open()) {
        std::cerr << "File can not be opened" << std::endl;
        return 1;
    }

    int count_matrix = 1;
    while (!in.eof()) {
        in >> matrix_size;

        double **matrix = allocateMatrix(matrix_size);

        std::cout << count_matrix++ << ") " << std::endl;

        inputMatrix(matrix, matrix_size, in);
        outputMatrix(matrix, matrix_size);

        std::cout << "The sum of the elements of the lower diagonal of smoothing matrix: "
                  << smoothingMatrix(matrix, matrix_size) << std::endl;

        std::cout << "----------------------------------------------" << std::endl;

        deleteMatrix(matrix, matrix_size);
    }
    in.close();

    return 0;
}
