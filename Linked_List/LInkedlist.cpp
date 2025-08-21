#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Linked list cannot be created!" << endl;
        return 0;
    }

    // create head node
    cout << "Enter data for node 1: ";
    cin >> value;
    Node* head = new Node();
    head->data = value;
    head->next = NULL;

    Node* temp = head;

    // create remaining nodes
    for (int i = 2; i <= n; i++) {
        cout << "Enter data for node " << i << ": ";
        cin >> value;

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        temp->next = newNode; // link new node
        temp = newNode;       // move temp to last node
    }

    // print linked list
    cout << "Linked List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}





