#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 1337;
int parent[N];
int distancia[N];
bool visited[N];

void bfs(int x)
{
    queue<int> q; // usando fila
    q.push(x);
    visited[x] = true; // marca como visitado
    distancia[x] = 0;  // distancia do ver inic = 0
    while (!q.empty()) // enquanto n vazia
    {
        int t = q.front();
        q.pop();
        int x = parent[t];
        if (visited[x]) // se o pai ja foi visitado = ciclo
        {
            cout << x << " "; // imprime o vertice do ciclo
            return;
        }
        visited[x] = true;
        distancia[x] = distancia[t] + 1;
        q.push(x);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &parent[i]);
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof visited);
        bfs(i);
    }
    return 0;
}
