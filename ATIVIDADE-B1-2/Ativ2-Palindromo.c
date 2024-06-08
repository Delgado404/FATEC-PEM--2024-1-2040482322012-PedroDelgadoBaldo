#include <string.h>
#include <stdio.h>


int main()
{
    char frase[100];
    int tamanho, comeco, final, letrasIguais;
    int ehPal = 1;
    printf("Escreva uma frase:");
    
    fgets(frase, sizeof(frase), stdin);
    final = strlen(frase) - 2;
    
    
    for(comeco = 0; comeco < final; comeco++)
    {
        if(frase[comeco] == ' '){
            comeco++;
        }
        
        if(frase[final] == ' ' || frase[final] == '\n'){
            final--;
        }
        
        if(frase[comeco] != frase[final]){
            ehPal = 0;
            break;
        }
        final--;
    }
    if(ehPal == 1){
     printf("é palindromo");
    } else {
    printf("Não é palindromo");
    }
    
    return 0;
}