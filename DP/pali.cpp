#include <iostream>
using namespace std;

bool **palindrome(string s){
    int n= s.length();
    bool **palindrome= new bool*[n];

    for(int i=0; i<n; i++){
        palindrome[i]= new bool[n];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            palindrome[i][j]= true;
        }
    }


        for(int i=n-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(j==i){
                    break;
                }
                if(s[i] == s[j]){
                    palindrome[i][j]= palindrome[i+1][j-1];
                }
                else{
                    palindrome[i][j]= false;
                }
            }
        }

        return palindrome;
}