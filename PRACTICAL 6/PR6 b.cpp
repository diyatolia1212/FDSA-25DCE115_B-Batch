#include <iostream>
using namespace std;
struct Node
{
    string page;
    Node* next;
};
Node* top = NULL;
void visit(string page)
{
    Node* newNode = new Node;
    newNode->page = page;
    newNode->next = top;
    top = newNode;
    cout << "Current Page: " << top->page << endl;
}
void back()
{
    if (top == NULL)
    {
        cout << "No history left. Cannot go back." << endl;
    }
    else
    {
        cout << "Going back from: " << top->page << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
        if (top == NULL)
            cout << "No page left." << endl;
        else
            cout << "Current Page: " << top->page << endl;
    }
}
int main()
{
    int choice;
    string page;
    while (1)
    {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter page name: ";
            cin >> page;
            visit(page);
        }
        else if (choice == 2)
        {
            back();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
