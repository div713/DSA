#include <iostream>
#include <string>
using namespace std;

bool stringSwap(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }

    int n= s1.length();

    int diff=0;
    char ch;

    for(int i=0; i<n; i++){
        if(s1[i] != s2[i]){
            if(diff > 0 && ch != s2[i]){
                return false;
            }
            ch = s1[i];
            diff ++;
            if(diff > 2) return false;

        }
    }
    return true;
}

int main(){
    string s1,s2;

    cin>>s1;
    cin>>s2;

    cout<<stringSwap(s1,s2);
    return 0;
}