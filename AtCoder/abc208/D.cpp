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
    int n, m; cin >> n >> m;
    vector<vector<ll>> d(n, vector<ll> (n, INF));
    for(int i = 0; i < n; i++){
        d[i][i] = 0;
    }
    
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        ll c; cin >> c;
        a--, b--;
        d[a][b] = c;
    }
    ll ans = 0;
    for(int k = 0; k < n; k++){
        vector<vector<ll>> curr(n, vector<ll> (n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                curr[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                if(curr[i][j] < INF){
                    ans += curr[i][j];
                }
            }
        }
        d = curr;
    }
    cout << ans << endl;
    return 0;
}