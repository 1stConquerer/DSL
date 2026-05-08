#include<iostream>
using namespace std;

// ---------- Singly Linked List ----------
struct SNode {
    int data;
    SNode* next;
};
SNode* shead = NULL;

void insertBegS(int x) {
    SNode* n = new SNode;
    n->data = x;
    n->next = shead;
    shead = n;
}

void displayS() {
    SNode* t = shead;
    while(t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

// ---------- Doubly Linked List ----------
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};
DNode* dhead = NULL;

void insertBegD(int x) {
    DNode* n = new DNode;
    n->data = x;
    n->prev = NULL;
    n->next = dhead;

    if(dhead != NULL)
        dhead->prev = n;

    dhead = n;
}

void displayD() {
    DNode* t = dhead;
    while(t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}
int main() {
    int ch, type, val;

    while(true) {
        cout << "\n1 Singly InsertBeg";
        cout << "\n2 Singly Display";
        cout << "\n3 Doubly InsertBeg";
        cout << "\n4 Doubly Display";
        cout << "\n5 Exit\n";

        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBegS(val);
                break;

            case 2:
                displayS();
                break;

            case 3:
                cout << "Enter value: ";
                cin >> val;
                insertBegD(val);
                break;

            case 4:
                displayD();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
