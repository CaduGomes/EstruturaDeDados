#include "HeapSort.h"
#include <iostream>

//implemente AQUI as funcoes sort e max_heapify do HeapSort
//você DEVE utilizar a função swap para trocar dois elementos de posição

void HeapSort::sort(Elemento** umVetor, int quantidadeDeElementos){
    construirHeapMax(umVetor, quantidadeDeElementos);
    
    for(int i=quantidadeDeElementos-1; i > 0; i--){
        swap(0, i, umVetor);
        max_heapify(umVetor, i, 0);
    }
    

}

void HeapSort::max_heapify(Elemento ** umVetor, int quantidadeDeElementos, int i){
    int esq = i*2 + 1;
    int dir = i*2 + 2;
    int max = i;
    
    if(i < 0 || i >= quantidadeDeElementos){
        throw posicao_invalida_exception();
    }
    
    if(esq < quantidadeDeElementos && umVetor[esq]->_chave > umVetor[max]->_chave){
        max = esq;
    }
    if(dir < quantidadeDeElementos && umVetor[dir]->_chave > umVetor[max]->_chave){
        max = dir;
    }
    if(max != i){
        swap(i,max,umVetor);
        max_heapify(umVetor, quantidadeDeElementos, max);
    }
}

void HeapSort::construirHeapMax(Elemento ** umVetor, int tamanho){
    for(int i = (tamanho/2) - 1; i >= 0; i--){
        max_heapify(umVetor, tamanho, i);
    }
}
