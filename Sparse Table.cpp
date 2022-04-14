#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define ff first
#define INF 1e18
#define ss second
using namespace std;
using namespace __gnu_pbds;
template <typename PB>
using ordered_set = tree<PB,null_type,less_equal<PB>,rb_tree_tag,tree_order_statistics_node_update> ;
const ll mod = 1e9+7;

int lg2(const int &x){return 31 - __builtin_clz(x);}
ll bigMod(ll a,ll b){a%=mod;ll res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
inline ll MOD(ll a){ return (a%mod + mod) %mod ; }
inline ll modAdd(ll a,ll b){ return MOD( MOD(a) + MOD(b) ) ; }
inline ll modSub(ll a,ll b){ return MOD( MOD(a) - MOD(b) ) ; }
inline ll modMul(ll a,ll b){ return MOD( MOD(a) * MOD(b) ) ; }
inline ll modInv(ll a){ return bigMod(a,mod-2) ; }
inline ll modDiv(ll a,ll b){ a=MOD(a); b=modInv(b); return (a*b)%mod; }
ll lcm(ll a, ll b)
{
    return (a * (b /__gcd(a, b)));
}
ll fix_mod(ll a,ll b)
{
    return (a%b+b)%b;
}
void fastio()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r+", stdin);
        //freopen("output.txt", "w+", stdout);
    //#endif
}
int main()
{
    fastio();
    ll t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        cout<<"Scenario #"<<tc<<":\n";
        int n,q,h;
        cin>>n>>q;
        ll a[n];
        ll g[21][n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            g[0][i]=a[i];
        }
        for(int i=1;i<=20;i++)
        {
            for(int j=0;j+(1<<(i-1))<n;j++)
            {
                g[i][j]=min(g[i-1][j],g[i-1][j+(1<<(i-1))]);
            }
        }
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--,r--;
            int len=r-l+1;
            int req=lg2(len);
            len=1<<req;
            cout<<min(g[req][l],g[req][r-len+1])<<"\n";

        }
    }
}