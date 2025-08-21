// Ask the user if they want to insert at a specific position.

// If yes, ask for the value and the position.

// Insert the node correctly at that position.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void printList(Node* head){
    Node* temp = head;
    while(temp!= NULL){

        cout<<temp->data<<" ";
        temp = temp->next;

    }
}


void insertAtPosition(Node*& head, int value, int position){
    Node* newNode = new Node();
    newNode->data= value;

    if(position ==1){
        newNode->next = head;
        head = newNode;
        return;
    }


    Node* temp = head;
    for(int i =1; i< position-1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp==NULL){
        cout<<"Position is out of bounds"<<endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;


}

int main(){
    int n, value;
    cout<<"Enter the number of nodes you want to insert"<<endl;
    cin>>n;

    cout<<"enter the value of the 1st node"<<endl;
    cin>>value;

    Node* head = new Node();
    head->data = value;
    head->next = NULL;

    Node* temp = head;
    for(int i = 2; i<n; i++){
        cout << "Enter data for node " << i << ": ";
        cin >> value;
         Node* newNode = new Node();
         newNode->data = value;
         newNode->next = NULL;
         temp-> next = newNode;
         temp= newNode;
    }

     cout << "\nOriginal Linked List: ";
    printList(head);

    // Ask user if they want to insert at a position
    char choice;
    cout << "\nDo you want to insert at a certain position? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int pos;
        cout << "Enter value to insert: ";
        cin >> value;
        cout << "Enter position (1-based index): ";
        cin >> pos;

        insertAtPosition(head, value, pos);

        cout << "Updated Linked List: ";
        printList(head);
    }

    return 0;

}
















