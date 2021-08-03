#include "SelectionSort.h"
#include <iostream>
//implemente AQUI a funcao sort do SelectionSort
//você DEVE utilizar a função swap para trocar dois elementos de posição

void SelectionSort::sort(Elemento** umVetor, unsigned int quantidadeDeElementos){
    unsigned int i;
    unsigned int k;
    for(i=0; i<quantidadeDeElementos-1;i++){
        unsigned int min = i;
        for(k=i;k<quantidadeDeElementos;k++){
            if(umVetor[k]->_chave < umVetor[min]->_chave){
                min = k;
            }
        }
        if(min != i){
            swap(min,i, umVetor);
        }
    }
    
}