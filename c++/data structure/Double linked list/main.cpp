#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;
#define Maxsize 50;

typedef struct Dnode {
	Elemtype data;
	struct Dnode* prior;
	struct Dnode* next;
}Dnode, * DLinklist;

DLinklist CreateDlinklist1(DLinklist& DL)
{
	DLinklist s; int x;
	DL = (DLinklist)malloc(sizeof(Dnode));
	DL->prior = NULL;
	DL->next = NULL;
	scanf("%d", &x);
	while (x!=9999)
	{
		s = (DLinklist)malloc(sizeof(Dnode));
		s->data = x;
		s->next = DL->next;
		if (DL->next != NULL)
		{
			DL->next->prior = s;
		}
		DL->next = s;
		s->prior = DL;
		scanf("%d", &x);
	}
	return DL;
}


DLinklist CreateDlinklist2(DLinklist& DL)
{
	int x;
	DL = (DLinklist)malloc(sizeof(Dnode));
	DLinklist s, p=DL;
	DL->prior = NULL; DL->next = NULL;
	scanf("%d",&x);
	while (x!=9999)
	{
		s = (DLinklist)malloc(sizeof(Dnode));
		s->data = x;
		p->next = s;
		s->prior = p;
		p = s;
		scanf("%d", &x);
		
	}
	p->next = NULL;
	return DL;
}

DLinklist Getelement(DLinklist DL, int i)
{
	int j = 1;
	DLinklist p = DL->next;
	if (i == 0)
		return DL;
	if (i < 0)
		return NULL;
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}

bool DL_insert(DLinklist DL, int i,Elemtype e)
{
	DLinklist p = Getelement(DL, i - 1);
	if (p == NULL)
		return false;
	DLinklist s;
	s = (DLinklist)malloc(sizeof(Dnode));
	s->data = e;
	if (p->next == NULL)
	{	
		
		s->next = NULL;
		p->next = s;
		s->prior = p;
		return true;
	}
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	s->prior = p;
	return true;

}

bool DL_delete(DLinklist DL, int i)
{
	DLinklist p = Getelement(DL, i - 1);
	if (p == NULL||p->next==NULL)
	{
		return false;
	}

	if (p->next->next == NULL)
	{
		free(p->next);
		p->next = NULL;

		return true;
	}
	DLinklist q = p->next;
	
	q->next->prior = p;
	p->next = q->next;
	free(q);
	q = NULL;
	return true;
}

void Printlist(DLinklist DL)
{
	DL = DL->next;
	while (DL != NULL)
	{
		printf("%3d ", DL->data);
		DL = DL->next;
	}
	printf("\n");
}

int main()
{
	DLinklist N2;
	CreateDlinklist2(N2);
	/*DL_insert(N2,2,90);*/
	DL_delete(N2, 2);
	Printlist(N2);
	return 0;
}
