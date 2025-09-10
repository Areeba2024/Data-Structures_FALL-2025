#include <iostream>
using namespace std;

const int n = 5;
bool friends[n][n] = {
    { false, true,  false, true,  true },
    { true,  false, true,  false, true  },
    { false, true,  false, false, false },
    { true,  false, false, false, true  },
    { true, true,  false, true,  false }
};

bool commonFriend(int a, int b) {
    for (int i = 0; i < n; i++) {
        if (friends[a][i] && friends[b][i]) {
            return true;
        }
    }
    return false;
}

int main() {
    cout << "Friends Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (friends[i][j] ? " * " : " X ");
        }
        cout << endl;
    }

    int p1, p2;
    cout << "\nEnter two people (0-4) to check common friend: ";
    cin >> p1 >> p2;

    if (commonFriend(p1, p2)) {
        cout << "Yes, " << p1 << " and " << p2 
             << " have a common friend.\n";
    } else {
        cout << "No, " << p1 << " and " << p2 
             << " do not have any common friends.\n";
    }

    return 0;
}
