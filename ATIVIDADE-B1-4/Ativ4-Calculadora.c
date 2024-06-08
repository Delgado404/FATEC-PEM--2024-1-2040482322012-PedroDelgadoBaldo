#include <stdio.h>
#include <string.h>
  
#define NUM 2

  float operando[NUM], resultado;
  int operacao;
  char resposta;

  // Módulos das operações 
    int funcSoma(){
      resultado = operando[0] + operando[1];    
    }
    
    int funcSubt(){
      resultado = operando[0] - operando[1];    
    }
    
    int funcDivi(){
      resultado = operando[0] / operando[1];    
    }
    
    int funcMult(){
      resultado = operando[0] * operando[1];    
    }
    
  // Código principal
    int main()
        {
        while(1){
            printf("Entre com os valores da operação... \n -> operador 1: ");
            scanf("%f", &operando[0]);
            getchar();
            
            printf(" -> operador 2: ");
            scanf("%f", &operando[1]);
            getchar();
            
            printf("Agora selecione a operação \n1| adicao\n2| subtracao\n3| divisao (op1/op2)\n4| multiplicacao\n\n -> Operacao: ");
            scanf("%i", &operacao);
            getchar();
            
                if(operacao == 1){
                    funcSoma();
                    printf("resultado da soma: %.2f + %.2f = %.2f", operando[0], operando[1], resultado);
                }
                
                if(operacao == 2){
                    funcSubt();
                    printf("resultado da subtração: %.2f - %.2f = %.2f", operando[0], operando[1], resultado);
                }
                
                if(operacao == 3){
                    while(operando[1] == 0){
                        printf("O divisor não pode ser 0, escolha outro número");
                        scanf("%f", &operando[1]);
                        getchar();
                    }
                    funcDivi();
                    printf("resultado da divisão: %.2f / %.2f = %.2f", operando[0], operando[1], resultado);
                }
                
                if(operacao == 4){
                    funcMult();
                    printf("resultado da multiplicação: %.2f * %.2f = %.2f", operando[0], operando[1], resultado);
                }
            
  // Pergunta nova operação
  
            printf("\nDigite S para sair ou C para continuar... (C/S):");
            scanf("%c", &resposta);
            getchar();
                
            if(resposta == 'C'){
                continue;
            } else {
                printf("adeus");
                return 0;
            }
        }
    }