//Yash_Jaiswal
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Endl '\n'
#define pb push_back
#define ff first
#define ss second
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const ll mod = 1e9 + 7;
template <class T> void display(vector<T> &v){ for(ll i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl;}
template <class U> void display(vector<vector<U>> &v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<" ";}cout<<endl;} cout<<endl;}
template <class V> void Input(vector<V> &v,ll n){for(ll i=0;i<n;i++){V element;cin>>element;v.pb(element);}}
template <class W> void Input(vector<vector<W>> &v, ll n, ll m){v.resize(n, vector<W>(m));for(ll i = 0; i < n; i++){for(ll j = 0; j < m; j++){W element;cin >> element;v[i].pb(element);}}}
ll Pow(ll base,ll ex){ll ans=1ll;while(ex>0){if(ex%2==1)ans=(ans*base)%mod;ex=ex/2;base=(base*base)%mod;}return ans;}
ll fact(ll n){if(n<=2)return n;else{ll a=1;for(ll i=2;i<=n;i++){a=((a%mod)*(i%mod))%mod;}return a;}}
ll nCr(ll n, ll r){if(r>n)return 0;ll res = 1;for (ll i = r+1; i <= n; i++){res = (res * i) % mod;}ll inv = 1;for (ll i = 2; i <= n-r; i++){inv = (inv * i) % mod;}inv = Pow(inv, mod-2);return (res * inv) % mod;}
ll nPr(ll n,ll r){ll d=fact(n);ll c=fact(n-r);return (d/c);}


/*********************************************************************************************************************************************************************************************************/

bool comp(pair<ll,pair<ll,ll>>& a,pair<ll,pair<ll,ll>>& b){
   if(a.ff==b.ff)return a.ss.ff<b.ss.ff;
  // if(a.ss.ff==b.ss.ff)return a.ss.ff<b.ss.ff;
return a.ff>b.ff;
}

ll fun(vector<pair<ll,ll>>& vp,vector<vector<ll>>& dp,vector<ll>& space,ll prev,ll ck,ll ind,ll n){
    if(ind==n)return 0;
    if(dp[ind][ck]!=-1)return dp[ind][ck];
    ll ans=fun(vp,dp,space,space[ind],2,ind+1,n);
    if(prev>vp[ind].ss){
        ans=max(ans,1+fun(vp,dp,space,space[ind],1,ind+1,n));
    }else if(vp[ind].ss<space[ind])ans=max(ans,1+fun(vp,dp,space,space[ind]-vp[ind].ss,0,ind+1,n));

    return dp[ind][ck]=ans;
}

void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> vp;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        vp.pb({a,b});
    }
    vector<ll> space;
    for(ll i=0;i<n-1;i++){
        space.pb(vp[i+1].ff-vp[i].ff);
    }
    space.pb(INT_MAX);
    //     cout<<" ";  
    // display(space);
    // for(auto it:vp)cout<<it.ss<<" ";
    //cout<<endl;
    vector<vector<ll>> dp(n,vector<ll>(3,-1));
    cout<<fun(vp,dp,space,INT_MAX,2,0,n)<<endl;
   // display(dp);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


  // #ifndef ONLINE_JUDGE
  //    freopen("input.txt","r",stdin);
  //    freopen("output.txt","w",stdout);  
  //     #endif
       
//   ll t;
//   cin>>t;
//     for(ll Z=0;Z<t;Z++)
    {
      solve();
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/