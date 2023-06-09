#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, l, c;
    vector<string> picture(1026);
    vector<vector<int>> visited(1026, vector<int>(1026, 0));
    queue<pair<int, int>> q;
    int clicks = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> picture[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && picture[i][j] == '.')
            {
                clicks++;
                q.push({i, j});
                visited[i][j] = 1;
                while (!q.empty())
                {
                    tie(l, c) = q.front();

                    q.pop();

                    if (l < n - 1 && !visited[l + 1][c] && picture[l + 1][c] == '.')
                    {
                        q.push({l + 1, c});
                        visited[l + 1][c] = 1;
                    }

                    if (l > 0 && !visited[l - 1][c] && picture[l - 1][c] == '.')
                    {
                        q.push({l - 1, c});
                        visited[l - 1][c] = 1;
                    }

                    if (c < m - 1 && !visited[l][c + 1] && picture[l][c + 1] == '.')
                    {
                        q.push({l, c + 1});
                        visited[l][c + 1] = 1;
                    }

                    if (c > 0 && !visited[l][c - 1] && picture[l][c - 1] == '.')
                    {
                        q.push({l, c - 1});
                        visited[l][c - 1] = 1;
                    }
                }
            }
        }
    }

    cout << clicks << endl;
}