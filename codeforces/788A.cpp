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
int n, x;
ll best = 0;

int main()
{
    cin >> n;
    vi a;
    for(int i=0;i<n;i++)cin >> x,a.pb(x);
    vi dp(n);
    dp[0] = 0;
    for(int i=0;i+1<n;i++){
        
    }
}