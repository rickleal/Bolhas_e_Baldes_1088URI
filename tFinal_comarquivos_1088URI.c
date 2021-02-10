#include <stdio.h>

/**
 * 
 * Trabalho Prático Final 2020.1
 *
 * MANRICK LEAL DE SOUSA 
 *
 * 25/01/2021
 *
 * 
 */

typedef struct{  
    int tudo[1000000];
}Tabela; 


int vetorIntercalar(int vetor[], int param1, int param2, int param3);
int conceitoMergesort(int vetor[], int param1, int param3);

int main (int argc, char **argv, char **envp){

    Tabela t;

    //Arquivo de entrada
    FILE *fPtr;
    fPtr = fopen(argv[1], "r");

    int sizeVetor[1000000];
    int entrada;

    int i, j = 0, cont = 0;

    //leitura de entrada
    fscanf(fPtr, "%d", &t.tudo[j]);
    while(!feof(fPtr)){
        j++;
        fscanf(fPtr, "%d", &t.tudo[j]);
    }
    
    fclose(fPtr);

    //Arquivo de saida
    FILE *fPtr2;
    fPtr2 = fopen(argv[2], "w");


    do{
        entrada = t.tudo[cont];

        //break
        if(entrada == 0){
            break;
        }

        for(i = 0; i <= entrada; i++){
            sizeVetor[i] = t.tudo[cont+1];
            cont++;
        }

        //resultado conceitoMergesort;
        int merge = conceitoMergesort(sizeVetor, 0, entrada);

        //escrita de saida
        if(merge % 2 == 0){
            fprintf(fPtr2, "%s\n", "Carlos");
        }else{
            fprintf(fPtr2, "%s\n", "Marcelo");
        }

    }while(1);
    
    fclose(fPtr2);

    return 0;
}

int vetorIntercalar(int vetor[], int param1, int param2, int param3){

    int intera; 
    int i, j;
    int aux;

    int vetAux[param3 - param1];

    intera = 0;
    aux = 0;

    i = param1;
    j = param2;

    while(i < param2 && j < param3){

        if(vetor[i] <= vetor[j]){
            vetAux[aux++] = vetor[i++];
        }else{
            vetAux[aux++] = vetor[j++];
            intera += param2 - i;
        }
    }

    while(i < param2){
        vetAux[aux++] = vetor[i++];
    }

    while(j < param3){
        vetAux[aux++] = vetor[j++];
    }

    for(i = param1; i < param3; i++){
        vetor[i] = vetAux[i - param1];
    }

    return intera;
}

int conceitoMergesort(int vetor[], int param1, int param3){

    //rearranjar direita01 e esquerda02
    int position01;
    int position02;

    int divExata;
    int ordenaInt;
    int rFim;

    position01 = 0;
    position02 = 0;
    ordenaInt = 0;

    if(param1 < param3-1){

        //conceito Merge_Sort
        divExata = (param1 + param3)/2;

        position01 = conceitoMergesort(vetor, param1, divExata);
        position02 = conceitoMergesort(vetor, divExata, param3);

        //intercalamento dos vetores
        ordenaInt = vetorIntercalar(vetor, param1, divExata, param3);
    }
    
    rFim = position01 + position02 + ordenaInt;

    return rFim;
}
