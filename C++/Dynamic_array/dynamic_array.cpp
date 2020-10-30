#include <iostream>
#include <cstdlib>
using namespace std;
class vect
{
public:
    int s;
    int* a= (int*)malloc(16*sizeof(int));
    int cap;
    vect(){
        s=0;
        cap=16;
       }
    int size(){
        return s;
    }
    int capacity(){
    return cap;
    }
    bool is_empty(){
    if (s==0)
        return true;
        return false;
    }
    int at(int index){

    try {
    if(index>(s-1))
       {
           throw -1;
       }
       else
       {

        return a[index];
       }
    }
        catch(int e)
        {
            cout<<"Array overflow";
        }

    }
   void  push(int item)
    {
        if (s==cap)
            resize(cap*2);

                a[s]=item;
                s=s+1;

    }
    void insert(int value,int index){
        if(s==cap)
        {
         resize(cap*2);
        }
        if(index>s)
        {
            cout<<"ERROR";
            return;
        }

        for(int i=s;i>index;i--)
            a[i]=a[i-1];

        a[index]=value;
        s=s+1;

    }
    void prepend(int item){
    insert(item,0);
    }
    int pop()
    {
        try{
            if(s==0)
                throw -1;
            else
            {
                s=s-1;
                 if(s<=cap/4)
                  resize(cap/2);
                return a[s-1];

            }

        }
        catch(int e){
            if(e==-1)
                cout<<"Exception:Array underflow";
        }
    }
    void del(int index)
    {
        try{
        if(index<0 || index >=s)
            throw ;
        else {
            s=s-1;
            for(int i=index;i<s;i++)
                a[i]=a[i+1];
        }
        }
        catch(int e)
        {
            cout<<"EXCEPTION";
        }

        if(s<=cap/4)
            resize(cap/2);
    }
    void remove(int item){
    for(int i=0;i<s;i++)
        if(a[i]==item)
        del(i);
    }
    int find(int item )
    {
        int ind=-1;
        for(int i=0;i<s;i++)
         {

                if(a[i]==item)
                    {
                        ind=i;
                        break;
                    }
         }

    return ind;

    }
    private:
    void resize(int c){
        cap=c;
      a=(int*)realloc(a,cap*sizeof(int));
    }

};

int main()
{
     vect v;
    v.push(12);



}
