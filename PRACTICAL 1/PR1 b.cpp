#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of borrow records: ";
    cin >> n;
    int a[n];
    cout << "Enter book IDs: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Books borrowed more than once: ";
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(a[i] == a[j]) {
                count++;
            }
        }
        int prev = 0;
        for(int k = 0; k < i; k++) {
            if(a[k] == a[i]) {
                prev++;
            }
        }
        if(count > 1 && prev == 0) {
            cout << a[i] << " ";
        }
    }
    return 0;
}
