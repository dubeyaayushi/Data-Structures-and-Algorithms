#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data; 
    Node* next;
};


void Addinglist(Node*& head1, Node*& head2){
    Node* temp = new Node();

    temp = head1;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = head2; // link the second list to the end of the first list

    Node* temp2 = new Node();
    temp2 = head1;
    while(temp2 != NULL){
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }



}

int main(){
    int n, value;

    cout<<"ENter the value of nodes you want to insert";
    cin>>n;

    cout<<"enter the value of first node"<<endl;
    cin>>value;

    Node* head1 = new Node();
    head1->data = value;
    head1->next = NULL;

    Node* temp1 = head1;
    for(int i=2; i<n; i++){
        cout<<"Enter the value of node"<<i<<endl;
        cin>>value;
        Node* newNode = new Node();
        newNode->data = value;
        temp1->next = newNode;
        temp1 = newNode;
        newNode->next = NULL;
    }

    int n2, value2;
    cout<<"Enter the number of nodes you want to insert in 2nd list"<<endl;
    cin>>n2;

    cout<<"Enter the value of first node of 2nd list"<<endl;
    cin>>value2;

    Node* head2 = new Node();
    head2->data= value2;
    head2->next = NULL;

    Node* temp2 = head2;
    for(int i=2; i<n2; i++){
        cout<<"Enter the value of node"<<i<<endl;
        cin>>value2;
        Node* newNode = new Node();
        newNode->data = value2;
        temp2->next = newNode;
        temp2 = newNode;
        newNode->next = NULL;
    }

    cout<<"Adding of two Linked List is: ";
    Addinglist(head1, head2);

}

