#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

void swap(int &a, int &b) {
    int temp = a; a = b; b = temp;
}

int partition(int arr[], int low, int high, int pivotIndex) {
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, string pivotType) {
    if (low < high) {
        int pivotIndex;
        if (pivotType == "first") pivotIndex = low;
        else if (pivotType == "random") pivotIndex = low + rand() % (high - low + 1);
        else if (pivotType == "middle") pivotIndex = (low + high) / 2;
        else {
            int a = arr[low], b = arr[(low + high) / 2], c = arr[high];
            int median = max(min(a,b), min(max(a,b), c));
            if (median == a) pivotIndex = low;
            else if (median == b) pivotIndex = (low + high) / 2;
            else pivotIndex = high;
        }
        int pi = partition(arr, low, high, pivotIndex);
        quickSort(arr, low, pi - 1, pivotType);
        quickSort(arr, pi + 1, high, pivotType);
    }
}

int main() {
    srand(time(0));
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = 7;
    string pivots[] = {"first", "random", "middle", "median"};
    for (int k = 0; k < 4; k++) {
        int temp[7];
        for (int i = 0; i < n; i++) temp[i] = arr[i];
        comparisons = 0;
        quickSort(temp, 0, n - 1, pivots[k]);
        cout << "Pivot = " << pivots[k] << " -> Comparisons: " << comparisons << endl;
    }
    return 0;
}