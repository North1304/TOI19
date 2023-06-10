#include <bits/stdc++.h>
using namespace std;
const int N = 8e4 + 1;
const int M = 2e6 + 1;
const int INF = 2e9;
int w[N] , cure[N] , poison[N] , dis[M];
vector<pair<int,int>> vec[M];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,s; cin >> n >> s;
    for(int i=1;i<=n;i++) {
        cin >> w[i];
        for(int j=0;j<s;j++) {
            int a; cin >> a;
            if (a==1) cure[i] |= (1<<j);
            else if (a==-1) poison[i] |= (1<<j);
        }
    }
    for(int k=0;k<(1<<s);k++) {
        for(int i=0;i<s;i++) {
            if (k&(1<<i)) vec[n+k+1].push_back({0, n+(k^(1<<i))+1});
        }
    }
    for(int i=1;i<=n;i++) {
        vec[n+poison[i]+1].push_back({0, i});
        vec[i].push_back({w[i], n+cure[i]+1});
    }
    for(int i=1;i<M;i++) dis[i] = INF;
    for(int i=1;i<=n;i++) {
        if (poison[i]==0) {
            dis[i] = 0;
            q.push({0, i});
        }
    }
    while (!q.empty()) {
        auto [dist,u] = q.top(); q.pop();
        for(auto [w,v]:vec[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if (dis[i]==INF) continue;
        ans = max(ans, dis[i]);
    }
    cout << ans;
    return 0;
}