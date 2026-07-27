#include<iostream>
using namespace std;
int linearSearchRecursive(int arr[], int size, int target, int index = 0)
{
    if (index >= size)
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }
    return linearSearchRecursive(arr, size, target, index + 1);
}
int main()
{
    int car[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target;
    cout<<"enter target: ";
    cin>>target;
    int found=0;
    cout<<"using linear search"<<endl;
    for(int i=0;i<10;i++)
    {
        if(car[i] == target)
        {
            found = 1;
            cout<<"car found at "<<i+1<<" position";
            break;
        }
    }

    if(found == 0)
    {
        cout<<"car not found";
    }
    cout<<endl<<"using recoursive"<<endl;
    int resultIndex = linearSearchRecursive(car, 10, target);
    if (resultIndex != -1)
    {
        cout << "car found at " << resultIndex + 1 << " position" << endl;
    }
    else
    {
        cout << "car not found" << endl;
    }
}
