/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

ll dp[105][105][105];

int main(){
    Shazam;
    int n; cin >> n;
    ll x; cin >> x;
    vector<ll> a(n);
    get(a);
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            for(int k = 0; k < 105; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    ll ans = INF;
    dp[0][0][0] = 0;
    auto max_self = [&](ll &a, ll b){
        a = max(a, b);
    };
    for(int i = 1; i <= n; i++){
        vector<vector<ll>> dp(i + 1, vector<ll> (i + 1, -1));
        dp[0][0] = 0;
        for(ll val : a){
            for(int choose = i - 1; choose >= 0; choose--){
                for(int rem = 0; rem < i ; rem++){
                    if(dp[choose][rem] != -1){
                        ll next_val = val + dp[choose][rem];
                        max_self(dp[choose + 1][ next_val % i], next_val);
                    }
                }
            }
        }
        if(dp[i][x % i] != -1){
            ans = min(ans, (x - dp[i][x % i]) / i);
        }
    }
    cout << ans << endl;
    return 0;
}