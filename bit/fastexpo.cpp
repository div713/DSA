#include <iostream>
using namespace std;

int fastexpo(int x, int n){
    int ans = 1;
    
    while(n){
        int bit = n & 1;
        if(bit > 0){
            ans = ans * x;
        }
        x= x*x;
        n= n>>1;
    }
    return ans;
}

int main(){
    cout<< fastexpo(4,4)<<endl;
    return 0;
}