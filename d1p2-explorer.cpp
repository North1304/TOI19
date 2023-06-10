#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
const int mod = 1e9 + 7;
vector<int> vec[N];
long long dp[N] , fact[N];
inline long long mul(long long a,long long b) {return (a * b) % mod;}
void dfs(int u,int p) {
    long long son = 0 , cou = 1;
    for(auto v:vec[u]) {
        if (v==p) continue;
        dfs(v, u);
        son++;
        cou *= dp[v];
        cou %= mod;
    }
    dp[u] = mul(cou, fact[son]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,last; cin >> n >> last;
    const int x = last;
    for(int i=2;i<2*n;i++) {
        int a; cin >> a;
        vec[last].push_back(a);
        last = a;
    }
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = mul(fact[i-1], i);
    dfs(x, -1);
    cout << dp[x];
    return 0;
}