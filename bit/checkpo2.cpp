#include <iostream>
using namespace std;

bool pow2(int num){
    if((num & (num-1)) == 0){
        return true;
    }else{
        return false;
    }
}


int main(){
    cout<<pow2(32)<<endl;
    cout<<pow2(20)<<endl;

    return 0;
}