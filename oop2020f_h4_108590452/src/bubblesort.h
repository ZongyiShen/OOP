#ifndef BUBBLESORT
#define BUBBLESORT
template <class T>
void BubbleSort(T begin, T end){
  int n = end - begin;
  for(int i=n-1;i>0;i--)
    for(int j=0;j<=i-1;j++)
      if(*(begin+j)>*(begin+j+1))
        std::swap(*(begin+j),*(begin+j+1));

}

template <class T, class C>
void BubbleSort(T begin, T end, C compare){
  int n = end - begin;
  for(int i=n-1;i>0;i--)
    for(int j=0;j<=i-1;j++)
      if(compare(*(begin+j), *(begin+j+1)))
        std::swap(*(begin+j),*(begin+j+1));
}
#endif
