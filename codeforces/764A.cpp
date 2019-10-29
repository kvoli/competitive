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


int gcd(int x, int y){
    while (y  > 0){
        x = y;
        y = x % y;
    }
    return x;
}

int lcm(int x, int y){
    
    int lcm = (x*y) / gcd(x,y);
    return lcm;

}


int main()
{
    int n,m,z,res;
    cin >> n >> m >> z;
    res = 0;
    for(int i = n; i <= z; i+=n){
        if (i % m == 0)res++;
    }
    cout << res << endl;
}