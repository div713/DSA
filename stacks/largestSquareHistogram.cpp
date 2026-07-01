#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//for largest square in histogram
int largestSquareArea(vector<int>& heights) {
    int n = heights.size();

    stack<int> st;
    int maxArea = 1;

    for(int i=0; i<n; i++){
        while(!st.empty() && heights[i] < heights[st.top()]){
            int idx = st.top();
            st.pop();

            int pse = -1;
            if(!st.empty()) pse = st.top();

            int area = 1;

            if(i-pse-1 <= heights[idx]){
                area = (i-pse - 1)*(i-pse-1);
            }
            else{
                area = heights[idx]*heights[idx];
            }
            
            maxArea = max(area,maxArea);
        }
        st.push(i);
    }

    while(!st.empty()){
        int idx = st.top();
        st.pop();

        int pse = -1;
        if(!st.empty()) pse = st.top();

        int area = 1;
        if(n-pse-1 <= heights[idx]){
            area = (n-pse-1)*(n-pse-1);
        }
        else{
            area = heights[idx]*heights[idx];
        }
        maxArea = max(area,maxArea);
    }

    return maxArea;
}

int main(){
    vector<int> arr = {1,2,3,2,1};

    cout<<largestSquareArea(arr)<<endl;

    return 0;
}