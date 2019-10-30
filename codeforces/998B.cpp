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
    int n, B;
    cin >> n >> B;
    int A[n], Odds[n], Even[n];
    for(int i=0;i<n;i++)scanf("%d", &A[i]);
    if(A[0] % 2 == 0){
        Even[0] = 1, Odds[0] = 0;
    } else {
        Even[0] = 0, Odds[0] = 1;
    }
    for(int i=1;i<n;i++){
        if(A[i] % 2 == 1){
            Odds[i] = Odds[i-1] + 1;
            Even[i] = Even[i-1];
        } else {
            Odds[i] = Odds[i-1];
            Even[i] = Even[i-1] + 1;
        }
    }
    vi cuts;
    for(int i=1;i<n-1;i+=2){
        if(Odds[i] == Even[i] && (Odds[n-1] - Odds[i]) == (Even[n-1] - Even[i])){
            cuts.pb(abs(A[i]-A[i+1]));
            // cout << cuts[cuts.size()-1] << endl;
        }
    }
    int res = 0;
    sort(cuts.begin(), cuts.end());
    while (B >= 0 and res < cuts.size()){
        B -= cuts[res];
        if (B >= 0){
            res++;    
        }
    }
    cout << res << endl;
}