#include <stdio.h>

// Protótipos das funções
char validaSexo();
float validaSalario();
void classificaSalario(float salario, char *classificacao);
void mostraClassificacao(float salario, char sexo);

// Função principal
int main() {
    int numAssalariados;
    int abaixoSalarioMinimo = 0;
    int acimaSalarioMinimo = 0;

    printf("Digite o número de assalariados a serem pesquisados: ");
    scanf("%d", &numAssalariados);

    for (int i = 0; i < numAssalariados; i++) {
        printf("\nDados do assalariado #%d:\n", i + 1);

        // Solicita o sexo do assalariado
        char sexo = validaSexo();

        // Solicita o salário do assalariado
        float salario = validaSalario();

        // Classifica o salário em relação ao salário mínimo
        char classificacao[20];
        classificaSalario(salario, classificacao);

        // Mostra os resultados
        mostraClassificacao(salario, sexo);
        
        // Contabiliza quantidade de assalariados abaixo e acima do salário mínimo
        if (salario < 1400.0) {
            abaixoSalarioMinimo++;
        } else {
            acimaSalarioMinimo++;
        }
    }

    // Apresenta a quantidade de assalariados abaixo e acima do salário mínimo
    printf("\nQuantidade de assalariados abaixo do salário mínimo: %d\n", abaixoSalarioMinimo);
    printf("Quantidade de assalariados acima do salário mínimo: %d\n", acimaSalarioMinimo);

    return 0;
}

// Função para validar o sexo
char validaSexo() {
    char sexo;

    do {
        printf("Digite o sexo (M/F): ");
        scanf(" %c", &sexo);

        if (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f') {
            printf("Sexo inválido. Tente novamente.\n");
        }

    } while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f');

    return sexo;
}

// Função para validar o salário
float validaSalario() {
    float salario;

    do {
        printf("Digite o salário (maior que R$1,00): ");
        scanf("%f", &salario);

        if (salario <= 1.0) {
            printf("Salário inválido. Deve ser maior que R$1,00. Tente novamente.\n");
        }

    } while (salario <= 1.0);

    return salario;
}

// Função para classificar o salário em relação ao salário mínimo
void classificaSalario(float salario, char *classificacao) {
    if (salario < 1400.0) {
        sprintf(classificacao, "Abaixo do salário mínimo");
    } else if (salario == 1400.0) {
        sprintf(classificacao, "Igual ao salário mínimo");
    } else {
        sprintf(classificacao, "Acima do salário mínimo");
    }
}

// Função para mostrar a classificação do salário
void mostraClassificacao(float salario, char sexo) {
    char classificacao[20];
    classificaSalario(salario, classificacao);

    printf("Salário: R$%.2f\n", salario);
    printf("Sexo: %s\n", (sexo == 'M' || sexo == 'm') ? "Masculino" : "Feminino");
    printf("Classificação em relação ao salário mínimo: %s\n", classificacao);
}