#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * Next;
}Node;

typedef struct node *List;

List CreatList()
{
    List new;
    new=(List)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d",&(new->data));
    new->Next=NULL;
    return new;
}


void showList(List L)
{
    List p;
    for(p=L;p!=NULL;p=p->Next)
    {
        printf("%d  ",p->data);
    }
}


List insertEnd(List L)
{
    List new,p;
    puts("INSERTION OF ELEMENT AT THE END");
    new=CreatList();
    if(L==NULL)
    {
        //list is empty
        return new;
    }
    //list not empty
    for(p=L;p->Next!=NULL;p=p->Next);
    p->Next=new;
    return L;
}


List insertBeg(List L)
{
    List new;
    puts("INSERTION OF ELEMENT AT THE BEGINNING");
    new=CreatList();
    if(L==NULL)
    {
        return new;
    }
    new->Next=L;
    return new;
}

List deleteEnd(List L)
{
    List p,q;
    if(L!=NULL)
    {
        if(L->Next==NULL)
        {
            p=L;
            free(p);
            return NULL;
        }
        for(q=L,p=L->Next;p->Next!=NULL;q=q->Next,p=p->Next);
        free(p);
        q->Next=NULL;
        return L;
    }else {
        puts("LIST IS EMPTY! ");
    }
}

List deleteBeg(List L)
{
    List p;
    if(L!=NULL)
    {
        if(L->Next==NULL)
        {
            p=L;
            free(p);
            return NULL;
        }
        p=L;
        L=L->Next;
        free(p);
    }else{
       puts("LIST IS EMPTY! ");
    }
    return L;
}



List addAfter(List L)
{
    List new,p;
    int x;
    new=CreatList();
    printf("ENTER X: ");
    scanf("%d",&x);
    printf("INSERTION OF ELEMENT AFTER %d\n\n",x);
    if(L)//if(L!=NULL)
    {
        for(p=L;p&&p->data!=x;p=p->Next);
        if(p==NULL)
        {
            printf("%d Not Found !",x);
        }else{
            new->Next=p->Next;
            p->Next=new;
        }
        return L;
    }
}


int main()
{
   List GINF=NULL;

   GINF=insertEnd(GINF);
   GINF=insertEnd(GINF);
   GINF=insertBeg(GINF);
   printf("\n\n");
   puts("THE LIST:\n");
   showList(GINF);
   printf("\n\n");


   puts("THE LIST after adding:\n");
   GINF=addAfter(GINF);
   printf("\n\n");
   showList(GINF);
   printf("\n\n");

}

