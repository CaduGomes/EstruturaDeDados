#ifndef FILAABSTRATA_HPP
#define FILAABSTRATA_HPP

#include <exception>

class fila_vazia_exception : public std::exception
{
	virtual const char* what() const throw()
  	{
    	return "fila vazia";
  	}
};

template <typename T>
struct Elemento
{
    struct Elemento* _proximo {nullptr};
    const T& _dado;
};


template <typename T>
class FilaAbstrata
{
protected :
        Elemento<T>* _primeiro {nullptr};
        Elemento<T>* _ultimo {nullptr};
        int _tamanho {0};

    public :
        virtual ~FilaAbstrata() {};
        virtual bool estaVazia() = 0;
        virtual int getTamanho() = 0;
        virtual int posicao(const T& umDado) = 0;
        virtual bool contem(const T& umDado) = 0;
        virtual void enqueue(const T& umDado) = 0;
        virtual const T& dequeue() = 0;
};

#endif