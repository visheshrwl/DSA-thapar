#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i, bool increasing) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (increasing) {
        if (left_child < n && arr[left_child] > arr[largest])
            largest = left_child;

        if (right_child < n && arr[right_child] > arr[largest])
            largest = right_child;
    } else {
        if (left_child < n && arr[left_child] < arr[largest])
            largest = left_child;

        if (right_child < n && arr[right_child] < arr[largest])
            largest = right_child;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, increasing);
    }
}

void heapSort(vector<int>& arr, bool increasing) {
    int n = arr.size();

    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    // Extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    // Sort in increasing order
    heapSort(arr, true);

    cout << "Sorted array in increasing order: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    // Sort in decreasing order
    heapSort(arr, false);

    cout << "Sorted array in decreasing order: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
