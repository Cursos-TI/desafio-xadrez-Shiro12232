#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001 > nul"); 

    int index;
    
    char *NomeAlunos[3][3] = {
        {"aluno", "mat:30", "pt:10"},
        {"aluno", "mat:20", "his:70"},
        {"aluno", "mat:60", "ing:90"}
    };

    printf("Digite o número do aluno:\n");
    printf("Aluno 0\n");
    printf("Aluno 1\n");
    printf("Aluno 2\n");

    scanf("%d", &index);

    if(index >= 0 && index < 3) {
        printf("As notas de %s são: %s, %s\n", 
               NomeAlunos[index][0], 
               NomeAlunos[index][1], 
               NomeAlunos[index][2]);
    } else {
        printf("Aluno inválido!\n");
    }

    return 0;
}

