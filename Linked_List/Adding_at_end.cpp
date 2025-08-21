#include<bits/stdc++.h>
using namespace std;



struct Node{
    int data;
    Node* next;
};

void printlist(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n, value;
    cout<<"Enter the value of number of nodes you want to insert"<<endl;
    cin>>n;

    cout<<"Enter the value of the 1st node"<<endl;
    cin>>value;

    Node* head = new Node();
    head->data= value;
    head->next = NULL;

    Node* temp = head;
    for(int i =2; i<n; i++){
        cout<<"enter the value of node"<<i<<endl;
        cin>>value;
        Node* newNode = new Node();
        newNode->data = value;
        temp->next = newNode;
        temp = newNode;
    }
 
    cout<<"Linked list is"<<endl;
    printlist(head);

    char choice;
    cout<<"Do you want to add a node at the end? (y/n)"<<endl;
    cin>>choice;

    if(choice == 'y' || 'Y'){
        cout<<"Enter the value you want to insert at the end"<<endl;
        cin>>value;

        Node* newNode= new Node();
        newNode-> data = value;
        newNode->next = NULL;

        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        cout<<"\nUpdated Linked List";
        printlist(head);
    }

}