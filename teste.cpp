#include <iostream>
#include <cmath>
#include <random>

// Função para estimar a CDF da distribuição qui-quadrada
double chiSquaredCDF(double x, int df, int numSamples = 100000) {
    if (x < 0 || df < 1) {
        std::cerr << "Erro: Argumentos inválidos." << std::endl;
        return 0.0;
    }

    std::default_random_engine generator;
    std::chi_squared_distribution<double> distribution(df);

    int count = 0;
    for (int i = 0; i < numSamples; ++i) {
        double sample = distribution(generator);
        if (sample <= x) {
            count++;
        }
    }

    return static_cast<double>(count) / numSamples;
}

int main() {
    int degreesOfFreedom;
    double x;

    // Solicita ao usuário o número de graus de liberdade e o valor para calcular a CDF
    std::cout << "Digite o numero de graus de liberdade: ";
    std::cin >> degreesOfFreedom;
    std::cout << "Digite o valor para calcular a CDF: ";
    std::cin >> x;

    // Calcula e exibe a CDF
    double cdf = chiSquaredCDF(x, degreesOfFreedom);
    std::cout << "CDF: " << cdf << std::endl;

    return 0;
}
