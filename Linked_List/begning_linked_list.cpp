// The user creates a linked list (by entering the number of nodes and their values).

// Now you want to ask the user if they want to insert at the beginning.

// If yes → take value → insert at beginning → print updated list.



#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void printList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    
}
}

void insertAtBeginning(Node*& head, int value){
     Node* newNode = new Node();  // create new node
    newNode->data = value;
    newNode->next = head;        // link new node to current head
    head = newNode; 
}



int main (){
    int n , value;
     
    cout<<"enter the how many nodes you want to create"<<endl;
    cin>>n;
     
    cout<<"enter the value for 1st node";
    cin>>value;
    Node* head = new Node();
    head->data= value;
    head->next = NULL;

    Node* temp = head;

    //creating remaning nodes
    for(int i =2; i<=n; i++){
       cout << "Enter data for node " << i << ": ";
        cin >> value;

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;

    }

    
    cout << "\nOriginal Linked List: ";
    printList(head);

     char choice;
    cout << "\nDo you want to insert at the beginning? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Enter value to insert at beginning: ";
        cin >> value;
        insertAtBeginning(head, value);

        cout << "Updated Linked List: ";
        printList(head);
    }

    return 0;

    
}






