#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "AbstractSort.h"

class SelectionSort : public AbstractSort
{
    public :
        void sort(Elemento** umVetor, unsigned int quantidadeDeElementos);
};

#endif