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
string t,b;

int main()
{
    int best = 0;
    cin >> t >> b;

    for(int i=0;i+1<t.size();i++){
        if      (t[i] == '0' && t[i+1] == '0' && b[i] == '0')best++,t[i]='O',t[i+1]='O',b[i]='O';
        else if (t[i] == '0' && b[i]=='0' && b[i+1]=='0')best++,t[i]='O',b[i+1]='O',b[i]='O';
        else if (b[i] == '0' && b[i+1]=='0' && t[i+1]=='0')best++,b[i]='O',b[i+1]='O',t[i+1]='O';    
        else if (t[i] == '0' && t[i+1]=='0' && b[i+1]=='0')best++,t[i]='O',t[i+1]='O',b[i+1]='O';
    }
    cout << best;
}