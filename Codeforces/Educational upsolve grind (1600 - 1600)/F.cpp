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
    map<ll, priority_queue<int>> f;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        ll k; cin >> k;
        f[k].push(-i);
    }
    for(auto &pp: f){
        while(pp.ss.size() > 1){
            pp.ss.pop();
            int idx = -1 * pp.ss.top();
            pp.ss.pop();
            f[pp.ff * 2].push(-idx);
        }
        
    }
    vector<pair<ll,ll>> ans;
    for(auto pp : f){
        if(pp.ss.size()){
            ans.push_back({abs(pp.ss.top()), pp.ff});
        }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].ss << " ";
    }
    cout << endl;
    return 0;
}