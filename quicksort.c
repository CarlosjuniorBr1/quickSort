#include <stdio.h>


void swap(int n1, int n2){
    int aux = n1;
    n1 = n2;
    n2 = aux;
}
int particiona(int *v, int inicio, int fim){
    int pivo = (v[inicio]+ v[fim] + v[(inicio+fim)/2])/3;
    while(inicio<fim){
        while(inicio<fim && v[inicio] <= pivo)
            inicio=inicio+1;
        while(inicio<fim && v[fim]>pivo)
            fim = fim-1;
        
        int aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;
    }
    return inicio;
}

void QuickSort(int * v,int inicio,int fim){
    if(inicio<fim){
        int pos = particiona(v,inicio,fim);
        QuickSort(v,inicio,pos-1);
        QuickSort(v,pos,fim);
    }
}
void printando(int *v, int tam){

    int i;
    for(i=0;i<tam;i++){
        printf("%d, ",v[i]);
    }
    printf("\n");
}

int main(){

    int vet[] = {47,35,12,49,56,25,71,83,5,3,1,70,99,10,61};
    printando(vet,15);
    QuickSort(vet,0,14);
    printf("--------------------------------------------------------\n");
    printando(vet,15);
    return 0;
}