#ifndef MINHAARVOREDEBUSCABINARIA_HPP
#define MINHAARVOREDEBUSCABINARIA_HPP

#include "ArvoreDeBuscaBinaria.hpp"
#include <cassert>
#include <utility>

/**
 * @brief Representa uma árvore binária de busca.
 * 
 * @tparam T O tipo de dado guardado na árvore.
 */
template <typename T>
class MinhaArvoreDeBuscaBinaria : public ArvoreDeBuscaBinaria<T>
{

protected:
    int quantHelper(Nodo<T> *chave) const
    {
        if (chave == nullptr)
            return 0;

        return (quantHelper(chave->filhoEsquerda) + 1 + quantHelper(chave->filhoDireita));
    }

    std::optional<Nodo<T> *> contemHelper(Nodo<T> *chave, T value) const
    {
        if (chave == nullptr)
            return std::nullopt;

        if (chave->chave == value)
            return chave;

        if (chave->chave > value)
            return contemHelper(chave->filhoEsquerda, value);

        if (chave->chave < value)
            return contemHelper(chave->filhoDireita, value);

        return std::nullopt;
    }

    void emOrdemHelper(ListaEncadeadaAbstrata<T> *l, Nodo<T> *chave) const
    {
        if (chave != nullptr)
        {
            emOrdemHelper(l, chave->filhoEsquerda);
            l->adicionaNoFim(chave->chave);
            emOrdemHelper(l, chave->filhoDireita);
        }
    }

    void preOrdemHelper(ListaEncadeadaAbstrata<T> *l, Nodo<T> *chave) const
    {
        if (chave != nullptr)
        {
            l->adicionaNoFim(chave->chave);
            preOrdemHelper(l, chave->filhoEsquerda);
            preOrdemHelper(l, chave->filhoDireita);
        }
    }

    void posOrdemHelper(ListaEncadeadaAbstrata<T> *l, Nodo<T> *chave) const
    {
        if (chave != nullptr)
        {
            posOrdemHelper(l, chave->filhoEsquerda);
            posOrdemHelper(l, chave->filhoDireita);
            l->adicionaNoFim(chave->chave);
        }
    }

    void inserirHelper(Nodo<T> *chave, T value)
    {
        if (value < chave->chave)
        {
            if (chave->filhoEsquerda == nullptr)
            {
                Nodo<T> *novaChave = new Nodo<T>();
                novaChave->chave = value;
                novaChave->altura = chave->altura + 1;
                chave->filhoEsquerda = novaChave;
            }
            else
            {
                inserirHelper(chave->filhoEsquerda, value);
            }
        }
        else
        {
            if (chave->filhoDireita == nullptr)
            {
                Nodo<T> *novaChave = new Nodo<T>();
                novaChave->chave = value;
                novaChave->altura = chave->altura + 1;
                chave->filhoDireita = novaChave;
            }
            else
            {
                inserirHelper(chave->filhoDireita, value);
            }
        }
        return;
    }

    bool ehFolha(Nodo<T> *chave)
    {
        if (chave->filhoDireita == nullptr && chave->filhoEsquerda == nullptr)
            return true;

        return false;
    }

    Nodo<T> **buscarPai(T value)
    {
        Nodo<T> **helper = &this->_raiz;

        if ((*helper)->chave == value)
            return nullptr;

        while (true)
        {
            if (value > (*helper)->chave)
            {
                if (value == (*helper)->filhoDireita->chave)
                    return helper;

                helper = &(*helper)->filhoDireita;
            }
            else
            {
                if (value == (*helper)->filhoEsquerda->chave)
                    return helper;

                helper = &(*helper)->filhoEsquerda;
            }
        }
    }

    T removerHelper(Nodo<T> *chave, Nodo<T> *pai, T value)
    {
        if (chave == nullptr)
            return value;
        if (chave->chave > value)
            return removerHelper(chave->filhoEsquerda, chave, value);
        if (chave->chave < value)
            return removerHelper(chave->filhoDireita, chave, value);

        if (ehFolha(chave))
        {
            if (chave->chave == this->_raiz->chave)
            {
                this->_raiz = nullptr;
                delete chave;
                return value;
            }

            if (pai->filhoEsquerda != nullptr)
                if (pai->filhoEsquerda->chave == value)
                    pai->filhoEsquerda = nullptr;

            if (pai->filhoDireita != nullptr)
                if (pai->filhoDireita->chave == value)
                    pai->filhoDireita = nullptr;

            delete chave;
            return value;
        }

        // Caso tenha filho a direita e na esquerda
        else if (chave->filhoDireita != nullptr)
        {
            Nodo<T> *helper = chave->filhoDireita;
            Nodo<T> *paiHelper = chave;
            while (helper->filhoEsquerda != nullptr)
            {
                paiHelper = helper;
                helper = helper->filhoEsquerda;
            }
            chave->chave = helper->chave;
            helper->chave = value;
            return removerHelper(helper, paiHelper, value);
        }

        return value;
    }

