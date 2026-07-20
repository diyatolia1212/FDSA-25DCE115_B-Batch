#include <iostream>
using namespace std;

int main() {
    int n;
    string word, longest = "";
    cout << "Enter number of words: ";
    cin >> n;
    cout << "Enter words: ";
    for (int i = 0; i < n; i++) {
        cin >> word;
    if (word.length() > longest.length()) {
            longest = word;
        }
    }
    cout << "Longest word: " << longest << endl;
    cout << "Length: " << longest.length();
    return 0;
}
