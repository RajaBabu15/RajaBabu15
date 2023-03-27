/*Author:: Visrut Lukhi
  NICHE JA BHAI YAHA KUCH NAHI HAI*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define pll pair<ll, ll>
#define mpll map<ll, ll>
#define ld long double
#define float double
#define f(i, x, n) for (ll i = x; i < n; i++)
#define rf(i, x, n) for (ll i = x; i >= n; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pi (3.141592653589)
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define ub upper_bound
#define lb lower_bound
#define Chal_Ab_Code_Dekhle ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll fastprime(ll n){ if(n==1) return 1; if(n==0) return 0; f(i, 2, (ll)sqrt(n)) if (n % i == 0) return 0;return 1;}
ll power(ll n,ll a){ ll res=1; while(n){ if(n%2){ res*=n,a--;} else	{n*=n,a/=2;}} return res;}
ll modpowe(ll n,ll a,ll p){ ll res=1; while(a){ if(a%2) res= ((res*n)%p) ,a--; else	n=((n*n)%p),a/=2;} return res;}
 
const ll N = 1e5+7;
vll g[N];
    int a[400];
    int dp[400];
int fun(int in){
    
    if(in<0){return 0;}
    if(dp[in]!=-1)
    return dp[in];
    int take = a[in] + fun(in-2);
    int nottake = fun(in-1);

    return dp[in] = max(take , nottake);
}
void solve()
{
    ll n;
    cin >> n;
    f(i,0,n)cin >> a[i];

    memset(dp ,-1, sizeof(dp));
    // f(i,0,n)cout << dp[i] << " ";
    int ans = fun(n-1);
    cout << ans << endl;
}
int main(){
//#ifndef ONLINE_JUDGE
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//#endif
Chal_Ab_Code_Dekhle;
 ll t;
 t = 1;
 cin >> t;
while(t--)
solve();
}




#include<bits/stdc++.h>

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define int long long 
#define ll long long
#define ull unsigned long long
#define lld long double
#define fo(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,n,s) for(int i=n;i>=s;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define sz(a) (int)a.size()
#define trav(x) for(auto &it:x)
const ll mod = 1000000000+7 ;
//const ll mod = 998244353 ;
const double pi = double(3.1415926535897932384626433832795);
typedef pair<ll,ll> pii;
#define ub upper_bound
#define lb lower_bound
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vpii;
#define all(x) (x).begin()+1, (x).end() //--
#define inf 1e18
#define setp(x) setprecision(x)
template<class T>
T cmax(T x, T y) { return (x > y ? x : y); }
template<class T>
T cmin(T x, T y) { return (x < y ? x : y); }

#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define rl(x) cin>>x;
#define rv(x, n) vi x(n+1); fo(i,1,n) cin>>x[i];
#define rv_(x, n) vi x(n); fo(i,0,n-1) cin>>x[i];

//void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << "{ "; __print(x.first); cerr << ", "; __print(x.second); cerr << " }";}
template<typename T>
void __print(const T &x) {int f = 0; cerr << " "; for (auto &i: x) cerr << (f++ ? " , " : ""), __print(i); cerr << " ";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


clock_t time_p=clock();
void timer(){time_p=clock()-time_p;cerr<<"\nTime Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"sec\n";}

void swap(ll &x, ll &y) {ll temp = x; x = y; y = temp;}
void google(ll t) {cout << "Case #" << t << ": ";}
ll bimult(ll a , ll b , ll m) {ll res = 0; while(b) {if(b&1) {res = (res + a)%m;}a = (a + a)%m;b>>=1;}return res;}
ll biexp(ll a, ll b , ll m) {ll res = 1;while(b) {if(b&1) {res = res * a;res%=m;}a = a * a;a%=m;b>>=1;}return res;}
inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
inline ll ceil(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b);}
//#define onebits(x)      __builtin_popcountll(x)
ll set_bits(ll n) { ll cnt = 0;while(n) { n-=n&-n; cnt++;}return cnt;}
#define zerobits(x)      __builtin_ctzll(x)
//const ll N = 2000010;
//template<class A> using ordered_set = tree<A,null_type,less<A>,rb_tree_tag,tree_order_statistics_node_update>;
  // find_by_order() , order_of_key()
priority_queue< ll , vector<ll> ,greater<ll> > pq;
// int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; //knight move;
// int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
vi dx{1 , 0 , -1 , 0};
vi dy{0 , 1 , 0 , -1};
//ll dx[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
//ll dy[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

vvi ReadGraph(ll n,ll m) {
   vvi a(n+1);
   fo(i,1,m) {
      ll x,y; cin>>x>>y;
      a[x].pb(y),a[y].pb(x);
   }
   return a;
}

vvi ReadTree(ll n) {
   return ReadGraph(n,n-1);
}

string S1 = "abcdefghijklmnopqrstuvwxyz";
string S2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


// ---------------------------------------*******************--------------------------------------//

void solve() {
      ll n; cin >> n;
      fo(i,1,n) {
            cout << i%2 << " ";
      } cout << "\n";
   
      
}


// ---------------------------------------*******************--------------------------------------//
 
 
int32_t main() {
      #ifndef ONLINE_JUDGE
            freopen("error.txt", "w", stderr);
      #endif 
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      ll t=1;
      cin>>t;
      fo(_,1,t) {
         // google(_); 
            solve();
      }
      timer();
      return 0;
}
