#include <bits/stdc++.h>

using namespace std;

int main()
{
    int R, C;
    char pasto[550][550];
    char animal;

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> animal;
            pasto[i][j] = animal;
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (pasto[i][j] != 'S')
                continue;

            // Cachorros são ilimitados, a ideia é criar um escudo de cachorros em cada ovelha
            // Se um lobo for vizinho direto de uma ovelha, a solução é impossível
            vector<pair<int, int>> vizinhos{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};

            for (auto par : vizinhos)
            {
                if (pasto[par.first][par.second] == 'W')
                {
                    cout << "No" << endl;
                    return 0;
                }
                if (pasto[par.first][par.second] == '.')
                    pasto[par.first][par.second] = 'D';
            }
        }
    }

    cout << "Yes" << endl;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << pasto[i][j];
        }

        cout << endl;
    }
}