//DFS Implementation
//Time Complexity : O(node+edge) == O(n)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define ff first
#define ss second
using namespace std;
using namespace __gnu_pbds;
template <typename PB>
using ordered_set = tree<PB, null_type, less_equal<PB>, rb_tree_tag, tree_order_statistics_node_update>;
ll lcm(ll a, ll b)
{
    return (a * (b / __gcd(a, b)));
}
ll fix_mod(ll a, ll b)
{
    return (a % b + b) % b;
}
void fastio()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
}
vector<ll> adj[100];
ll vis[100];
void dfs(ll u)
{
    vis[u]=1;                  
    cout<<u<<" ";                    
    for(auto i:adj[u])
    {
        if(vis[i]==0)
        dfs(i);
    }
}
int main()
{
    fastio();
    ll node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);
}