#ifndef MINHAPILHA_H
#define MINHAPILHA_H

#include "PilhaAbstrata.h"

template <typename T>
class MinhaPilha :  public PilhaAbstrata<T>
{
    //Implemente aqui as funcões marcadas com virtual na ListaEncadeadaAbstrata
    //Lembre-se de implementar o construtor e destrutor da classe
    
    public:

    MinhaPilha(){
        this->_lista = new MinhaListaEncadeada<T>();
    }
    
    ~MinhaPilha(){
        delete this->_lista;
    }
    
    bool estaVazia(){
        return this->_lista->estaVazia();
    };
    
    int getTamanho(){
        return this->_lista->getTamanho();
    };
    
    T* pop(){
        
        if(getTamanho() == 0){
            throw pilha_vazia_exception();
        }
        
         return this->_lista->retiraDoInicio();
    };
    
    void push(T* umDado){
        this->_lista->adicionaNoInicio(umDado);
    };
    
    bool contem(T* umDado){
         return this->_lista->contem(umDado);
    };
    
    int posicao(T* umDado){
         return this->_lista->posicao(umDado);
    };

};

#endif


