#include <stdio.h>
#include <stdbool.h>

struct node {
int data ;
struct node *next;
};
int s=0; // global variable to store size
struct node *head =NULL;
struct node *tail=NULL;
int size(){
return s;
}

bool empty(){
    if (head==NULL)
        return true ;
    return false ;
}

int value_at(int index)
{
    int i=0;
    if(i>=size)
    {
        printf("NO such element exists ");
        return NULL;
    }
    struct node *n = head;
    int val = n->data;
    while(i!=index)
    {
        n=n->next;
        val=n->data;
    }
    return val ;
}

void push_back(int value){
struct node *n=head;
if(head==NULL)
{
    head=(struct node *)malloc(sizeof(struct node));
    head->data=value;
    s=s+1;
    head->next=NULL;
    return ;
}

while(n->next!= NULL)
{
    n=n->next;
}
n->next=(struct node*)malloc(sizeof(struct node) );
n->next->data=value;
n->next->next=NULL;
s=s+1;
return;
}
int pop_back(){
if(empty())
{
    printf("list empty");
    return;
}
else{
    struct node* n=head;
    while(n->next!=NULL)
    {
        n=n->next;
    }
    int v=n->data;
    n=NULL;
    s=s-1;
    return v;

}
}
int main()
{
    do{
    int data;
    printf("Enter elements of linked list and -1 to exit\n");
    scanf("%d",&data);
    if(data==-1)
        break;
    else
        push_back(data);
}while(1);

printf("THe size is %d\n Last element is %d",size(),pop_back());
}
