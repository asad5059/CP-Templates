
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
ll n,m,x,y;
char a[100][100];
bool vis[100][100];
ll dis[100][100];
ll d1[]={1,-1,0,0};
ll d2[]={0,0,1,-1};
bool ok(int i,int j)
{
    return vis[i][j]==0 && i>0 && i<=n && j>0 && j<=m && a[i][j]!='#';
}
void bfs(ll i,ll j)
{
    vis[i][j]=1;
    queue <pair<ll,ll>> q;
    q.push({i,j});
    dis[i][j]=0;
    while(!q.empty())
    {
        pair<ll,ll> cur=q.front();
        q.pop();
        for(int k=0;k<4;k++)
        {
            ll p=cur.ff+d1[k];
            ll qq=cur.ss+d2[k];
            if(ok(p,qq))
            {
                q.push({p,qq});
                vis[p][qq]=1;
                dis[p][qq]=dis[cur.ff][cur.ss]+1;
            }
        }
    }
}
int main()
{
    fastio();
    cin>>n>>m;
    int s1,s2,e1,e2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='S')
            {
                s1=i,s2=j;
            }
            if(a[i][j]=='G')
            {
                e1=i,e2=j;
            }
        }
    }
    bfs(s1,s2);
    cout<<dis[e1][e2]<<endl;
    
}
