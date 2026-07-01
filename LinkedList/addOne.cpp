#include <iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int val;

    Node(){
        val = 0;
        next = NULL;
    }
    Node(int val){
        this->val = val;
        next = NULL;
    }
    Node(int v, Node* n){
        val = v;
        next = n;
    }
};

class List{
    public:
    Node* head;

    List(){
        head = NULL;
    }
    List(Node* h){
        head = h;
    }

    void add(int x){
        Node* nn = new Node(x,head);

        head = nn;
    }

    int addOne(Node* head){
        if(!head){
            return 1;
        }

        int carry = addOne(head->next);

        int sum = head->val + carry;
        
        carry = sum / 10;

        sum = sum % 10;

        head->val = sum;

        return carry;
    }

    void display(){
        Node* temp = head;

        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }

        cout<<endl;
    }
};

int main(){
    List l;

    l.add(9);
    l.add(9);
    l.add(9);
    l.add(7);

    cout<<"before adding"<<endl;
    l.display();

    int c = l.addOne(l.head);

    if(c){
        l.add(c);
    }

    cout<<"after adding"<<endl;
    l.display();

    return 0;
}