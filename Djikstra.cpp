#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define ff first
#define INF 1e18
#define pii pair<ll,ll>
#define ss second
using namespace std;
using namespace __gnu_pbds;
template <typename PB>
using ordered_set = tree<PB,null_type,less_equal<PB>,rb_tree_tag,tree_order_statistics_node_update> ;
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
vector <pii> v[100009];
ll dis[100009];
ll n,e;
void dijkstra(ll j)
{
    dis[j]=0;
    //max heap
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({dis[j],j});
    while(!q.empty())
    {
        pii cur=q.top();
        q.pop();
        for(auto i:v[cur.ss])
        {
            if(cur.ff+i.ss<dis[i.ff])
            {
                dis[i.ff]=cur.ff+i.ss;
                q.push({dis[i.ff],i.ff});
            }
        }
    }
}
int main()
{
    fastio();
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
    for(int i=0;i<=n;i++) dis[i]=INF;
    dijkstra(1);

}