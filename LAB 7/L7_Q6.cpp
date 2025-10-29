#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[20];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void merge(int arr[], int start, int mid, int end) {
    int size = end - start + 1;
    int  *temp = new int[size];
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (int t = 0; t < size; t++) {
        arr[start + t] = temp[t];
    }

    delete[] temp;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr1[10] = {9, 45, 12, 1, 33, 22, 19, 7, 10, 5};
    int arr2[10] = {3, 8, 27, 18, 99, 42, 16, 30, 25, 11};
    int arr[20];
    for (int i = 0; i < 10; i++) arr[i] = arr1[i];
    for (int i = 0; i < 10; i++) arr[i + 10] = arr2[i];
    cout << "Before sorting: ";
    for (int i = 0; i < 20; i++) cout << arr[i] << " ";
    cout << endl;
    radixSort(arr, 20);
    cout << "After sorting using Radix Sort: ";
    for (int i = 0; i < 20; i++) cout << arr[i] << " ";
    cout << endl;
    mergeSort(arr, 0, 19);
    cout << "After sorting using Merge Sort: ";
    for (int i = 0; i < 20; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
    return 0;
}
