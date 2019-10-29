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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll cheapest = inf;

    for (int i = 0; i < 24; i++){
        for (int j=0; j < 24; j++){
            for (int k = 0; k < 24; k++){
                if((i + j*2 + k*3 + n) % 4 == 0 && (i*a+j*b+k*c < cheapest))cheapest=i*a+j*b+k*c;
            }
        }
    }
    cout << cheapest << endl;

    
    // n = number of copybooks already owned
    // a = cost of 1 copy book
    // b = cost of 2 copy book
    // c = cost of 3 copy book
}