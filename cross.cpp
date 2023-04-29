#include <bits/stdc++.h>

using namespace std;

int h, w;
int tam = 0;

void dfs(int i, int j, vector<string> &M, vector<vector<int>> &visited)
{
    if (!visited[i][j] && M[i][j] == '#')
    {
        tam++;
        visited[i][j] = 1;
        if (i > 0 && j > 0)
            dfs(i - 1, j - 1, M, visited);
        if (i > 0 && j < w - 1)
            dfs(i - 1, j + 1, M, visited);
        if (i < h - 1 && j > 0)
            dfs(i + 1, j - 1, M, visited);
        if (i < h - 1 && j < w - 1)
            dfs(i + 1, j + 1, M, visited);
    }
}

int main()
{

    vector<string> M(101);
    vector<vector<int>> visited(101, vector<int>(101, 0));
    int componentes = 0;
    vector<int> resp(101, 0);

    cin >>
        h >> w;

    for (int i = 0; i < h; i++)
    {
        cin >> M[i];
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (!visited[i][j] && M[i][j] == '#')
            {
                componentes++;
                tam = 0;
                dfs(i, j, M, visited);
                int pos = (tam - 1) / 4;
                resp[pos]++;
                //  cout << tam << endl;
            }
        }
    }

    for (int i = 1; i <= min(w, h); i++)
    {
        cout << resp[i] << " ";
    }

    cout << endl;
}