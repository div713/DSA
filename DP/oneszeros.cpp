#include <iostream>

using namespace std;

int rec(vector<string>& strs, int m, int n, int idx, int curr0, int curr1,int currans){
        if(idx == strs.size()){
            return currans;
        }
        string s= strs[idx];

        int zero= count(s.begin(), s.end(),'0');
        int one= count(s.begin(), s.end(),'1');

        if(zero + curr0 > m || one + curr1 > n){
            return currans;
        }

        int ans=0;
        
        int ret= rec(strs,m,n,idx+1,curr0+ zero, curr1+ one, currans+1);
        int ret2= rec(strs,m,n,idx+1,curr0,curr1,currans);
        
        ans=  max(ret,ret2);
        
        return ans;
    }

int TD(vector<string>& strs, int m, int n, int idx, int curr0, int curr1, vector<vector<vector<int>>>& dp){
        if(idx == strs.size()){
            return 0;
        }
        if(curr0 > m || curr1 > n){
            return -1e9;
        }

        if(dp[idx][curr0][curr1] != -1){
            return dp[idx][curr0][curr1];
        }

        string s= strs[idx];

        int zero= count(s.begin(), s.end(),'0');
        int one= count(s.begin(), s.end(),'1');
        
        int ret= -1;
            
        if(zero + curr0 <= m && one + curr1 <=n){
            ret= 1 + TD(strs,m,n,idx+1,curr0+ zero, curr1+ one,dp);
        }
        int ret2= TD(strs,m,n,idx+1,curr0,curr1,dp);

        dp[idx][curr0][curr1] = max(ret,ret2);
        return max(ret,ret2);
    }

int main(){
    int m = 3;
    int n = 8;
    vector<string> strs = {"100", "111", "101"};
    vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

    int ans = rec(strs,m,n,0,0,0,0);

    cout<<ans<<endl;

    return 0;
}