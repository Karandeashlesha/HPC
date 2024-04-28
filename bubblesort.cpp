//Write a program to implement Parallel Bubble Sort using OpenMP. Use existing algorithms and measure the performance of sequential and parallel algorithms.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <omp.h>
using namespace std;

// Function to perform bubble sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}
void printVector(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}

int main() {
    int n = 100; // Size of vector
    std::vector<int> arr(n), arr_copy(n);

    srand(42);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
        arr_copy[i] = arr[i];
    }

    std::cout << "Original vector:" << std::endl;
    printVector(arr);

    double start = omp_get_wtime();
    bubbleSort(arr);
    double end = omp_get_wtime();
    std::cout << "\nSequential Bubble Sort: " << end - start << " seconds" << std::endl;
    printVector(arr);

    return 0;
}
