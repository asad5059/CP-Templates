#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define ff first
#define ss second
using namespace std;
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
}
ll node,edge,x,y;
vector <ll> adj[10001];
bool vis[10001];
ll dis[10001];
void bfs(ll u)
{
    vis[u]=1;
    queue <ll> q;
    q.push(u);
    dis[u]=0;
    while(!q.empty())
    {
        ll cur=q.front();
        q.pop();
        for(auto i:adj[cur])
        {
            if(vis[i]==0)
            {
                q.push(i);
                vis[i]=1;
                dis[i]=dis[cur]+1;
            }
        }
    }
}
int main()
{
    fastio();
    cin>>node>>edge;
    while(edge--)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bfs(3);
    for(int i=1;i<=node;i++)
    {
        cout<<i<<" : "<<dis[i]<<endl;
    }
}
