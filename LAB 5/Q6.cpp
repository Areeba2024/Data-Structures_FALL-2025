#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim) {
    if (dim == 1) {
        int sum = 0;
        for (int i = 0; i < sizes[0]; i++)
            sum += arr[i][0];
        return sum;
    }
    int sum = 0;
    for (int i = 0; i < sizes[dim - 1]; i++)
        sum += recursiveArraySum((int**)arr[i], sizes, dim - 1);
    return sum;
}

int main() {
    int a1[] = {1, 2, 3};
    int a2[] = {4, 5};
    int a3[] = {6, 7, 8, 9};

    int* arr[] = {a1, a2, a3};
    int sizes[] = {3, 3};
    int total = 0;

    for (int i = 0; i < 3; i++) {
        int s = (i == 0) ? 3 : (i == 1 ? 2 : 4);
        for (int j = 0; j < s; j++) total += arr[i][j];
    }

    cout << "Sum of all elements: " << total << endl;
    return 0;
}
