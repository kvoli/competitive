#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<vector>
#include<set>
#include<iomanip>
#define F first
#define S second
#define P sytstem("PAUSE");
#define H return 0;
#define pb push_back
#define ll long long
using namespace std;
const ll A=100000000000000LL, N=228228;

int mod(string t, int N){
    int r = 0;
    for (int i = 0; i < t.length(); i++){
        r = r * 10 + (t[i] - '0');
        r %= N;
    }
    return r;
}

string getMin(int N){
    queue<string> q;
    set<int> visit;

    string t = "1";

    q.push(t);

    while(!q.empty()){
        t = q.front(); q.pop();
        
        int rem = mod(t, N);

        if (rem == 0){
            return t;
        } else if(visit.find(rem) == visit.end()){
            visit.insert(rem);
            q.push(t + "0");
            q.push(t + "1");
        }
    }
}

int main(){
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        cout << getMin(x) <<  "\n";
    }
    return 0;
}