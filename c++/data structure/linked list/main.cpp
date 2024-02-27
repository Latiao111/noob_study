#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;
#define Maxsize 50;

typedef struct Lnode {
	Elemtype data;
	struct Lnode* next;
}Lnode,*Linklist;

Linklist Creatlist1(Linklist& L)
{
	Lnode* s; int x;
	L = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;
	scanf("%d", &x);
	while (x!=9999)
	{
		s = (Lnode*)malloc(sizeof(Lnode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

Linklist Creatlist2(Linklist& L)
{
	int x;
	L = (Linklist)malloc(sizeof(Lnode));
	Linklist s, r=L;
	scanf("%d", &x);
	while (x!=9999)
	{
		s = (Lnode*)malloc(sizeof(Lnode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

void Printlist(Linklist L)
{
	L = L->next;
	while (L!=NULL)
	{
		printf("%3d ", L->data);
		L = L->next;
	}
	printf("\n");
}

Linklist Getelement(Linklist L, int i)
{	
	int j = 1;
	Linklist p = L->next;

	if (0 == i)
		return L;
	if (i < 0)
		return NULL;
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}

bool ListFrontInsert(Linklist L, int i, Elemtype e)
{
	Linklist p = Getelement(L, i - 1);
	if (NULL == p)
		return false;
	Linklist s = (Linklist)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;

}

bool Listdelete(Linklist L, int i)
{
	Linklist p = Getelement(L, i - 1);
	if (p == NULL)
		return false;
	Linklist q;
	q = p->next;
	p->next = q->next;
	free(q);
	return true;
}

int main()
{	

	Linklist N1;
	Linklist Search;
	//Creatlist1(N1);
	//Printlist(N1);
	Creatlist2(N1);
	

	/*Search=Getelement(N1, 2);
	if (Search)
	{
		printf("查找成功");
		printf("%d", Search->data);
	}
	else
	{
		printf("查找失败");
	}*/



	/*ListFrontInsert(N1, 2, 999);*/
	/*Listdelete(N1, 2);*/
	
	Printlist(N1);
	return 0;

}