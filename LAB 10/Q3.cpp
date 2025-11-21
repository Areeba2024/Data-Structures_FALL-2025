#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int kthLargest(int arr[], int n, int k) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= n - k; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    return arr[n - k];
}

int main() {
    int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    int n1 = 7;
    cout << "Kth largest: " << kthLargest(arr1, n1, 3) << endl;

    int arr2[] = {12, 3, 5, 7, 19};
    int n2 = 5;
    cout << "Kth largest: " << kthLargest(arr2, n2, 2) << endl;
}
