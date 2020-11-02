#include <iostream>
namespace hp{
    int a[100000]; // array to store elements of heap
    int size=0;
    void shift_up(int key){
        while(key != 0 && a[key]<a[(int)(key-1)/2])
            std::swap(a[key],a[(int)(key-1)/2]);
            key =(key-1)/2;
    }
    void insert(int val)
    {
        size=size+1;
        a[size]=val;
        shift_up(size);
    }
    int get_size()
    {
        return size;
    }
    bool isEmpty(){
    if(size==0)
        return true;
    return false;
    }
    void shift_down(int j)
    {
        int t=j;
        if((j*2+1)<get_size() && a[j*2+1]>a[t] )
           t=j*2+1;
        if(((j*2+2)<get_size() && a[j*2+2]>a[t]))
            t=j*2+2;
        if(t==j)
            return ;
        std::swap(a[j],a[t]);
        shift_down(t);

    }
    int extract_max(){   // extracts and also removes max item
    int item = a[0];
    size=size-1;
    a[0]=a[size];
    size=size-1;
    shift_down(0);
    return item ;
    }
    void remove(int i)
    {
        std::swap(a[i],a[size]);
        size=size-1;
        shift_down(i);
    }
    void heapify(){
                       // create a heap out of array a within O(n) time
           for(int i=(size/2)-1;i>=0;i--)
           {
               shift_down(i);
           }
    }
    void  heap_sort() // sorts the array  in descending order
    {

    for(int i=size-1; i>=0 ;i--)
       {std::swap(a[0],a[size-1]);
       size=size-1;
       shift_down(0);
       }
    }
}
  int main(){
    std::cout<<"HELLO";
    std::cout<<"Enter the size of heap \n";
    std::cin>>hp::size;
    std::cout<<"Enter the elements of heap \n";
    for (int i=0;i<hp::size;i++)
        std::cin>>hp::a[i];
    using namespace hp;
    heapify();
    insert(23);
    insert(-32);
    remove(4);
    int size1=hp::size ;
    heap_sort();
     for (int i=0;i<size1;i++)
        std::cout<<hp::a[i]<<" ";
    }



