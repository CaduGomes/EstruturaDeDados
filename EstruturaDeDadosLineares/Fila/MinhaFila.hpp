#ifndef MINHAFILA_H
#define MINHAFILA_H

#include "FilaAbstrata.hpp"

template <typename T>
class MinhaFila :  public FilaAbstrata<T>
{
    public:
    bool estaVazia(){
        return this->_tamanho == 0;
    };

    int getTamanho(){
        return this->_tamanho;
    };

    int posicao(const T& umDado){
        Elemento<T>* element = this->_primeiro;
        for(int i=1;i <= this->_tamanho;i++){
            if(element->_dado == umDado){
                return i;
            }
            element = element->_proximo;
        }
        
        return -1;
    };

    bool contem(const T& umDado){
        Elemento<T>* element = this->_primeiro;
        for(int i=0;i < this->_tamanho;i++){
            if(element->_dado == umDado){
                return true;
            }
        }
        return false;
    };

    void enqueue(const T& umDado){
        Elemento<T>* NewEl = new Elemento<T>{._proximo = nullptr, ._dado = umDado};
            
        if(getTamanho() == 0){
            this->_primeiro = NewEl;
            this->_tamanho++;
            return;
        }

        if(getTamanho() == 1){
            this->_ultimo = NewEl;
            this->_primeiro->_proximo = this->_ultimo;
            this->_tamanho++;
            return;
        }

        this->_ultimo->_proximo = NewEl;
        this->_ultimo = NewEl;
        this->_tamanho++;
    };

    const T& dequeue(){
        if(this->_tamanho == 0){
            throw fila_vazia_exception();
        }
        Elemento<T>* newEl = this->_primeiro->_proximo;
        const T& dado =  this->_primeiro->_dado;
        delete this->_primeiro;
        this->_primeiro = newEl;
        this->_tamanho--;
        
        return dado;
    };
};

#endif


