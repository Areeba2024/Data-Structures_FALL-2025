#include <iostream>
#include <string>
using namespace std;

int linear(string a[], int n, string x, int &s) {
    s = 0;
    for (int i = 0; i < n; i++) {
        s++;
        if (a[i] == x) return i;
    }
    return -1;
}

int binary(string a[], int n, string x, int &s) {
    int l = 0, h = n - 1;
    s = 0;
    while (l <= h) {
        s++;
        int m = (l + h) / 2;
        if (a[m] == x) return m;
        else if (a[m] < x) l = m + 1;
        else h = m - 1;
    }
    return -1;
}

int main() {
    string a[] = {"Ahmed","Ali","Basit","Karim","Rizwan","Sarwar","Tariq","Taufiq","Yasin","Zulfiqar"};
    int n = sizeof(a) / sizeof(a[0]);
    string find[] = {"Aftab", "Rizwan", "Tariq"};
    int k = 3;

    for (int i = 0; i < k; i++) {
        string x = find[i];
        cout << "\nSearching for: " << x << endl;

        int s1, s2;
        int i1 = linear(a, n, x, s1);
        int i2 = binary(a, n, x, s2);

        if (i1 != -1) cout << "Linear: Found at " << i1 << " in " << s1 << " steps\n";
        else cout << "Linear: Not found (" << s1 << " steps)\n";

        if (i2 != -1) cout << "Binary: Found at " << i2 << " in " << s2 << " steps\n";
        else cout << "Binary: Not found (" << s2 << " steps)\n";
    }
}
