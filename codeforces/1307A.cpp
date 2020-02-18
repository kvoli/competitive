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
int t, n;


int main() {
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        int n, d, a, res;
        cin >> n >> d;
        cin >> res;
        for(int j=1;j<n;j++){
            cin >> a;
            if (a > 0) {
                int div = d / j;
                if (div > a) {
                    res += a;
                    d -= a * j;
                } else if (a >= div) {
                    res += div;
                    d -= div * j;
                } 
            }
        }
        cout << res << endl;
    }
}

// 100 16
// 8 2 1 3 3 3 8 10 4 5 4 8 7 7 3 3 10 10 5 1 9 10 4 3 4 2 8 6 4 3 1 4 5 2 10 2 1 2 3 10 2 10 3 3 7 2 6 2 6 1 2 8 6 6 6 3 9 3 3 8 7 4 8 8 3 4 8 3 4 5 8 1 6 5 7 7 5 7 7 3 8 2 2 4 7 4 6 4 9 4 4 10 6 7 2 4 3 3 10 10
