//Criado por Vicente de Souza Lima Neto e Pedro ALexandria

#include <stdio.h>
#include <string.h>

//funcao com o algoritmo de selecao, com e funcao alfabetica usei a lib string
void ordenarSelec(char arr[][100], int n){
    int i, j, min_idx;
    char temp[100];
    
    for (i = 0; i < n - 1; i++){
        min_idx = i;
        for(j = i + 1; j < n; j++){
            if(strcmp(arr[j], arr[min_idx]) < 0){ //strcmp compara strings
                min_idx = j;
            }
        }
        //strcpy copia strings
        strcpy(temp, arr[min_idx]);
        strcpy(arr[min_idx], arr[i]);
        strcpy(arr[i], temp);
    }
}

int main() {
    char arr[10][100];
    int n, i;
		
  	//A maneira que achei de ilimitar o uso de dados foi inserir quantos dados incluir
    printf("Entre com o numero de dados para inserir: ");
    scanf("%d", &n);

    printf("Entre %d strings:\n", n);
    for (i = 0; i < n; i++)
        scanf("%s", arr[i]);
    
    ordenarSelec(arr, n);
    
    printf("\nDados inseridos!\n");
    
    //depois de ordenados com a funcao acima e so printar iterando a array ja ordenada
    printf("\nOrdenando as strings:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    return 0;
}