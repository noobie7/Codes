/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ff first
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define fl(i,a,b) for(int i = a ; i <b ;i++)
#define get(a) fl(i,0,a.size())  cin>>a[i];
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n, m, x; cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    ll ans = INF;
    for(int mask = 0; mask < (1 << n); mask++){
        vector<int> score(m);
        ll cost = 0;
        for(int bit = 0; bit < n; bit++){
            if(mask & (1 << bit)){
                cost += c[bit];
                for(int j = 0; j < m; j++){
                    score[j] += a[bit][j];
                }
            }
        }
        if(*min_element(all(score)) >= x)
            ans = min(ans, cost);
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}