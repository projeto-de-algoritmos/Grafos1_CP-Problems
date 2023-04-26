#include <bits/stdc++.h>

using namespace std;

int count_distance_from_first_node(int n, int m)
{
    queue<pair<int, int>> fila;
    vector<bool> visited(10002, false);
    int aux, count;

    fila.push({n, 0});
    visited[n] = true;

    while (!fila.empty())
    {
        tie(aux, count) = fila.front();
        fila.pop();

        if (aux == m)
            break;

        if (aux * 2 <= 10000 && !visited[aux * 2])
        {
            visited[aux * 2] = true;
            fila.push({aux * 2, count + 1});
        }

        if (aux - 1 > 0 && !visited[aux - 1])
        {
            visited[aux - 1] = true;
            fila.push({aux - 1, count + 1});
        }
    }

    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << count_distance_from_first_node(n, m) << endl;
}