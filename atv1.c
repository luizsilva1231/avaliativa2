#include <stdio.h>

// Protótipos das funções
int validaQuantidade();
float calculaSalario(int quantidade);

// Função principal
int main() {
    int quantidade;
    char continuar;

    do {
        // Solicita a quantidade de peças fabricadas
        quantidade = validaQuantidade();

        // Calcula e mostra o salário do funcionário
        float salario = calculaSalario(quantidade);
        printf("O salário do funcionário é: R$%.2f\n", salario);

        // Pergunta se deseja continuar para o próximo funcionário
        printf("Deseja calcular o salário de outro funcionário? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    return 0;
}

// Função para validar a quantidade de peças fabricadas
int validaQuantidade() {
    int quantidade;

    do {
        printf("Digite a quantidade de peças fabricadas: ");
        scanf("%d", &quantidade);

        if (quantidade < 0) {
            printf("A quantidade de peças deve ser maior ou igual a zero. Tente novamente.\n");
        }

    } while (quantidade < 0);

    return quantidade;
}

// Função para calcular o salário total do funcionário
float calculaSalario(int quantidade) {
    const float salarioBase = 600.0;
    const int limite1 = 50;
    const int limite2 = 80;
    const float adicionalLimite1 = 0.50;
    const float adicionalLimite2 = 0.75;

    float salarioTotal = salarioBase;

    if (quantidade > limite1) {
        salarioTotal += (quantidade - limite1) * adicionalLimite1;

        if (quantidade > limite2) {
            salarioTotal += (quantidade - limite2) * (adicionalLimite2 - adicionalLimite1);
        }
    }

    return salarioTotal;
}