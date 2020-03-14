#include<bits/stdc++.h>


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

const ll INF = LLONG_MAX;

ll n,m,a,b,w,k,i,z;
vector<ll>v[100005];
priority_queue<ll> q;
map <pair<ll,ll>, ll> weights;
ll d[100005], p[100005];

void prt(int x){
    if (x != 1) prt(p[x]);
    cout << x << ' ';
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=2;i<=n;i++)d[i] = INF;

    while(m--){
        cin>>a>>b>>w;
        v[a].push_back(b);
        v[b].push_back(a);
        weights[mp(a,b)] = w;
        weights[mp(b,a)] = w;
    }

    q.push(1);

    while (q.size()) {
        k = q.top();
        q.pop();
        for (i=0;i<v[k].size();i++){
            z = v[k][i];
            w = weights[mp(k,z)];
            if (d[k] + w < d[z]) d[z] = d[k] + w,p[z]=k,q.push(z);
        }
    }

    if (d[n] == INF)return cout << -1, 0;
    prt(n);
    return 0;
}