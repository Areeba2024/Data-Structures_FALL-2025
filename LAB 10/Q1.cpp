#include <iostream>
using namespace std;

class minHeap {
public:
    int heap[50];
    int size;

    minHeap() {
        size = 0;
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2*i + 1; }
    int right(int i)  { return 2*i + 2; }

    void heapify_up(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify_down(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] < heap[smallest])
            smallest = l;
        if (r < size && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify_down(smallest);
        }
    }

    void insert(int val) {
        heap[size] = val;
        heapify_up(size);
        size++;
    }

    void update_key(int i, int new_val) {
        if (i < 0 || i >= size) return;
        int old = heap[i];
        heap[i] = new_val;

        if (new_val < old)
            heapify_up(i);
        else
            heapify_down(i);
    }

    void delete_index(int i) {
        if (i < 0 || i >= size) return;
        heap[i] = heap[size - 1];
        size--;
        heapify_down(i);
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    minHeap H;
    int arr[] = {8, 7, 6, 5, 4};
    for (int x : arr)
        H.insert(x);
    H.print();
    H.update_key(2, 1);
    H.print();
    H.delete_index(1);
    H.print();
}
