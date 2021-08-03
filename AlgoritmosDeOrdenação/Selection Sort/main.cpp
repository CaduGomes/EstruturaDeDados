#include "gtest/gtest.h"
#include "SelectionSort.h"

TEST(SelectionSortTest,MelhorCaso){
	Elemento e0, e1, e2;
  e0._chave = 0;
  e1._chave = 1;
  e2._chave = 2;

  Elemento** vetor = new Elemento*[3];
  vetor[0] = &e0;
  vetor[1] = &e1;
  vetor[2] = &e2;

  AbstractSort* sorter = new SelectionSort();
  sorter->sort(vetor, 3);
  ASSERT_EQ(sorter->getSwapsCount(),0);
  
  delete[] vetor;
  delete sorter;
}

TEST(SelectionSortTest,PiorCaso){
	Elemento e0, e1, e2, e3, e4;
  e0._chave = 5;
  e1._chave = 4;
  e2._chave = 3;
  e3._chave = 1;
  e4._chave = 2;

  Elemento** vetor = new Elemento*[5];
  vetor[0] = &e0;
  vetor[1] = &e1;
  vetor[2] = &e2;
  vetor[3] = &e3;
  vetor[4] = &e4;
  
  AbstractSort* sorter = new SelectionSort();
  sorter->sort(vetor, 5);
  ASSERT_EQ(sorter->getSwapsCount(),3);
  
  delete[] vetor;
  delete sorter;
}

TEST(SelectionSortTest,CasoMedio){
	Elemento e0, e1, e2, e3, e4, e5;
  e0._chave = 0;
  e1._chave = 1;
  e2._chave = 2;
  e3._chave = 5;
  e4._chave = 3;
  e5._chave = 4;

  Elemento** vetor = new Elemento*[6];
  vetor[0] = &e0;
  vetor[1] = &e1;
  vetor[2] = &e2;
  vetor[3] = &e3;
  vetor[4] = &e4;
  vetor[5] = &e5;
  
  AbstractSort* sorter = new SelectionSort();
  sorter->sort(vetor, 6);
  ASSERT_EQ(sorter->getSwapsCount(),2);
  
  delete[] vetor;
  delete sorter;
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
