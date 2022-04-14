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
ll get(ll a);
vector<ll> v;
void uni(int a,int b)
{
    a=get(a);
    b=get(b);
    if(a!=b)
    v[b]=a;

}
ll get(ll a)
{
    if(a==v[a])
    return a;
    return v[a]=get(v[a]);
}
int main()
{
    fastio();
    ll n,q;
    cin>>n>>q;
    v.resize(n+2);
    for(int i=1;i<=n;i++)
    {
        v[i]=i;
    }
    while(q--)
    {
        string s;
        ll a,b;
        cin>>s>>a>>b;
        if(s[0]=='u')
        {
            uni(a,b);
        }
        else
        {
            a=get(a);
            b=get(b);
            cout<<(a==b?"YES":"NO")<<"\n";
        }
    }
}