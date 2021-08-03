#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

typedef struct Elemento
{
	int _chave;
	void* _dado;
} Elemento;

class InsertionSort
{
    public :
        void sort(Elemento** umVetor, int quantidadeDeElementos);
};

#endif