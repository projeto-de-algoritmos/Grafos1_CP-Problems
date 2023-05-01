#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Constants
{
    N = 1100,
    MAX_WEIGHTS = 10
}; // Definição enum p constantes

string weights_str;
int weights_taken[static_cast<int>(Constants::N)], weight_sum[2];

void find_possible_combinations(int current_weight_index, int total_weights, const string &str)
{
    // Se tiver pego todos os pesos, imprime e da exit
    if (current_weight_index == total_weights + 1)
    {
        cout << "YES\n";
        for (int i = 1; i <= total_weights; i++)
        {
            cout << weights_taken[i] << " ";
        }
        cout << endl;
        exit(0);
    }

    // Seleciona peso
    for (int weight_idx = 1; weight_idx <= static_cast<int>(Constants::MAX_WEIGHTS); weight_idx++)
    {
        if (str[weight_idx - 1] == '1') // verifica disponibilidade
        {
            if (current_weight_index == 1 || weight_idx != weights_taken[current_weight_index - 1])
            {
                if (weight_sum[current_weight_index % 2] + weight_idx > weight_sum[(current_weight_index + 1) % 2]) // Verifica se o peso selecionado é maior que o outro
                {
                    weight_sum[current_weight_index % 2] += weight_idx;                       // Soma o peso atual a soma dos pesos
                    weights_taken[current_weight_index] = weight_idx;                         // Guarda o peso atual
                    find_possible_combinations(current_weight_index + 1, total_weights, str); // Recursiviadde
                    weight_sum[current_weight_index % 2] -= weight_idx;
                }
            }
        }
    }
}

int main()
{
    cin >> weights_str; // pega os pesos
    int num_weights;
    cin >> num_weights;

    for (int i = 1; i <= num_weights; i++)
    {
        weights_taken[i] = -1;
    }

    find_possible_combinations(1, num_weights, weights_str); // função recursiva pra verificar a permutação

    cout << "NO\n";

    return 0;
}
