#include<iostream>
using namespace std;
int binarySearchRecursive(int a[], int start, int end1, int target)
{
    if(start > end1)
        return -1;

    int mid = (start + end1) / 2;

    if(a[mid] == target)
        return mid;

    if(a[mid] < target)
        return binarySearchRecursive(a, mid + 1, end1, target);

    return binarySearchRecursive(a, start, mid - 1, target);
}
int main()
{
    int a[10] = {101,102,103,104,105,106,107,108,109,110};
    int target = 111;
    int start = 0;
    int end1 = 9;
    cout << "Using Binary Search" << endl;
    while(start <= end1)
    {
        int mid = (start + end1) / 2;

        if(a[mid] == target)
        {
            cout << "Found at position: " << mid + 1 << endl;
            break;
        }else if(a[mid] < target)
        {
            start = mid + 1;
        }else
        {
            end1 = mid - 1;
        }
    }
    if(start > end1)
    {
        cout << "Not Found" << endl;
    }
    cout << endl << "Using Recursive Binary Search" << endl;
    int result = binarySearchRecursive(a, 0, 9, target);
    if(result != -1)
        cout << "Found at position: " << result + 1 << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}
