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
    int n; cin >> n; 
    vector<ll> a(n);
    get(a);
    ll tot = 0;

    ll curra = 0, currb = 0;
    for(int i = 0 ;i < n; i++){
        if(i & 1){
            curra += a[i];
        }
        else{
            currb += a[i];
        }
        tot += a[i];
    }
    if(curra < currb){
        swap(curra, currb);
    }
    ll mndif = INF;
    vector<ll> pref(n), suff(n);
    pref[0] = a[0];
    pref[1] = a[1];
    for(int i = 2; i < n; i++){
        pref[i] = a[i] + pref[i - 2];
    }
    suff[n-1] = a[n-1];
    suff[n-2] = a[n-2];
    for(int i = n - 3; i >= 0; i--){
        suff[i] = suff[i + 2] + a[i];
    }
    for(int i = 1; i + 1 < n; i++){
        ll scorea = pref[i] + suff[i + 1];
        ll scoreb = tot - scorea;
        if(scorea < scoreb){
            swap(scoreb, scorea);
        }
        mndif = min (mndif, scorea - scoreb);
    }
    mndif = min(mndif, curra - currb);
    cout << (mndif + tot) / 2 << " " << (tot - mndif) / 2 << endl;
    return 0;

}