#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define INF 1e9

int t, n;
bool flag;
string s1, s2, s3, s4, s5;

void solve()
{
    cin >> s1;
    s2 = 'a' + s1;
    s3 = s2;
    s4 = s1 + 'a';
    s5 = s4;

    reverse(s2.begin(), s2.end());
    reverse(s4.begin(), s4.end());

    if (s2 != s3) {
        cout << "YES\n"
             << s3 << endl;
    } else if (s4 != s5) {
        cout << "YES\n"
             << s5 << endl;
    } else {
        cout << "NO\n";
    }
}

int main(void)
{
    fastio;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
