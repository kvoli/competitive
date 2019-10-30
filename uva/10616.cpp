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

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
const ll inf = 10000000000000ll;


int n[205];
int N, Q;
int D, M;
int dp[205][15][25];


// decide how many different subsets of size m are divisible by d
int go(){
    memset(dp, 0, sizeof(dp));

    dp[0][0][0] = 1;

    for(int i=1;i<=N;i++){
        for(int j=0;j<=M;j++){
            for(int k=0;k<D;k++){

                dp[i][j][k] = dp[i-1][k][j];

                if(j){
                    int x = (D + k - n[i-1] % D) % D;
                    dp[i][j][k] += dp[i-1][j-1][x];
                }
            }
        }
    }
    return dp[N][M][0];
}


int main()
{
    int c = 1;

    while (EOF != scanf("%d %d", &N, &Q) && (N || Q)) {
        printf("SET %d:\n", c++);
        for (int i = 0; i < N; i++)
            scanf("%d", &n[i]);
        for (int i = 0; i < Q; i++) {
            scanf("%d %d", &D, &M);
            printf("QUERY %d: %d\n", i+1, go());
        }
    }
}