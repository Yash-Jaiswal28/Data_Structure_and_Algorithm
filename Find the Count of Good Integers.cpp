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


ll fact[11];
// class Solution {
// public:
    unordered_set<string> done;
    void generatenums(long long& res, int n, int k, string& s) {
        if (s.size() == (n + 1) / 2) {
            string tmp = s;
            if (s.size() * 2 != n)
                tmp.pop_back();
            reverse(tmp.begin(), tmp.end());
            tmp = s + tmp;
            if (stoll(tmp) % k == 0) {
                sort(tmp.begin(), tmp.end());
                if (done.find(tmp) != done.end())       
                    return;
                done.insert(tmp);
                int cnt[10] = {};
                for (char x : tmp)
                    cnt[x - '0']++;
                // https://math.stackexchange.com/a/2799206
                int64_t curr = ncr(n - 1, cnt[0]);
                curr *= fact[n - cnt[0]];
                for (int i = 1; i < 10; i++)
                    curr /= fact[cnt[i]];
                res += curr;
            }
            return;
        }
        for (ll i = s.empty(); i < 10; i++) {
            s += '0' + i;
            generatenums(res, n, k, s);
            //cout<<s<<endl;
            s.pop_back();
        }
    }
    long long ncr(int n, int r) {
        // if (r > n)
        //     return 0;
        return (fact[n] / (fact[r] * fact[n - r]));
    }
    long long countGoodIntegers(int n, int k) {
        if (!fact[0]) {
            fact[0] = 1;
            for (int i = 1; i < 11; i++)
                fact[i] = (fact[i - 1] * i);
        }
        long long ans = 0;
        string trash;
        generatenums(ans, n, k, trash);
        return ans;
    }
// };
 

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


  // #ifndef ONLINE_JUDGE
  //    freopen("input.txt","r",stdin);
  //    freopen("output.txt","w",stdout);  
  //     #endif
       
  ll t;
  cin>>t;
    for(ll Z=0;Z<t;Z++)
    {
        int n,k;
        cin>>n>>k;
      cout<<"-->"<<countGoodIntegers(n,k)<<endl;
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/