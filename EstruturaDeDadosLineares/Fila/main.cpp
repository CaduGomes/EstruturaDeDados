#include "gtest/gtest.h"
#include "MinhaFila.hpp"

TEST(FilaTest,Init){
	FilaAbstrata<int>* p = new MinhaFila<int>;
	ASSERT_NE(p,nullptr);
	ASSERT_EQ(p->estaVazia(),true);
	delete p;
}

TEST(FilaTest,Enqueue){
    FilaAbstrata<int>* p = new MinhaFila<int>;
	int d1 = 10;
	int d2 = 20;
	int d3 = 30;
	
	p->enqueue(d1);
	ASSERT_EQ(p->getTamanho(),1);
	ASSERT_EQ(p->contem(d1),true);
	ASSERT_EQ(p->posicao(d1),1);
	
	p->enqueue(d2);
	ASSERT_EQ(p->getTamanho(),2);
	ASSERT_EQ(p->contem(d2),true);
	ASSERT_EQ(p->posicao(d2),2);
	ASSERT_EQ(p->posicao(d1),1);

	p->enqueue(d3);
	ASSERT_EQ(p->getTamanho(),3);
	ASSERT_EQ(p->contem(d3),true);
	ASSERT_EQ(p->posicao(d3),3);
	ASSERT_EQ(p->posicao(d2),2);
	ASSERT_EQ(p->posicao(d1),1);
	
	
	delete p;
}

// TEST(FilaTest,Dequeue){
//     FilaAbstrata<int>* p = new MinhaFila<int>;
// 	int d1 = 10;
// 	int d2 = 20;
// 	int d3 = 30;
	
// 	int r;

// 	EXPECT_THROW(p->dequeue(),fila_vazia_exception);
	
// 	p->enqueue(d1);
// 	p->enqueue(d2);
// 	p->enqueue(d3);
	
	
	
// 	r = p->dequeue();
// 	ASSERT_EQ(r, d1);
// 	ASSERT_EQ(p->getTamanho(),2);
// 	ASSERT_EQ(p->posicao(d2),1);
// 	ASSERT_EQ(p->posicao(d3),2);
	
// 	r = p->dequeue();
// 	ASSERT_EQ(r, d2);
// 	ASSERT_EQ(p->getTamanho(),1);
// 	ASSERT_EQ(p->posicao(d3),1);
	
// 	r = p->dequeue();
// 	ASSERT_EQ(r, d3);
// 	ASSERT_EQ(p->getTamanho(),0);
	
// 	EXPECT_THROW(p->dequeue(),fila_vazia_exception);
	
// 	delete p;
// }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
