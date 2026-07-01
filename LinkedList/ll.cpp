#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int x){
        data = x;
        next = NULL;
    }

    Node(int x, Node* n){
        data = x;
        next = n;
    }

    ~Node(){
        if(next){
            delete next;
            next = NULL;
        }
    }
};

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head = NULL;
        tail = NULL;
    }
    List(Node* h){
        head = h;
        
        while(h->next){
            h = h-> next;
        }

        tail = h;
    }
    void push_front(int x){
        Node* nn = new Node(x,NULL);

        if(head == NULL){
            tail = nn;
        }
        else{
            nn->next = head;
        }
        head = nn;
    }

    void push_back(int x){
        Node* nn= new Node(x,NULL);

        if(head == NULL){
            head = nn;
            tail = nn;
            return;
        }

        tail->next = nn;
        tail = nn;
    }

    void pop_front(){
        if(!head){
            return;
        }
        
        Node* temp = head;
        head = head->next;
        if(!head){
            tail = NULL;
        }

        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;

        if(!temp || !temp->next){
            head = NULL;
            tail = NULL;
            delete temp;
            return;
        }

        while(temp->next->next != NULL){
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
        tail = temp;
    }

    ~List(){
        if(head){
            delete head;
            head = NULL;
        }
    }

};