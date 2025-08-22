#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

 void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
 }

 void getSize(Node* head){
    Node* temp = head;
    int count = 1 ;
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    cout << "Size of linked list: " << count << endl;
}


int main(){
    int n, value;

    cout<<"enter the number of nodes you want to insert"<<endl;
    cin>>n;

    Node*head = new Node();


    cout<<"enter the value for first node"<<endl;
    cin>> value;

    head->data = value;
    head->next = NULL;


    Node* temp = new Node();
    temp = head;
    for(int i = 2; i<=n; i++){
        Node* newNode = new Node();
        cout<<"enter the value of node"<<i<<endl;
        cin>>value;
        newNode->data= value;
        newNode->next = NULL;
        temp->next= newNode;
        temp = newNode;
    }

    printList(head);

    getSize(head);



}




