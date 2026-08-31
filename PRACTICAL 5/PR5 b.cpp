#include <iostream>
using namespace std;

struct Node {
    string name;
    Node *prev, *next;
};

Node *head = NULL, *tail = NULL;

void join(string name) {
    Node *n = new Node{name, tail, NULL};

    if (head == NULL)
        head = tail = n;
    else {
        tail->next = n;
        tail = n;
    }
}

void leave(string name) {
    Node *t = head;

    while (t != NULL && t->name != name)
        t = t->next;

    if (t == NULL) {
        cout << "Student not found!\n";
        return;
    }

    if (t->prev != NULL)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next != NULL)
        t->next->prev = t->prev;
    else
        tail = t->prev;

    delete t;
}

void display() {
    Node *t = head;

    while (t != NULL) {
        cout << t->name << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int ch;
    string name;

    do {
        cout << "\n1.Join  2.Leave  3.Display  4.Exit\n";
        cin >> ch;

        if (ch == 1) {
            cin >> name;
            join(name);
        }
        else if (ch == 2) {
            cin >> name;
            leave(name);
        }
        else if (ch == 3)
            display();

    } while (ch != 4);

    return 0;
}
