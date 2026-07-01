// Maxim and Nikita are working together on a project consisting of 𝑛 lines of code.

// Maxim starts working immediately and writes at a speed of 𝑥 lines per hour until the very end.

// Nikita has two options:

// not use AI and write from the very beginning at a speed of 𝑦 lines per hour;
// spend 𝑧 hours first setting up an AI agent, writing nothing during that time, and then write at a speed of 10⋅𝑦 lines per hour.
// Nikita makes this choice before work begins and does not change it later.

// While Nikita is setting up the AI, he does not write any code at all, but Maxim continues working at the speed of 𝑥 lines per hour.

// The project is considered completed as soon as Maxim and Nikita together have written at least 𝑛 lines of code. If the project can be completed before the AI setup ends, then the work ends at that moment.

// Time is measured using full hours: if a project is completed in the middle of an hour, this hour is counted fully.

// Nikita chooses whether to use AI or not.

// Determine the minimum number of full hours after which the project will be completed.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1≤𝑡≤100). The description of the test cases follows.

// The only line of each test case contains four integers 𝑛, 𝑥, 𝑦, and 𝑧 (1≤𝑛,𝑥,𝑦,𝑧≤10000) — the number of lines in the project, Maxim's speed, Nikita's speed without AI, and the AI setup time, respectively.

// Output
// For each test case, output one integer — the minimum number of full hours after which the project will be completed if Nikita acts optimally.


#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t){
        int n,x,y,z;

        cin>>n>>x>>y>>z;
        int mint = 100000;

        int time1 = ceil((double) n/(x+y));

        mint = min(mint, time1);
        
        int time2 = z;
        int lines = n - x*z;

        if(lines > 0){
            time2 += ceil((double)lines/(x+(10*y)));
            mint = min(mint,time2);
        }else{
            time2 = ceil((double)n/x);
            mint = min(mint,time2);
        }

        cout<<mint<<endl;
        t--;
    }

    return 0;
}
