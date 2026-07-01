#include <iostream>

using namespace std;

    int ways(string s, int idx,vector<int> &strg){
        
        if(idx == s.length()){
            return 1;
        }

        if(strg[idx] != -1){
            return strg[idx];
        }
        if(s[idx]== '0'){
            strg[idx]=0;
            return 0;
        }

        int w= ways(s,idx+1,strg);

        if(idx + 1< s.length() && (s[idx]== '1' || (s[idx]=='2' && s[idx+1] <= '6'))){
            w+= ways(s,idx+2,strg);
        }
        
        strg[idx]=w;
        return w;
    }
    int main() {
        string s= "122341";
        int n= s.length();
        vector<int> strg(n,-1);
        ways(s,0,strg);
        cout<<strg[0];
        return 0;
    }