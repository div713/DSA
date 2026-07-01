#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        string s;
        bool isone = false;

        for(int i=0; i<n; i++){
            char c;
            cin>>c;
            s += c;
            if(c == '1') isone = true;
        }

        if(n == k && isone){
            cout<<"NO"<<endl;
            continue;
        }

        bool ans = true;

        vector<bool> vis(n,false);

        for(int i=0; i<n; i++){
            if(vis[i]){
                continue;
            }
            
            int ones = 0;
            if(s[i] == '1') ones++;
            vis[i] = true;

            for(int j=i; j<n-k; j=j+k){
                if(vis[j+k]){
                    continue;
                }

                vis[j+k] = true;

                if(s[j+k] == '1') ones++;
            }

            if(ones&1){
                ans = false;
                break;
            }
        }

        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}