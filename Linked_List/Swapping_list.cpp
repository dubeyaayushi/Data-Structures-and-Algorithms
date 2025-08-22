// A struct (short for structure) is a user-defined data type that lets you group different variables (possibly of different types) under one name.


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

 void printList(Node* head1){
    Node* temp1 = head1;
    while(temp1 != NULL){
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    cout << endl;
 }


 
void swapping(Node* head1 , Node* head2) {
      Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        // Swap data
        int t = temp1->data;
        temp1->data = temp2->data;
        temp2->data = t;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

int main() {
    int n,m, value1, value2;
    cout << "Enter number of nodes for fisrt list : ";
    cin >> n;

    cout << "Enter number of nodes for second list : ";
    cin >> m;

    if (n <= 0) {
        cout << "Linked list cannot be created!" << endl;
        return 0;
    }

    // create head node
    cout << "Enter data for node 1of first list: ";
    cin >> value1;
    Node* head1 = new Node();
    head1->data = value1;
    head1->next = NULL;

    cout << "Enter data for node 1 of second list : ";
    cin >> value2;
    Node* head2 = new Node();
    head2->data = value2;
    head2->next = NULL;


     Node* temp1 = head1;

    Node* temp2 = head2;

    // create remaining nodes
    for (int i = 2; i <= n; i++) {
        cout << "Enter data for node of first list " << i << ": ";
        cin >> value1;

        Node* newNode = new Node();
        newNode->data = value1;
        newNode->next = NULL;

        temp1->next = newNode; // link new node
        temp1 = newNode;       // move temp to last node
    }


    cout<<endl;

      for (int i = 2; i <= m; i++) {
        cout << "Enter data for node of second list " << i << ": ";
        cin >> value2;

        Node* newNode = new Node();
        newNode->data = value2;
        newNode->next = NULL;

        temp2->next = newNode; // link new node
        temp2 = newNode;       // move temp to last node
    }



    cout << "\nOriginal List 1: ";
    printList(head1);

    cout << "Original List 2: ";
    printList(head2);

    swapping(head1, head2);
   
    cout << "\nAfter Swapping:\n";
    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    return 0;

}





