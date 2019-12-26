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

int n, m, t, i, j, k;
ll x,y,z;
string s;


int main()
{
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        bool used[n];
        memset(used, false, sizeof(used));
        int perm[n];
        for(int k=0;k<n;k++){
            cin >> m;
            perm[k] = m;
        }
        int min_val = perm[0];
        int min_val_index = 0;
        int prev_min_index = 0;
        while(min_val_index < n){
            for(int j = prev_min_index; j < n;j++)if(perm[j] <= min_val)min_val=perm[j],min_val_index=j;
            for(int j = min_val_index; j > prev_min_index; j--){
            int tmp = perm[j];
            perm[j] = perm[j-1];
            perm[j-1] = tmp;
            }
            min_val_index++;
            prev_min_index = min_val_index;
        }
        for(int j=0;j<n;j++)cout << perm[j] << ' ';
        cout << endl;
    }
}