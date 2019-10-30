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

int longestIncreasing(vi &heights, vi &widths, int n){
    vi dp(widths);
    int best = 0;
    for(int i=0; i < n; i++){
        for(int j=i; j >= 0; j--){
            if (heights[i] > heights[j] && dp[j] + widths[i] > dp[i]){
                dp[i] = dp[j] + widths[i];
            }
        }
        best  = max(best, dp[i]);
    }
    return best;
}

int longestDecreasing(vi &heights, vi &widths, int n){
    vi dp(widths);
    int best = 0;
    for(int i = 0; i < n; i++){
        for(int j=i-1; j >= 0; j--){
            if (heights[i] < heights[j] && dp[j] + widths[i] > dp[i]){
                dp[i] = dp[j] + widths[i];
            }
        }
        best  = max(best, dp[i]);
    }
    return best;
}


int main()
{
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        int n, x;
        cin >> n;
        vi heights, widths;
        for(int j=0;j<n;j++)cin >> x, heights.pb(x);
        for(int j=0;j<n;j++)cin >> x, widths.pb(x);
        int inc, dec;
        inc = longestIncreasing(heights, widths, n);
        dec = longestDecreasing(heights, widths, n);
        if (inc >= dec){
            cout << "Case " << i+1 << ". Increasing (" << inc << "). ";
            cout << "Decreasing (" << dec << ")." << endl;
        } else {
            cout << "Case " << i+1 << ". Decreasing (" << dec << "). ";
            cout << "Increasing (" << inc << ")." << endl;
        }
    }
}