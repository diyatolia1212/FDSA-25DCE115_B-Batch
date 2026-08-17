#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements (only 0, 1, and 2): ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Selection Sort
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
    cout << "\nSorted Array: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
