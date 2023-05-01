#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define ll long long
const int MAXN = 1e5 + 5;

ll a[MAXN];           // array valor dos vertices
vector<ll> adj[MAXN]; // lista de adjacencia p o grafo
bool visited[MAXN];   // array pra guardar onde ja foi visitado

ll bfs(ll s) // busca em largura e retorna o menor
{
    queue<ll> q; // fila
    q.push(s);
    visited[s] = true;
    ll minvalue = a[s];
    while (!q.empty()) // enquanto a fila n estiver vazia
    {
        ll u = q.front();
        q.pop();
        for (ll v : adj[u]) // range-based for loop
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
                minvalue = min(minvalue, a[v]);
            }
        }
    }
    return minvalue; // retorna minimo
}

int main()
{
    ll n, m, x, y;
    cin >> n >> m;

    for (ll i = 1; i <= n; i++) // ver
    {
        cin >> a[i];
    }

    for (ll i = 0; i < m; i++) // are
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ll sumvalue = 0;
    memset(visited, false, sizeof visited);
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            sumvalue += bfs(i);
        }
    }
    cout << sumvalue << endl; // soma val min d cada comp
    return 0;
}
