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
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    // c = length of book
    // v0 = initial reading speed
    // v1 = max reading speed
    // a = acceleration in reading speed
    // l = number of pages needing re-reading each day (except 0)
    int capacity = v0;
    int read = v0;
    int i = 1;
    while (read < c)
    {
        read -= l;
        capacity = min(v1, v0 + a * i);
        read += capacity;
        // cout << "read: " << read << " max: " << c << " i: " << i << " cap: " << capacity << endl;
        ++i;

    }
    cout << i << endl;
}