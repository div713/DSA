#include <iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* child;
    ListNode* next;

    ListNode(){
        val = 0;
        child = NULL;
        next = NULL;
    }
    ListNode(int val){
        this->val = val;
        child = NULL;
        next = NULL;
    }
    ListNode(int val, ListNode* next){
        this->val = val;
        this->child = NULL;
        this->next = next;
    }
    ListNode(int val, ListNode* next, ListNode* child){
        this->val = val;
        this->child = child;
        this->next = next;
    }    
};

ListNode* merge(ListNode* l1, ListNode* l2){
        
    ListNode* ans = new ListNode(0);
    ListNode* dummy = ans;

    while(l1 && l2){
        if(l1->val < l2->val){
            // ListNode* nn = new ListNode(l1->val);
            ans->child = l1;
            l1 = l1->child;
        }
        else{
            // ListNode* nn = new ListNode(l2->val);
            ans->child = l2;
            l2 = l2->child;
        }
        ans = ans->child;
    }

    while(l1){
        // ListNode* nn = new ListNode(l1->val);
        ans->child = l1;
        l1 = l1->child;
        ans = ans->child;
    }

    while(l2){
        // ListNode* nn = new ListNode(l2->val);
        ans->child = l2;
        l2 = l2->child;
        ans = ans->child;
    }
    ans->child = NULL;
    return dummy->child;
}

ListNode* flatten(ListNode* node){
        
    if(!node || !node->next) return node;

    ListNode* l2 = flatten(node->next);

    node = merge(node,l2);

    return node;
}

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

int main(){
    ListNode* head = new ListNode(5);
    head->child = new ListNode(14);

    head->next = new ListNode(10);
    head->next->child = new ListNode(90);

    head->next->next = new ListNode(12);
    head->next->next->child = new ListNode(13);
    head->next->next->child->child = new ListNode(13);

    head->next->next->next = new ListNode(7);
    head->next->next->next->child = new ListNode(17);

    ListNode* sol = flatten(head);

    printLinkedList(head);

    return 0;
}