#include <bits/stdc++.h>
using namespace std;
const int N = 301;
const int mod = 1e9 + 7;
int n,k,d,arr[N];
long long dp[N][N][10];
long long solve(long long l,long long r,int now) {
    if (dp[l][r][now]!=-1) return dp[l][r][now];
    if (l>r) return 0;
    if (now==k) return dp[l][r][now] = 1;
    dp[l][r][now] = 0;
    for(int i=l;i<r;i++) {
        if (abs((arr[i]-arr[l-1]) - (arr[r]-arr[i])) <= d) {
            dp[l][r][now] += solve(l, i, now+1) * solve(i+1, r, now+1);
            dp[l][r][now] %= mod;
        }
    }
    return dp[l][r][now];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> d;
    memset(dp, -1, sizeof(dp));
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    cout << solve(1, n, 1);
    return 0;
}