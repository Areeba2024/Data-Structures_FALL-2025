#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x){
        	return mid;
		} 
        else if (arr[mid] < x){
        	low = mid + 1;
		}
        else{
        	high = mid - 1;
		} 
    }
    return -1;
}

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, n);

    int rollLastTwo = 45; 

    int pos = binarySearch(arr, n, rollLastTwo);

    if (pos == -1) {
        int newArr[100];
        for (int i = 0; i < n; i++) newArr[i] = arr[i];
        int idx = n;
        for (int i = 0; i < n; i++) {
            if (arr[i] > rollLastTwo) {
                for (int j = n; j > i; j--){
                newArr[j] = newArr[j - 1];
                newArr[i] = rollLastTwo;
                idx = i;
                break;
				}
            }
        }
        n++;
        arr[0] = newArr[0]; 
        for (int i = 0; i < n; i++) arr[i] = newArr[i];
        pos = binarySearch(arr, n, rollLastTwo);
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nValue found at index: " << pos << endl;

    return 0;
}
