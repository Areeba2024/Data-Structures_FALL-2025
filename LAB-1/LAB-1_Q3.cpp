#include <iostream>
using namespace std;

class ShallowBox {
    int* length;
    int* width;
    int* height;

public:
    ShallowBox(int l, int w, int h) {
        length = new int(l);
        width  = new int(w);
        height = new int(h);
    }

    void setLength(int l) {
	 *length = l; 
	 }

    void display() {
        cout << "Length: " << *length << ", "<< "Width: " << *width << ", "<< "Height: " << *height << endl;
    }
};

class DeepBox {
    int* length;
    int* width;
    int* height;

public:
    DeepBox(int l, int w, int h) {
        length = new int(l);
        width  = new int(w);
        height = new int(h);
    }

    DeepBox(const DeepBox& obj) {
        length = new int(*obj.length);
        width  = new int(*obj.width);
        height = new int(*obj.height);
    }

    DeepBox& operator=(const DeepBox& obj) {
        if (this != &obj) {
            delete length;
            delete width;
            delete height;

            length = new int(*obj.length);
            width  = new int(*obj.width);
            height = new int(*obj.height);
        }
        return *this;
    }

    void setLength(int l) { 
	*length = l; 
	}

    void display() {
        cout << "Length: " << *length << ", "<< "Width: " << *width << ", "<< "Height: " << *height << endl;
    }

    ~DeepBox() {
        delete length;
        delete width;
        delete height;
    }
};

int main() {
    ShallowBox sb1(10, 20, 30);
    ShallowBox sb2 = sb1;  
    cout << "Before:" << endl;
    cout << "Shallow Box 1: "; sb1.display();
    cout << "Shallow Box 2: "; sb2.display();

    sb2.setLength(99);  

    cout << "After modifying sb2:" << endl;
    cout << "Shallow Box 1: "; sb1.display();
    cout << "Shallow Box 2: "; sb2.display();

    cout << "\n";
    DeepBox db1(10, 20, 30);
    DeepBox db2 = db1;  
    cout << "Before:" << endl;
    cout << "Deep Box 1: "; db1.display();
    cout << "Deep Box 2: "; db2.display();

    db2.setLength(99);  

    cout << "After modifying db2:" << endl;
    cout << "Deep Box 1: "; db1.display();
    cout << "Deep Box 2: "; db2.display();

    return 0;
}
