#include <iostream>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;

    bool contain(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }

    ~Node() {
        for (int i = 0; i < 26; i++) {
            if (links[i] != nullptr) {
                delete links[i];
                links[i] = nullptr;
            }
        }
    }
};


class Solution{
    public:
    int distinctSub(string &s){
        Node* root = new Node();

        int n = s.length();
        int cnt = 0;

        for(int i=0; i<n; i++){
            Node* node = root;
            for(int j=i; j<n; j++){
                if(!node->contain(s[j])){
                    node->put(s[j], new Node());
                    cnt++;
                }
                node = node->get(s[j]);
            }
        }
        return cnt+1;
    }
};


int main(){
    Solution sol;

    string s = "divyam";  
    cout << "Current String: " << s << endl;

    // Input string
    cout << "Number of distinct substrings: " << sol.distinctSub(s)<< endl;  
    return 0;  
}