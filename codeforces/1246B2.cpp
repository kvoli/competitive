#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pi> vp;
typedef vector<pl> vpl;

const ll inf = 10000000000000ll;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll n, k, d, cur_len, best_len;
        cin >> n >> k >> d;
        vi shows(n);
        vi counter(2000000);
        best_len = inf;
        cur_len = 0;
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            shows.pb(val);
            if (j < d)
            {
                counter[val]++;
                if (counter[val] == 1)
                    cur_len++;
                cout << val << ' ' << counter[val] << endl;
            }
            else
            {
                counter[shows[j - d]]--;
                counter[val]++;
                cout << counter[shows[j-d]] << ' '<< counter[val] << endl;
                if (counter[shows[j - d]] < 1)
                    cur_len--;
                if (counter[val] == 1)
                    cur_len++;
                best_len = min(cur_len, best_len);
                cout << cur_len << ' ' << best_len << endl;
            }
        }
        best_len = min(cur_len, best_len);
        cout << best_len << endl;
    }
}
