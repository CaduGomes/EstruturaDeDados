#include "InsertionSort.h"

//implemente AQUI a funcao sort do Insertion Sort
//você DEVE utilizar a função swap para trocar dois elementos de posição

void InsertionSort::sort(Elemento** umVetor, int quantidadeDeElementos){
    for(int i=1; i < quantidadeDeElementos;i++){
        Elemento* tmp = umVetor[i];
        int k = i-1;
        
        while(k >= 0 && umVetor[k]->_chave > tmp->_chave){
        
            umVetor[k+1] = umVetor[k];
            k = k-1;
        }
        umVetor[k+1] = tmp;
    }
}