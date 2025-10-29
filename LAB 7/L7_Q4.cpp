#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool available;
};

int partition(Product arr[], int low, int high) {
    double pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int SIZE = 3;
    Product products[SIZE];

    cout << "Enter details of 3 products:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nProduct " << i + 1 << " name: ";
        cin >> products[i].name;
        cout << "Price: ";
        cin >> products[i].price;
        cout << "Description (one word only): ";
        cin >> products[i].description;
        cout << "Available (1 for Yes, 0 for No): ";
        cin >> products[i].available;
    }

    quickSort(products, 0, SIZE - 1);

    cout << "\nProducts sorted by price\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Name: " << products[i].name << endl;
        cout << "Price: $" << products[i].price << endl;
        cout << "Description: " << products[i].description << endl;
        cout << "Available: " << (products[i].available ? "Yes" : "No") << endl;
    }

    return 0;
}
