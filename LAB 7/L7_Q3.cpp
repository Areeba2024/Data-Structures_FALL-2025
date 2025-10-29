#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int time; 
};

void merge(Runner arr[], int start, int mid, int end) {
    int size = end - start + 1;
    Runner* temp = new Runner[size];
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (arr[i].time <= arr[j].time) {
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

void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    const int SIZE = 10;
    Runner runners[SIZE];

    cout << "Enter names and finish times (in seconds) of 10 participants:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Runner " << i + 1 << " name: ";
        cin >> runners[i].name;
        cout << "Finish time (seconds): ";
        cin >> runners[i].time;
    }

    mergeSort(runners, 0, SIZE - 1);

    cout << "\nTop 5 Fastest Runners:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].name << " - " << runners[i].time << " seconds\n";
    }

    return 0;
}
