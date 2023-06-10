#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char str[N];
stack<pair<int,int>> s;
long long ans,sum;
int now,st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> str[i];
    s.push({N, 0});
    for(int i=1;i<=n;i++) {
        if (str[i]=='F') now = 0 , st = 0;
        else {
            if (st==0) st = i;
            sum += ++now;
            while (!s.empty() && s.top().first<now) s.pop();
            sum += st - s.top().second - 1;
            if (str[i+1]=='F') {
                for(int j=now;j>=1;j--) s.push({j, i-j+1});
            }
        }
        ans += sum;
    }
    cout << ans;
    return 0;
}