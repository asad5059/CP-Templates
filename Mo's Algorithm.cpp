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
const int block=300;
int cnt=0;
int freq[2000000];
vector<ll> v,ans;
struct Query
{
    int id,l,r;
};
bool cmp(Query q1,Query q2)
{
    if(q1.l/block != q2.l/block)
    {
        return q1.l/block < q2.l/block;
    }
    else
    {
        return q1.r > q2.r;
    }
}
void add(int i)
{
    freq[v[i]]++;
    if(freq[v[i]]==1)
    {
        cnt++;
    }
}
void remove(int i)
{
    freq[v[i]]--;
    if(freq[v[i]]==0)
    {
        cnt--;
    }
}

vector<Query> dq;
int main()
{
    fastio();
    int n;
    cin>>n;
    v.resize(n);
    memset(freq,0,sizeof freq);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int q;
    cin>>q;
    dq.resize(q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        dq[i].id=i;
        dq[i].l=l;
        dq[i].r=r;
    }
    ans.resize(q);
    sort(dq.begin(),dq.end(),cmp);
    int ML = 0 , MR = -1;
	for(int i=0;i<q;i++)
	{
		int L = dq[i].l;
		int R = dq[i].r;
 
		while(ML > L)
		ML-- , add(ML);
 
		while(MR < R)
		MR++ , add(MR);
 
		while(ML < L)
		remove(ML) , ML++;
 
		while(MR > R)
		remove(MR) , MR--;
 
		ans[dq[i].id] = cnt;
	}
    for(auto i:ans)
    cout<<i<<"\n";
}