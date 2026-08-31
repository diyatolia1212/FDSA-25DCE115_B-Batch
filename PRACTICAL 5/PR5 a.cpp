#include <iostream>
using namespace std;
struct Node {
    string song;
    Node *prev, *next;
};
Node *head = NULL, *tail = NULL;
void begin(string s) {
    Node *n = new Node{s, NULL, head};
    if (head == NULL)
        head = tail = n;
    else {
        head->prev = n;
        head = n;
    }
}
void end(string s) {
    Node *n = new Node{s, tail, NULL};
    if (head == NULL)
        head = tail = n;
    else {
        tail->next = n;
        tail = n;
    }
}
void after(string oldS, string newS) {
    Node *t = head;
    while (t != NULL && t->song != oldS)
        t = t->next;
    if (t == NULL) {
        cout << "Song not found!\n";
        return;
    }
    Node *n = new Node{newS, t, t->next};
    if (t->next != NULL)
        t->next->prev = n;
    else
        tail = n;
    t->next = n;
}
void removeFirst() {
    if (head == NULL) return;
    Node *t = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;
    delete t;
}
void display() {
    Node *t = head;
    int count = 0;
    while (t != NULL) {
        cout << t->song << " ";
        count++;
        t = t->next;
    }
    cout << "\nCount = " << count << endl;
}
int main() {
    int ch;
    string s, oldS;
    do {
        cout << "\n1.Begin  2.End  3.After  4.Remove  5.Display  6.Exit\n";
        cin >> ch;
        switch(ch) {
        case 1:
            cin >> s;
            begin(s);
            break;
        case 2:
            cin >> s;
            end(s);
            break;
        case 3:
            cin >> oldS >> s;
            after(oldS, s);
            break;
        case 4:
            removeFirst();
            break;
        case 5:
            display();
            break;
        }
    } while(ch != 6);
    return 0;
}
