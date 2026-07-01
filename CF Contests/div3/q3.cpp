// You are given three integers 𝑎, 𝑏, 𝑥. You want to make 𝑎 and 𝑏 equal. In order to do so, you can apply the following operations:

// Choose one of the integers 𝑎 or 𝑏 and add 1 to it.
// Choose one of the integers 𝑎 or 𝑏 and divide it by 𝑥 with rounding down.
// You need to find the minimum number of operations after which 𝑎 becomes equal to 𝑏. Can you prove your skills, or will you have to go back home?

// Input
// The first line contains a single integer 𝑡 (1≤𝑡≤104) — the number of test cases.

// Then 𝑡 test cases follow.

// Each test case consists of a single line containing three integers 𝑎, 𝑏, 𝑥 (1≤𝑎,𝑏≤109, 2≤𝑥≤109).

// Output
// For each test case, output a single integer — the minimum number of operations required to make 𝑎 and 𝑏 equal.

// #include <iostream>
// #include <cmath>
// #include <algorithm>
// #include <vector>
// #include <climits>
// using namespace std;

// long long getCost(vector<pair<long long,long long>> &chain,long long v){
//     long long mini = LLONG_MAX;

//     for(pair<long long,long long> p : chain){
//         if(p.first <= v){
//             mini = min(mini, p.second + (v-p.first));
//         }
//     }
//     return mini;
// }

// int main(){
//     int t;
//     cin>>t;

//     while(t--){
//         long long a,b,x;
//         cin >> a >> b >> x;

//         vector<pair<long long,long long>> chainA,chainB;
//         vector<long long> candidates;

//         int div = 0;
//         long long i = a;
//         while(true){
//             chainA.push_back({i,div});
//             candidates.push_back(i);

//             if(i == 0) break;
//             i = i/x;
//             div++;
//         }

//         div = 0;
//         i = b;
//         while(true){
//             chainB.push_back({i,div});
//             candidates.push_back(i);

//             if(i == 0) break;
//             i = i/x;
//             div++;
//         }

//         long long mincost = LLONG_MAX ;

//         for(long long v : candidates){
//             mincost = min(mincost,getCost(chainA,v)+getCost(chainB,v));
//         }

//         cout<<mincost<<endl;
//     }
// }

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

using ll = long long;

ll getCost(const vector<pair<ll,ll>>& chain, ll v)
{
    ll best = LLONG_MAX;

    for(auto [u,d] : chain)
    {
        if(u <= v)
            best = min(best, d + (v-u));
    }

    return best;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        ll a,b,x;
        cin >> a >> b >> x;

        vector<pair<ll,ll>> A,B;
        vector<ll> candidates;

        ll cur = a;
        int d = 0;

        while(true)
        {
            A.push_back({cur,d});
            candidates.push_back(cur);

            if(cur==0) break;

            cur /= x;
            d++;
        }

        cur = b;
        d = 0;

        while(true)
        {
            B.push_back({cur,d});
            candidates.push_back(cur);

            if(cur==0) break;

            cur /= x;
            d++;
        }

        ll ans = LLONG_MAX;

        for(ll v : candidates)
        {
            ans = min(ans,
                      getCost(A,v) + getCost(B,v));
        }

        cout << ans << '\n';
    }
}