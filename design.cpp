#include <iostream>
#include <vector>
#include <algorithm>

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void spiralFill(const std::vector<int>& sortedArray, std::vector<std::vector<int>>& matrix, int n) {
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int index = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = sortedArray[index++];
        }
        ++top;

        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = sortedArray[index++];
        }
        --right;

        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = sortedArray[index++];
            }
            --bottom;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = sortedArray[index++];
            }
            ++left;
        }
    }
}

int main() {
    const int n = 3;
    std::vector<int> array = {7, 2, 9, 3, 5, 1, 4, 8, 6};

    // Sort the array
    std::sort(array.begin(), array.end());

    // Initialize a 3x3 matrix with 0s
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    // Fill the matrix spirally
    spiralFill(array, matrix, n);

    // Print the matrix
    printMatrix(matrix);

    return 0;
}
