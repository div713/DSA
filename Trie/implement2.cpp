#include <iostream>
using namespace std;

struct Node{
    Node* links[26];
    int ew = 0;
    int cp = 0;

    bool contains(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* n){
        links[ch-'a'] = n;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setprefix(){
        cp ++;
    }

    void setEnd(){
        ew++;
    }

    int getEnd(){
        return ew;
    }

    int getprefix(){
        return cp;
    }

    void decpre(){
        cp--;
    }

    void decend(){
        ew--;
    }
};

class Trie{
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(string s){
        Node* node = root;
        for(int i=0; i<s.length();i++){
            if(!node->contains(s[i])){
                node->put(s[i], new Node());
            }
            
            node = node->get(s[i]);
            node->setprefix();
        }
        node->setEnd();
    }

    int wordsEqualTo(string s){
        Node* node = root;

        for(int i=0; i<s.length(); i++){
            if(!node->contains(s[i])){
                return false;
            }

            node = node->get(s[i]);
        }

        return node->getEnd();
    }

    int startsWith(string s){
        Node* node = root;

        for(int i=0; i<s.length(); i++){
            if(!node->contains(s[i])){
                return false;
            }

            node = node->get(s[i]);
        }

        return node->getprefix();
    }

    void erase(string s){
        Node* node = root;

        for(int i=0; i<s.length(); i++){
            if(!node->contains(s[i])){
                return;
            }

            node = node->get(s[i]);
            node->decpre();
        }

        node->decend();
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("apple");
    cout << "Inserting strings 'apple' twice into Trie" << endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie.wordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.startsWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie.erase("apple");
    cout << "Count Words Equal to 'apple': ";
    cout << trie.wordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.startsWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie.erase("apple");
    cout << "Count Words Starting With 'app': ";
    cout << trie.startsWith("app") << endl;
    return 0;
}