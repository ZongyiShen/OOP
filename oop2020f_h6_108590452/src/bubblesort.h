#ifndef BUBBLESORT
#define BUBBLESORT
#include <iostream>
using namespace std;

template <class T>
void BubbleSort(T begin, T end);

template <class T, class C>
void BubbleSort(T begin, T end, C compare);

#endif
