#include <iostream>

using namespace std;

void cmbnSum(vector<int>& nums, int target, int idx, int currsum,int &ways ,vector<int> &strg){
        if(currsum == target){
            ways++;
            return;
        }
        if(currsum > target){
            return;
        }
        if(nums[idx] > target){
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            cmbnSum(nums,target,idx,currsum + nums[i],ways,strg);
        }
}

int main(){
    vector<int> nums= {7,350};
    int target= 700;
    int ways=0;
    vector<int> strg(nums.size(),0);

    cmbnSum(nums,target,0,0,ways,strg);

    cout<<ways;
    return 0;
}