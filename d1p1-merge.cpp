#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int x[N] , s[N] , y[N] , t[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,q; cin >> n >> m >> q;
    for(int i=1;i<=n;i++) cin >> x[i];
    for(int i=1;i<=n;i++) {
        cin >> s[i];
        s[i] += s[i-1];
    }
    for(int i=1;i<=m;i++) cin >> y[i];
    for(int i=1;i<=m;i++) {
        cin >> t[i];
        t[i] += t[i-1];
    }
    while (q--) {
        int a,b,k; cin >> a >> b >> k;
        int l = -1e9 , r = 1e9 , ans = -1e9;
        while (l <= r) {
            int mid = (l + r) / 2;
            int S = 0 , T = 0;
            int lx = 1 , rx = n;
            while (lx <= rx) {
                int midx = (lx + rx) / 2;
                if (x[midx] <= mid) lx = midx + 1 , S = s[midx];
                else rx = midx - 1;
            }
            int ly = 1 , ry = m;
            while (ly <= ry) {
                int midy = (ly + ry) / 2;
                if ((y[midy] * a) + b <= mid) ly = midy + 1 , T = t[midy];
                else ry = midy - 1;
            }
            if (S + T >= k) r = mid - 1 , ans = mid;
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}