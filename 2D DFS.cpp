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
ll r, c;
int adj[100][100];
int vis[100][100];
int d1[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int d2[] = {0, 0, -1, 1, -1, 1, -1, 1};
// knight
// int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
// int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
void dfs(int i, int j)
{
    vis[i][j] = 1;
    for (int k = 0; k < 8; k++)
    {
        int x = i, y = j;
        x = i + d1[k];
        y = j + d2[k];
        if (vis[x][y] == 0 && adj[x][y] == 1 && x >= 0 && x < r && y >= 0 && y < c)
        {
            dfs(x, y);
        }
    }
}
int main()
{
    fastio();
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> adj[i][j];
        }
    }
    ll cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (adj[i][j] == 1 && vis[i][j] == 0)
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}