#include <iostream>
#include <vector>
#include <chrono> // For high-resolution timing

// Function to perform matrix multiplication
void multiplyMatrices(const std::vector<std::vector<int>>& mat1,
                      const std::vector<std::vector<int>>& mat2,
                      std::vector<std::vector<int>>& result,
                      int R1, int C1, int C2) {
    for (int i = 0; i < R1; ++i) {
        for (int j = 0; j < C2; ++j) {
            result[i][j] = 0; // Initialize element
            for (int k = 0; k < C1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    // Define matrix dimensions (can be adjusted for larger tests)
    // R1: Rows of Matrix 1
    // C1: Columns of Matrix 1 (and Rows of Matrix 2)
    // C2: Columns of Matrix 2
    const int R1 = 500; // Increase for bigger file and more computation
    const int C1 = 400; // Increase for bigger file and more computation
    const int C2 = 500; // Increase for bigger file and more computation

    // Declare matrices
    std::vector<std::vector<int>> mat1(R1, std::vector<int>(C1));
    std::vector<std::vector<int>> mat2(C1, std::vector<int>(C2));
    std::vector<std::vector<int>> result(R1, std::vector<int>(C2));

    // Initialize matrices with some values (e.g., 1s for simplicity)
    // You can also use random values for more realistic scenarios
    for (int i = 0; i < R1; ++i) {
        for (int j = 0; j < C1; ++j) {
            mat1[i][j] = 1;
        }
    }

    for (int i = 0; i < C1; ++i) {
        for (int j = 0; j < C2; ++j) {
            mat2[i][j] = 1;
        }
    }

    std::cout << "Performing matrix multiplication of dimensions "
              << R1 << "x" << C1 << " and " << C1 << "x" << C2 << std::endl;

    // Start timer
    auto start_time = std::chrono::high_resolution_clock::now();

    // Perform multiplication
    multiplyMatrices(mat1, mat2, result, R1, C1, C2);

    // Stop timer
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << "Matrix multiplication completed in " << duration.count() << " ms." << std::endl;

    // Optional: Print a small part of the result matrix to verify (commented out for large matrices)
    /*
    std::cout << "\nResult matrix (top-left 5x5):\n";
    for (int i = 0; i < std::min(5, R1); ++i) {
        for (int j = 0; j < std::min(5, C2); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */

    return 0;
}
