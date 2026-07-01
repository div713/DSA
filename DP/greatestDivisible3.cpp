//Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.
#include <iostream>
using namespace std;

class Solution {
public:
    int rec(vector<int>& nums, int currsum,int idx, int **dp){
        if(idx == nums.size()){
            return currsum;
        }

        if(dp[currsum][idx] != -1){
            return dp[currsum][idx];
        }
        
        int ans= -1;

        int ans1= rec(nums,currsum + nums[idx], idx + 1,dp);
        int ans2= rec(nums, currsum, idx+ 1,dp);

        if(ans1 % 3 == 0 && ans2 % 3 == 0){
            ans= max(ans1,ans2);
        }
        else if(ans1 % 3 == 0){
            ans= ans1;
        }
        else if(ans2 % 3 == 0){
            ans= ans2;
        }
        else{
            ans= 0;
        }

        dp[currsum][idx] = ans;
        return ans;
    }
    int maxSumDivThree(vector<int>& nums) {
        int s=0;
        for(int i=0; i<nums.size(); i++){
            s+= nums[i];
        }

        int **dp= new int *[s+1];
        for(int i=0; i<= s; i++){
            dp[i]= new int[nums.size()];

            for(int j=0; j<nums.size(); j++){
                dp[i][j] = -1;
            }
        }

        return rec(nums,0,0,dp);

    }
};