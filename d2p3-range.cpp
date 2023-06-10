#include <bits/stdc++.h>
#define T tuple<int,int,int>
using namespace std;
const int N = 4e5 + 1;
vector<T> vec;
vector<int> dp;
int ans[N];
bool sorter(const T &a, const T &b) {
    auto [l1,r1,idx1] = a;
    auto [l2,r2,idx2] = b;
    if (r1!=r2) return r1<r2;
    return l1>l2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        int l,r; cin >> l >> r;
        vec.push_back({l,r,i});
    }
    sort(vec.begin(), vec.end(), sorter);
    for(auto [l,r,i]:vec) {
        auto it = upper_bound(dp.begin(), dp.end(), l, greater<int>()) - dp.begin();
        if (it==dp.size()) dp.push_back(l);
        else dp[it] = l;
        ans[i] = it+1;
    }
    cout << dp.size() << '\n';
    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
    return 0;
}