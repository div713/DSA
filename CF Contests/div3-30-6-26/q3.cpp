#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        int tran = 0;

        for(int i=1; i<n; i++){
            if(s[i] != s[i-1]) tran++;
        }

        if(tran == 1){
            cout<<2<<endl;
        }
        else{
            cout<<1<<endl;
        }

    }
    return 0;
}