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
int n,q;
vector<ll> v,seg;
void build(int l,int r,int pos)
{
    if(l==r)
    {
        seg[pos]=v[r];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*pos+1);
    build(mid+1,r,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
ll qry(int l,int r,int ql,int qr,int pos)
{
    if(l>=ql && r<=qr)
    return seg[pos];
    else if(r<ql || l>qr)
    return LLONG_MAX;
    int mid=(l+r)/2;
    return min(qry(l,mid,ql,qr,2*pos+1),qry(mid+1,r,ql,qr,2*pos+2));
}
void update(int i,int x,int l,int r,int pos)
{
    if(l==r)
    {
        seg[pos]=v[l];
        return;
    }
    int mid=(l+r)/2;
    if(i<=mid){
        update(i,x,l,mid,2*pos+1);
    }
    else update(i,x,mid+1,r,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
int main()
{
    fastio();
    cin>>n>>q;
    v.resize(n);
    for(auto &i:v)
    {
        cin>>i;
    }
    int sz=1;
    while(sz<n)
    {
        sz*=2;
    }
    sz=2*sz-1;
    seg.resize(sz,LLONG_MAX);
    build(0,n-1,0);
    while(q--)
    {
        int t,l,r,x,i;
        cin>>t;
        if(t==1)
        {
            cin>>i>>x;
            v[i]=x;
            update(i,x,0,n-1,0);

        }
        else
        {
            cin>>l>>r;
            cout<<qry(0,n-1,l,r-1,0)<<"\n";
        }
    }
}