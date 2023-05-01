#include <bits/stdc++.h>

using namespace std;

char s[51][51];
int visited[51][51], n, m;

// usado para representar a mudanca das coordenadas nas 4 direcoes possiveis
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool dfs(int x, int y, int px, int py, int len)
{
    visited[x][y] = 1; // marca como visitado

    for (int i = 0; i < 4; i++)
    {
        // proximas coordenadas
        int tx = x + dx[i];
        int ty = y + dy[i];

        // verifica se a proxima posicao tem o mesmo valor da posicao atual
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && s[tx][ty] == s[x][y])
        {
            // verifica se ja foi visitado
            if (visited[tx][ty])
            {
                // verifica se existe ciclo e se tem pelo menos 4 de tamanho
                if (len >= 4 && tx == px && ty == py)
                    return true;
            }
            else
            {
                if (dfs(tx, ty, px, py, len + 1))
                    return true;
            }
        }
    }

    visited[x][y] = 0;
    return false; // caso nao encontre ciclo
}

bool check()
{
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(i, j, i, j, 1))
                return true;
        }
    }

    return false;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);

    printf("%s\n", check() ? "Yes" : "No");

    return 0;
}
