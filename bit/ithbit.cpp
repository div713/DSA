#include <iostream>

using namespace std;

int getithbit(int num, int i){
    if((num & (1<<i)) > 0 ){
        return 1;
    }else{
        return 0;
    }
}

int setithbit(int num, int i){
    return (num | (1<<i));
}

int clearithbit(int num, int i){
    return (num & (~(1<<i)));
}

int updateithbit(int num, int i, int val){
    num = num & ~(1<<i);

    num = num | (val << i);

    return num;
}

int clearlastibits(int num, int i){
    return num & ~((1<<i)-1);
}

int countSetBits(int num){
    int ans = 0;
    while(num){
        ans += num & 1;
        num = num >> 1;
    }
    return ans;
}

int main(){
    // cout<<getithbit(6,1)<<endl;

    // cout<<setithbit(8,4)<<endl;

    // cout<<clearithbit(6,1)<<endl;

    // cout<<updateithbit(7,3,1)<<endl;

    // cout<<clearlastibits(15,4)<<endl;

    cout<<countSetBits(15)<<endl;

    return 0;
}