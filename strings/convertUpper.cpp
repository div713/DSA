#include <iostream>
using namespace std;

void toUpper( char str[] , int n){
    for(int i=0; i<n; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

int main(){
    
    char word[] = "apple";
   

    toUpper(word,strlen(word));

    cout<<word;
    return 0;
}