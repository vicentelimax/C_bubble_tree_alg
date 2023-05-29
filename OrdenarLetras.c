// criado por: Vicente de Souza Lima Neto e 

#include <stdio.h>
#include <string.h>

//funcao exemplo do material de ordenacao por bolha
void ordernarBolha(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char str[100];
    printf("Entre com a frase: ");
    fgets(str, sizeof(str), stdin); //scanf() nao funcinou pois ele corta no primeiro espaco, nao funciona para frase. fgets() foi a melhor solucao.

    // remove nova linha possivel
    str[strcspn(str, "\n")] = '\0';

    ordernarBolha(str);
    printf("Frase ordenada por letras: %s\n", str);
    return 0;
}