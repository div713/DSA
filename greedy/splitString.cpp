#include <iostream>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int balance = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == 'L') balance ++;
            else{
                balance --;
            }

            if(balance == 0) ans ++;
        }
        return ans;
    }
};

int main(){
    string s;
    cin>>s;
    
    Solution sol;

    int ans = sol.balancedStringSplit(s);

    cout<< ans << endl;
    return 0;
}