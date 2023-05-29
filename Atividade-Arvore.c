//criado por Vicente de Souza Lima Neto e Pedro Henrique Alexandria

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *esquerda;
  struct Node *direita;
}; typedef struct Node Node;

//Função para criar Node -> tá igual ao cod da prof.
Node* criarNode(int data) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }
    novoNode->data = data;
    novoNode->esquerda = NULL;
    novoNode->direita = NULL;
    return novoNode;
}

Node* inserirNode(Node *raiz, int data){
    if(raiz == NULL){
        return criarNode(data);
    }
    else{
        if (data <= raiz -> data){
            raiz->esquerda = inserirNode(raiz->esquerda, data);
        }
        else{
            raiz->direita = inserirNode(raiz->direita, data);
        }
        return raiz;
    }
}
int contaNodes(Node *raiz){

   if(raiz == NULL)
        return 0;
   else
        return 1 + contaNodes(raiz->esquerda) + contaNodes(raiz->direita);
}

//exibir em ordem. Filho esquerda > raiz > filho a direita!
void exibirEmOrdem(Node* raiz){
    if(raiz != NULL){
        exibirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->data);
        exibirEmOrdem(raiz->direita);
    }
}

//função de soma dos valores de nós de uma arvore
int somaNos (Node* raiz){
  int cont=0;
  if(raiz != NULL){
    return cont = raiz->data + somaNos(raiz->esquerda) + somaNos(raiz->direita);
	  }
}

//exibir em pre-ordem. Raiz > filho esquerda > filho direita
void exibirPreOrdem(Node* raiz){
    if(raiz != NULL){
        printf("%d ", raiz->data);
        exibirPreOrdem(raiz->esquerda);
        exibirPreOrdem(raiz->direita);
    }
}

//exibir em pos-ordem. Filho esquerda > filho direita > raiz
void exibirPosOrdem(Node* raiz){
    if(raiz != NULL){
        exibirPosOrdem(raiz->esquerda);
        exibirPosOrdem(raiz->direita);
        printf("%d ", raiz->data);
    }
}


//funcao de apoio ao calculo da altura, para determinar o maior node
int maiorNode(int x, int y){
  if(x > y){
    return x;
  }
  else{
    return y;
  }
}

//funcao para altura. 1 + pois conta a raiz!
int calcAltura(Node* raiz){
  
  if((raiz == NULL) || (raiz->esquerda == NULL && raiz->direita == NULL)){
      return 0;
  }
  else{
      return 1 + maiorNode(calcAltura(raiz->esquerda), calcAltura(raiz->direita));
  }
}

void menu(){
    printf("\n1 - Para Criar uma arvore\n");
    printf("2 - Inserir um inteiro na arvore\n");
    printf("3 - Exibir o numero de nos da arvore\n");
    printf("4 - Exibir os dados em ordem\n");
    printf("5 - Exibir os dados em pre-ordem\n");
    printf("6 - Exibir os dados em pos-ordem\n");
    printf("7 - Calcular a soma dos dados na arvore\n"); //falta esse
    printf("8 - Exibir a altura da arvore\n");
    printf("9 - Para encerrar o programa. \n");

}


int main(){
    
    Node* raiz = NULL;
    int choice, data, numNodes, h, somNodes;
    
    do{
        menu();
        printf("\nEscolha uma opcao: ");
        scanf("%d", &choice);
        
        switch(choice){
            
            case 1:
                raiz = NULL;
                printf("Arvore Criada.\n");
                break;
            
            case 2:
                printf("Entre com um numero inteiro: ");
                scanf("%d", &data);
                raiz = inserirNode(raiz, data);
                printf("Dado inserido.\n");
                break;
            
            case 3:
                 numNodes = contaNodes(raiz);
                printf("O numero de elementos da árvore e: %d\n", numNodes);
                break;
                
            case 4:
                printf("Os dados exibidos EmOrdem sao: ");
                exibirEmOrdem(raiz);
                printf("\n");
                break;
            
            case 5:
                printf("Os dados exibidos em Pre-ordem: ");
                exibirPreOrdem(raiz);
                printf("\n");
                break;
                
            case 6:
                printf("Os dados exibidos em Pos-ordem");
                exibirPosOrdem(raiz);
                printf("\n");
                break;
          case 7:
                somNodes = somaNos(raiz);
                printf("A soma dos elementos da arvore e: %d\n", somNodes);
                break;
            
            case 8:
                h = calcAltura(raiz);
                printf("A altura da arvore e: %d\n", h);
                printf("\n");
                break;
                
            case 9:
                printf("Encerrando...\n");
                break;
            
            default:
                printf("Escolha invalida. Tente uma opcao!\n");
                
        }
    }while(choice != 9);
    
    

    return 0;
}
