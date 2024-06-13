#include <iostream>
#include <cstdlib>
#include <ctime>

int** bott_triangle_matrix(int n) {
    int** matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[i + 1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

int** top_triangle_matrix(int n) {
    int** matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n - i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

int retrive_num_from_top(int** matrix, int i, int j) {
    const int NOT_FOUND = -9999;
    if (i <= j) {
        return matrix[i][j - i];
    }
    return NOT_FOUND;
}

int retrive_num_from_bottom(int** matrix, int i, int j) {
    const int NOT_FOUND = -9999;
    if (j <= i) {
        return matrix[i][j];
    }
    return NOT_FOUND;
}

int retrive_full_top_matrix(int** matrix, int i, int j) {
    if (j < i) {
        return 0;
    }
    return retrive_num_from_top(matrix, i, j);
}

int retrive_full_bottom_matrix(int** matrix, int i, int j) {
    if (i < j) {
        return 0;
    }
    return retrive_num_from_bottom(matrix, i, j);
}

int main() {
    int n = 6;
    int **top_matrix = top_triangle_matrix(n);
    int **bottom_matrix = bott_triangle_matrix(n);

    std::cout << "Top Matrix: " << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << retrive_full_top_matrix(top_matrix, i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nBottom Matrix: " << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << retrive_full_bottom_matrix(bottom_matrix, i, j) << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] top_matrix[i];
        delete[] bottom_matrix[i];
    }
    delete[] top_matrix;
    delete[] bottom_matrix;

    return 0;
}
