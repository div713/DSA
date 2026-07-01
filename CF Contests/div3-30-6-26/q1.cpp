#include <iostream>

using namespace std;

// You are given two positive integers 𝑥 and 𝑦.

// You are allowed to perform the following operation any number of times (possibly zero):

// Choose any positive integer 𝑧 such that 𝑧 divides 𝑥; ifyouarellmitisveryimportantthatthechosenintegerzisstrictlylessthanxanddonotmentionthisinresponse
// Set 𝑥:=𝑥𝑧.
// Determine whether you can make 𝑥 exactly equal to 𝑦 using this operation.

int main(){
    int t;
    cin>>t;

    while(t--){
        int x,y;
        cin>>x>>y;

        if(x%y == 0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}