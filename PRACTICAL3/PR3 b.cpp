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
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while(mid <= high)
    {
        if(a[mid] == 0)
        {
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else if(a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
    cout << "\nSorted Array: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
