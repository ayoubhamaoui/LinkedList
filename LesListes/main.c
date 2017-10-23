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

List DeleteAll(List L,int x)
{
    List p,q;
    if(!L)
    {
        return 0;
    }


}

/*List Intersection(List L,List R)
{
    List In=NULL,p,new;
    //on suppose que les listes n'ont pas de doublons
    for(p=L;p;p=p->Next)
    {
        if(Existe(R,p->Next)==1)
        {
            new=(List)malloc(sizeof(Node));
            new->data=p->data;
            new->Next=In;
            In=new;
        }
    }
    return In;
}*/


/*List Unio(List L,List R)
{
    List new=concatener(L,R);
    return Purger(L);
}*/


List concatener(List L,List R)
{
   List p,q;
   if(L==NULL || R==NULL)
   {
       return R;
   }

   for(p=L;p->Next!=NULL;p=p->Next);
   p->Next=R;
   return L;
}


int Exist(List L,int x)//return 1 if x exist
{
    List p;
    for(p=L;p && p->data != x;p=p->Next);
    if(!p)
    {
        return 0;
    }else{
        return 1;
    }
}


List AddAfter(List L)
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


List sortList(List L)//insertion Sort
{
    List p,q;
    int temp;
    for(p=L;p->Next!=NULL;p=p->Next)
    {
        for(q=p->Next;q!=NULL;q=q->Next)
        {
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
    return L;
}


List InsertionSort(List L,int x)
{
    List new=(List)malloc(sizeof(Node));
    new->data=x;
    new->Next=L;
    return sortList(new);
}


List InversList(List L)
{
    List p,q,r;
    if(!L || !L->Next)
    {
        return L;
    }
    //list had two variables
    p=L;
    q=p->Next;
    r=q->Next;
    p->Next=NULL;
    q->Next=p;
    while(r!=NULL)
    {
        p=q;
        q=r;
        r=r->Next;
        q->Next=p;
    }
    return q;
}

/*List InverserAvecRecopie(List L)
{
    List Linv=NULL,p;
    for(p=L;p;p=p->Next)
    {
        Linv=AddBeg(Linv,p->data);
    }
    return Linv;
}*/





int main()
{
   List Entier=NULL;
   List entie=NULL;

   entie=insertEnd(entie);
   entie=insertEnd(entie);
   entie=insertBeg(entie);
   entie=insertBeg(entie);
   entie=insertBeg(entie);
   printf("First list:\n");
   showList(entie);

   printf("\n\n");
   /*Entiers=insertEnd(Entiers);
   Entiers=insertEnd(Entiers);
   Entiers=insertBeg(Entiers);
   printf("seconde List:");showList(entie);*/
  printf("Inverse:::\n");
  entie=InversList(entie);
  showList(entie);

}






























