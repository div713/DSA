#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

int ans = 0;

bool isGood(long long x){
    vector<int> freq(10,0);
    int distinct = 0;
    while(x){
        int dig = x%10;
 
        if(freq[dig] == 0){
            distinct++;
        }
 
        if(distinct > 2) return false;
 
        freq[dig]++;
 
        x/=10;
    }
    return distinct <= 2;
}

void dfs(long long cur, int len, int d1, int d2,vector<long long> &good) {
    if (len > 10) return;

    if (cur >= 2 && cur <= 1000000000)
        good.push_back(cur);

    if (len == 10) return;

    if (!(cur == 0 && d1 == 0))
        dfs(cur * 10 + d1, len + 1, d1, d2,good);

    if (d2 != d1 && !(cur == 0 && d2 == 0))
        dfs(cur * 10 + d2, len + 1, d1, d2,good);
}



int main(){
    int t;
    cin>>t;

    vector<long long> good;
    for (int d = 1; d <= 9; d++)
        dfs(0, 0, d, d, good);

    for(int f = 0; f <= 9; f++){
        for(int s = f+1; s<=9; s++){
            if(f == 0 && s == 0) continue;
            dfs(0, 0, f, s,good);
            dfs(0,0,s,f,good);
        }
    }

    sort(good.begin(), good.end());
    good.erase(unique(good.begin(), good.end()), good.end());

    while(t--){
        int x;
        cin>>x;

        for(int i=0; i<good.size(); i++){
            if(isGood(1LL*x*good[i])){
                cout<<good[i]<<endl;
                break;
            }
        }

    }
    return 0;
}