#ifndef MINHA_ARVORE_AVL_HPP
#define MINHA_ARVORE_AVL_HPP

#include "MinhaArvoreDeBuscaBinaria.hpp"

/**
 * @brief Representa uma árvore AVL.
 * 
 * @tparam T O tipo de dado guardado na árvore.
 */
template <typename T>
class MinhaArvoreAVL final : public MinhaArvoreDeBuscaBinaria<T>
{

private:
    void isBalanced(T value, Nodo<T> **pai)
    {
        if (pai == nullptr)
            return;

        while (true)
        {
            int balanc = getBalanceadmento(*pai);

            if (balanc > 1)
            {
                Nodo<T> *filho = (*pai)->filhoEsquerda;
                balanc = getBalanceadmento(filho);
                if (balanc >= 0)
                { // Rotação simples à direita
                    rotDireita(filho, *pai);
                }
                else
                { // Rotação esquerda-direita
                    rotEsqDir(*pai);
                }
            }
            else if (balanc < -1)
            {
                Nodo<T> *filho = (*pai)->filhoDireita;
                balanc = getBalanceadmento(filho);

                if (balanc <= 0)
                { // Rotação simples à esquerda
                    rotEsquerda(filho, *pai);
                }
                else
                { // Rotação direita-esquerda
                    rotDirEsq(*pai);
                }
            }

            if ((*pai)->chave == this->_raiz->chave)
                break;

            pai = MinhaArvoreDeBuscaBinaria<T>::buscarPai((*pai)->chave);
        }
    }

    int getBalanceadmento(Nodo<T> *chave)
    {
        if (chave == nullptr)
            return 0;

        int esq = 0;
        int dir = 0;

        if (chave->filhoDireita != nullptr)
            dir = ((MinhaArvoreDeBuscaBinaria<T>::altura(chave->filhoDireita->chave)).value_or(0)) + 1;
        if (chave->filhoEsquerda != nullptr)
            esq = ((MinhaArvoreDeBuscaBinaria<T>::altura(chave->filhoEsquerda->chave)).value_or(0)) + 1;

        return esq - dir;
    }

    void rotDireita(Nodo<T> *&filho, Nodo<T> *&pai)
    {
        Nodo<T> *helper = filho->filhoDireita;
        pai->filhoEsquerda->filhoDireita = pai;
        pai->filhoEsquerda = helper;

        if (this->_raiz->chave == pai->chave)
        {
            this->_raiz = filho;
        }
    }

    void rotEsquerda(Nodo<T> *&filho, Nodo<T> *&pai)
    {
        Nodo<T> *helper = filho->filhoEsquerda;
        pai->filhoDireita->filhoEsquerda = pai;
        pai->filhoDireita = helper;

        pai = filho;
    }

    void rotEsqDir(Nodo<T> *&pai)
    {
        Nodo<T> *&filho = pai->filhoEsquerda;
        Nodo<T> *chave = pai->filhoEsquerda->filhoDireita;
        Nodo<T> *helper = filho->filhoDireita->filhoEsquerda;

        filho->filhoDireita = helper;
        chave->filhoEsquerda = filho;
        pai->filhoEsquerda = chave->filhoDireita;
        chave->filhoDireita = pai;
        pai = chave;
    }

    void rotDirEsq(Nodo<T> *&pai)
    {
        Nodo<T> *&filho = pai->filhoDireita;
        Nodo<T> *chave = pai->filhoDireita->filhoEsquerda;
        Nodo<T> *helper = filho->filhoEsquerda->filhoDireita;

        filho->filhoEsquerda = helper;
        chave->filhoDireita = filho;
        pai->filhoDireita = chave->filhoEsquerda;
        chave->filhoEsquerda = pai;
        pai = chave;
    }

public:
    void inserir(T value)
    {
        MinhaArvoreDeBuscaBinaria<T>::inserir(value);
        Nodo<T> **pai = MinhaArvoreDeBuscaBinaria<T>::buscarPai(value);
        isBalanced(value, pai);
    }

    void remover(T value)
    {
        Nodo<T> **pai = MinhaArvoreDeBuscaBinaria<T>::buscarPai(value);
        MinhaArvoreDeBuscaBinaria<T>::remover(value);
        isBalanced(value, pai);
    }
};

#endif