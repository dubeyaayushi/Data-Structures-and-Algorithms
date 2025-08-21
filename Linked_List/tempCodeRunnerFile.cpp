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