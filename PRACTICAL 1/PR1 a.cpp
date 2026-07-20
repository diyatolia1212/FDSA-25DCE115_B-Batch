#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    int items[n];
    cout << "Enter items: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }
    int h;
    cout << "Enter hours: ";
    cin >> h;
    int rotations = h % n;
    cout << "Final display order: ";
    for (int i = 0; i < n; i++) {
        cout << items[(i + rotations) % n] << " ";
    }

    return 0;
}
