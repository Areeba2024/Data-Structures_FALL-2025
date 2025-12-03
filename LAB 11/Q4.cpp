#include <iostream>
using namespace std;

struct PairSum {
    int a;
    int b;
    int sum;
    bool used;
};

int main() {
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = 7;

    PairSum pairs[200]; 
    int idx = 0;

    for (int i = 0; i < 200; i++)
        pairs[i].used = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int s = arr[i] + arr[j];

            for (int k = 0; k < idx; k++) {
                if (pairs[k].used && pairs[k].sum == s) {
                    
                    if (pairs[k].a != arr[i] && pairs[k].a != arr[j] &&
                        pairs[k].b != arr[i] && pairs[k].b != arr[j]) {

                        cout << "(" << pairs[k].a << ", " << pairs[k].b
                             << ") and (" << arr[i] << ", " << arr[j] << ")";
                        return 0;
                    }
                }
            }

            pairs[idx].a = arr[i];
            pairs[idx].b = arr[j];
            pairs[idx].sum = s;
            pairs[idx].used = true;
            idx++;
        }
    }

    cout << "No pairs found";
    return 0;
}
