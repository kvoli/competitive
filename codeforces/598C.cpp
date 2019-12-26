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

int n, m, t, i, j, k, d;
ll x,y,z;
string s;


int main()
{
    cin >> n >> m >> d;
    vi platforms;
    int cur = d-1;
    int res[n];
    memset(res, 0, sizeof(res));
    for (int i=0;i<m;i++){
        cin >> k;
        if (cur > n){
            cout << "YES" << endl;
            for(int j=0;j<n;j++)cout << res[j] << ' ';
            exit(0);
        }
        for(int j=0;j<k;j++)res[cur+j] = i+1;
        cur += k-1;
        cur += d;
    }
    if (cur > n){
    cout << "YES" << endl;
    for(int j=0;j<n;j++)cout << res[j] << ' ';
    exit(0);
    }
    cout << "NO";

}