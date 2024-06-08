#include <stdio.h>
#include <string.h>

typedef struct {
  int idProduto;
  char nmProduto[50];
  char dsProduto[100];
  double vlProduto;
  int qtProduto;
} Produto;

int id = 0;

void inserirProduto(Produto *produto) {
  
  produto[id].idProduto = id + 1; 

  printf("Digite o nome do produto: ");
  fgets(produto[id].nmProduto, sizeof(produto[id].nmProduto), stdin);
  produto[id].nmProduto[strcspn(produto[id].nmProduto, "\n" )] = '\0';
  
  printf("Digite a descrição do produto: ");
  fgets(produto[id].dsProduto, sizeof(produto[id].dsProduto), stdin);

  printf("Digite o valor do produto: ");
  scanf("%lf", &produto[id].vlProduto);
  getchar();

  printf("Digite a quantidade do produto: ");
  scanf("%i", &produto[id].qtProduto);
  getchar();

  id++;
}

void bubbleSort(Produto *produto){
  Produto temp;
  for (int i = 0; i < id - 1; i++) {
     for (int j = i + 1; j < id; j++) {
        if (strcmp(produto[i].nmProduto, produto[j].nmProduto) > 0) {
              temp = produto[i];
              produto[i] = produto[j];
              produto[j] = temp;
          }
      }
  }
}

int listarProdutos(Produto *produto){   

  if(id == 0){
    printf("Não há produtos cadastrados\n");
    return 0;
  } 
  
  bubbleSort(produto);
  
    printf("Produtos inseridos: \n");
    printf("|código  nome  valor  quantidade|\n");
     
  //optei por não mostrar a descrição do produto pois ficaria muito grande, apenas uma questão de estética.
    for(int i = 0; i < id; i++){
        printf("%3i. %-10s %.2lf %5i\n", produto[i].idProduto, produto[i].nmProduto, produto[i].vlProduto, produto[i].qtProduto);
    }
}

void comprarProdutos(Produto *produto){
    int escolha, quantidade, item;
    double total = 0;
    char resposta;
  
    listarProdutos(produto);
  
  while(1){
    printf("Selecione o código do produto: \n");
    scanf("%i", &escolha);
    getchar();
  
    printf("Selecione a quantidade: \n");
    scanf("%i", &quantidade);
    getchar();

    if(quantidade > produto[escolha - 1].qtProduto){
      printf("quantidade indisponível\n");
    } else {
      produto[escolha-1].qtProduto -= quantidade;
      total += produto[escolha-1].vlProduto * quantidade;
    }
    printf("Deseja adicionar mais produtos? (s/n): \n");
    scanf("%c", &resposta);
    if(resposta == 'n'){
      printf("Compra finalizada\n total: %.2lf", total);
      break;
    }
    item++;
  }
}

int menu(){
  int selecao;
  
   printf("\nMenu\n --> opções\n | 1: Inserir produtos\n | 2: Mostrar lista de produtos\n | 3: Simular compra(nf)\n | 4: Sair\n");
    printf("Selecione uma opção: ");
    scanf("%i", &selecao);
    getchar();
    printf("\n");

  return selecao;
}

int main() {
  
  Produto produto[100];
  
  while (1) {

    switch (menu()) {
    case 1:
      inserirProduto(produto);
      break;
    case 2:
      listarProdutos(produto);
      break;
    case 3:
      comprarProdutos(produto);
      break;
    case 4:
      printf("Código terminado...");
      return 0;
    }
  }
}