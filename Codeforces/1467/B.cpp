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



int main(){
    Shazam;
    test(){
        int n; cin >> n;
        vector<ll> a(n + 1), cnt(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 2; i < n; i++){
            cnt[i] += (a[i] < a[i + 1] && a[i] < a[i - 1]);
            cnt[i] += (a[i] > a[i + 1] && a[i] > a[i - 1]);
        }
        for(int i = 1; i <= n; i++){
            cnt[i] += cnt[i - 1];
        }
        // 1-based index
        ll ans = cnt[n];
        for(int i = 2; i < n; i++){
            if(cnt[i] - cnt[i - 1]){
                //changing the ith element iff it is a valley or hilltop
                int l = max(2, i - 1);
                int r = min(n - 1, i + 1);
                {
                    ll temp = a[i];
                    a[i] = a[i - 1];
                    ll cntr = 0;
                    for(int i = l; i <= r; i++){
                        cntr += (a[i] < a[i - 1] && a[i] < a[i + 1]);
                        cntr += (a[i] > a[i - 1] && a[i] > a[i + 1]);
                    }
                    ans = min(ans, cnt[n] - (cnt[r] - cnt[l - 1]) + cntr);
                    a[i] = temp;
                }
                {
                    ll temp = a[i];
                    a[i] = a[i + 1];
                    ll cntr = 0;
                    for(int i = l; i <= r; i++){
                        cntr += (a[i] < a[i - 1] && a[i] < a[i + 1]);
                        cntr += (a[i] > a[i - 1] && a[i] > a[i + 1]);
                    }
                    ans = min(ans, cnt[n] - (cnt[r] - cnt[l - 1]) + cntr);
                    a[i] = temp;
                }

            } 
        }
        cout << ans << endl;
    }
    return 0;
}