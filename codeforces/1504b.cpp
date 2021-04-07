#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define INF 1e9

int t, n;
bool flag;

void solve()
{
    int n, cnt = 0;
    string a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1')
            ++cnt;
        if (i < n - 1 && a[i] == b[i] && a[i + 1] != b[i + 1] && (i % 2 == 0 || (i + 1) / 2 != cnt)) {
            cout << "NO" << endl;
            return;
        }
        if (i < n - 1 && a[i] != b[i] && a[i + 1] == b[i + 1] && (i % 2 == 0 || (i + 1) / 2 != cnt)) {
            cout << "NO" << endl;
            return;
        }
        if (i == n - 1 && a[i] != b[i] && (i % 2 == 0 || (i + 1) / 2 != cnt)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(void)
{
    fastio;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