    int alturaHelper(Nodo<T> *chave, int altura) const
    {
        if (chave == nullptr)
            return 0;

        int esquerda = 0, direita = 0;

        if (chave->filhoEsquerda != nullptr)
            esquerda = alturaHelper(chave->filhoEsquerda, altura + 1);
        else
            esquerda = altura;

        if (chave->filhoDireita != nullptr)
            direita = alturaHelper(chave->filhoDireita, altura + 1);
        else
            direita = altura;

        if (esquerda >= direita)
        {
            return esquerda;
        }
        else
        {
            return direita;
        }
    }

    void destrutorHelper(Nodo<T> *chave)
    {
        if (chave != nullptr)
        {
            destrutorHelper(chave->filhoDireita);
            destrutorHelper(chave->filhoEsquerda);
            delete chave;
        }
    }

public:
    ~MinhaArvoreDeBuscaBinaria()
    {
        destrutorHelper(this->_raiz);
    };

    /**
     * @brief Verifica se a arvore esta vazia
     * @return Verdade se a arvore esta vazia.
     */
    bool vazia() const
    {
        return this->_raiz == nullptr;
    };

    /**
     * @brief Retornar quantidade de chaves na arvore
     * @return Numero natural que representa a quantidade de chaves na arvore
     */
    int quantidade() const
    {
        if (vazia())
        {
            return 0;
        }

        return quantHelper(this->_raiz);
    };

    /**
     * @brief Verifica se a arvore contem uma chave
     * @param chave chave a ser procurada na arvore
     * @return Verdade se a arvore contem a chave
     */
    bool contem(T chave) const
    {
        if (vazia())
            return false;

        if (std::optional<Nodo<T> *> ostr = contemHelper(this->_raiz, chave); ostr)
            return true;

        return false;
    };

    /**
     * @brief Retorna a altura da (sub)arvore
     * @param chave chave que é raiz da (sub)arvore cuja altura queremos. Se chave é nula, retorna a altura da arvore.
     * @return Numero inteiro representando a altura da (subarvore). Se chave nao esta na arvore, retorna std::nullopt
     */
    std::optional<int> altura(T chave) const
    {
        if (!contem(chave))
            return std::nullopt;

        Nodo<T> *no = contemHelper(this->_raiz, chave).value_or(nullptr);

        if (no != nullptr)
            return alturaHelper(no, 0);

        return alturaHelper(this->_raiz, 0);
    };

    /**
     * @brief Insere uma chave na arvore
     * @param chave chave a ser inserida
     */
    void inserir(T chave)
    {
        if (vazia())
        {
            Nodo<T> *novaChave = new Nodo<T>();
            novaChave->chave = chave;
            novaChave->altura = 0;
            delete this->_raiz;
            this->_raiz = novaChave;
            return;
        }

        inserirHelper(this->_raiz, chave);
    };

    /**
     * @brief Remove uma chave da arvore
     * @param chave chave a removida
     * @return Retorna a chave removida ou nullptr se a chave nao esta na arvore
     */
    void remover(T chave)
    {
        removerHelper(this->_raiz, nullptr, chave);
    };

    /**
     * @brief Busca a chave do filho a esquerda de uma (sub)arvore
     * @param chave chave da arvore que eh pai do filho a esquerda
     * @return Chave do filho a esquerda. Se chave nao esta na arvore, retorna std::nullopt
     */
    std::optional<T> filhoEsquerdaDe(T chave) const
    {
        if (!contem(chave))
            return std::nullopt;

        Nodo<T> *no = contemHelper(this->_raiz, chave).value_or(nullptr);

        if (no->filhoEsquerda != nullptr)
            return no->filhoEsquerda->chave;

        return std::nullopt;
    };

    /**
     * @brief Busca a chave do filho a direita de uma (sub)arvore
     * @param chave chave da arvore que eh pai do filho a direita
     * @return Chave do filho a direita. Se chave nao esta na arvore, retorna nullptr
     */
    std::optional<T> filhoDireitaDe(T chave) const
    {
        if (!contem(chave))
            return std::nullopt;

        Nodo<T> *no = contemHelper(this->_raiz, chave).value_or(nullptr);

        if (no->filhoDireita != nullptr)
            return no->filhoDireita->chave;

        return std::nullopt;
    };

    /**
     * @brief Lista chaves visitando a arvore em ordem
     * @return Lista encadeada contendo as chaves em ordem. 
     */
    ListaEncadeadaAbstrata<T> *emOrdem() const
    {
        ListaEncadeadaAbstrata<T> *lista = new MinhaListaEncadeada<T>();
        emOrdemHelper(lista, this->_raiz);
        return lista;
    };

    /**
     * @brief Lista chaves visitando a arvore em pre-ordem
     * @return Lista encadeada contendo as chaves em pre-ordem. 
     */
    ListaEncadeadaAbstrata<T> *preOrdem() const
    {
        ListaEncadeadaAbstrata<T> *lista = new MinhaListaEncadeada<T>();
        preOrdemHelper(lista, this->_raiz);

        return lista;
    };

    /**
     * @brief Lista chaves visitando a arvore em pos-ordem
     * @return Lista encadeada contendo as chaves em pos ordem. 
     */
    ListaEncadeadaAbstrata<T> *posOrdem() const
    {
        ListaEncadeadaAbstrata<T> *lista = new MinhaListaEncadeada<T>();
        posOrdemHelper(lista, this->_raiz);
        return lista;
    };
};

#endif
