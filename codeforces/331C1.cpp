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
const int iinf = 2147483647;


void collect_digits(vi &digits, ll num){
    if (num > 9){
        collect_digits(digits, num / 10);
    }
    digits.pb(num % 10);
}


int main()
{
    ll n;
    cin >> n;
    ll dp[n+1];
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        if (i < 10){
            dp[i] = 1;
        } else {
            vi digits; 
            ll z = 214783647;
            collect_digits(digits, i);
            for (int u : digits)z = min(z, dp[i - u]);
            dp[i] = z + 1;
        }
    }
    cout << dp[n];
}