#ifndef MINHALISTAENCADEADA_H
#define MINHALISTAENCADEADA_H

#include "ListaEncadeadaAbstrata.h"

template <typename T>
class MinhaListaEncadeada :  public ListaEncadeadaAbstrata<T>
{
    public:
    MinhaListaEncadeada(){
        this->_tamanho = 0;
        this->_primeiro = nullptr;
    }
    
    ~MinhaListaEncadeada(){
        Elemento<T>* el = this->_primeiro;
        
        for(int i=1; i < this->_tamanho; i++){
                Elemento<T>* removedEl = el;
                el = el->_proximo;
                delete removedEl;
        }
        
        delete el;
    }
    
    bool estaVazia() {
       return this->_tamanho < 1;
    };
    
    int getTamanho() {
        return this->_tamanho;
    };
    
    int posicao(T* umDado) {
        Elemento<T>* element = this->_primeiro;
        for(int i=1;i <= this->_tamanho;i++){
            if(element->_dado == umDado){
                return i;
            }
            element = element->_proximo;
        }
        
        return -1;
    };
    
    bool contem(T* umDado) {
        Elemento<T>* element = this->_primeiro;
        for(int i=1;i <= this->_tamanho;i++){
            if(element->_dado == umDado){
                return true;
            }
        }
        return false;
    };
    
    void adicionaNoInicio(T* umDado) {
        Elemento<T>* element = new Elemento<T>;
        element->_proximo = this->_primeiro;
        element->_dado = umDado;
        
        this->_primeiro = element;
        this->_tamanho++;
    };
    
    void adicionaNaPosicao(T* umDado, int umaPosicao) {
        if(umaPosicao <= 0 || this->_tamanho + 1 < umaPosicao){
            throw posicao_invalida_exception();
        }
        
        Elemento<T>* newElement = new Elemento<T>;
        newElement->_proximo = nullptr;
        newElement->_dado = umDado;
        
        
        if(umaPosicao == 1){
            newElement->_proximo = this->_primeiro;
            this->_primeiro = newElement;
            this->_tamanho++;
            return;
        }
        
        Elemento<T>* el = this->_primeiro;
        
        for(int i=1; i <= this->_tamanho; i++){
            if(i == (umaPosicao - 1)){
                newElement->_proximo = el->_proximo;
                el->_proximo = newElement;
                this->_tamanho++;
                return;
            }
            
            el = el->_proximo;
        }
        
    };
    
    void adicionaNoFim(T* umDado) {
        
    };
    
    T* retiraDoInicio() {
        if(this->_tamanho == 0){
            throw lista_encadeada_vazia_exception();
        }
        Elemento<T>* newEl = this->_primeiro->_proximo;
        T* dado =  this->_primeiro->_dado;
        delete this->_primeiro;
        this->_primeiro = newEl;
        this->_tamanho--;
        
        return dado;
    };
    
    T* retiraDaPosicao(int umaPosicao) {
        if(umaPosicao <= 0 || umaPosicao > this->_tamanho){
            throw posicao_invalida_exception();
        }
        
        if(umaPosicao == 1){
            return retiraDoInicio();
        }
        
        Elemento<T>* el = this->_primeiro;
        
        for(int i=1; i <= this->_tamanho; i++){
            if(i == (umaPosicao - 1)){
                Elemento<T>* newEl =  el->_proximo->_proximo;
                T* dado = el->_proximo->_dado;
                delete el->_proximo;
                el->_proximo = newEl;
                this->_tamanho--;
                return dado;
            }
            
            el = el->_proximo;
        }
        delete el;
        throw std::exception();
    };
    
    T* retiraDoFim() {
        Elemento<T>* element = this->_primeiro;
        for(int i=1;i <= this->_tamanho;i++){
            if(i == this->_tamanho){
                return element->_dado;
            }
            element = element->_proximo;
        }
        
        throw std::exception();
    };
    
    T* retiraEspecifico(T* umDado) {
        return umDado;
    };
};

#endif