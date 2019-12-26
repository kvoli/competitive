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
int t;
ll x,y,z;
string s;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll a,b,n,S;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> a >> b >> n >> S;
        if((a * n) % S == 0 || (a * n) % S + b >= S){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}