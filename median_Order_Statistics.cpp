#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function to swap two elements of an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// partition function for quicksort algorithm
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// randomized algorithm to find the k-th smallest element in an array
int randomized_select(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }
    int pivot_index = rand() % (high - low + 1) + low;
    swap(&arr[pivot_index], &arr[high]);
    int pivot = partition(arr, low, high);
    int left_length = pivot - low + 1;
    if (k == left_length) {
        return arr[pivot];
    }
    else if (k < left_length) {
        return randomized_select(arr, low, pivot - 1, k);
    }
    else {
        return randomized_select(arr, pivot + 1, high, k - left_length);
    }
}

int main() {
    int arr[] = { 5, 7, 3, 8, 4, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // find the 3rd smallest element
    srand(time(NULL)); // seed random number generator
    int result = randomized_select(arr, 0, n - 1, k);
    cout<<endl;
    cout << "The " << k << "-th smallest element is: " << result << endl << endl;
    return 0;
}
