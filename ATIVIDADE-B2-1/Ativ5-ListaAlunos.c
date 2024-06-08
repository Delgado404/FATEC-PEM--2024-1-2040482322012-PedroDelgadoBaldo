// Após inserir o nome de um aluno na função inserir(), deve-se apertar o enter até aparecer a pergunta da nota, pois o fgets armazena junto do nome digitado, um \n.

#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct Aluno {
  char nome[50];
  double notaFinal;
} Aluno;

int selecao, i, add, lista = 0;
Aluno alunos[MAX];
char aux[50];

int inserir() {
  printf("Digite o número de alunos que deseja inserir: ");
  scanf("%i", &add);
  getchar();

  for (int i = 0; i < add; i++) {
    printf("Digite o nome do aluno: ");
    // scanf("%s", alunos[lista].nome);
    fgets(alunos[lista].nome, sizeof(alunos[lista].nome), stdin);
    getchar();
    
    printf("Digite a nota final do aluno: ");
    scanf(" %lf", &alunos[lista].notaFinal);
    getchar();
    
    while(alunos[lista].notaFinal < 0 || alunos[lista].notaFinal > 10){
      printf("nota deve ser entre 0 e 10: ");
      scanf("%lf", &alunos[lista].notaFinal);    
    }
    lista++;
    if(lista > MAX){
      printf("Lista cheia");
    }
  }
}

int bubbleSort(){
  Aluno temp;
  for (int i = 0; i < lista - 1; i++) {
     for (int j = i + 1; j < lista; j++) {
        if (strcmp(alunos[i].nome, alunos[j].nome) > 0) {
              temp = alunos[i];
              alunos[i] = alunos[j];
              alunos[j] = temp;
          }
      }
  }
}
int listar() {
  bubbleSort();
  
  printf("Listagem dos alunos(nome, nota, situação):\n");
  for (int j = 0; j < lista; j++) {
    printf("%i. %s /", j+1, alunos[j].nome);
    printf(" %.2f /", alunos[j].notaFinal);
    if(alunos[j].notaFinal >= 6){
      printf(" Aprovado\n");
    } else {
      printf(" Reprovado\n");
    }
  }
}
int main() {

  while (1) {
    printf("\nMenu\n --> opções\n // 1: Inserir\n // 2: Listar\n // 3: Sair\n");

    printf("Selecione uma opção: ");
    scanf("%i", &selecao);
    printf("\n");
    getchar();

    switch (selecao) {
    case 1:
      inserir();
      break;
    case 2:
      listar();
      break;
    case 3:
      printf("adeus");
      return 0;
      break;
    }
  }
}