#include<stdio.h>
#include<stdlib.h>

#define Maxsize 50
typedef int Elemtype;

typedef struct {
	Elemtype data[Maxsize];
	int length;
}Sqlist;

bool ListInsert(Sqlist& L, int i, Elemtype e)
{
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length > Maxsize)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}	

bool ListDelet(Sqlist& L, int i, Elemtype& e)
{
	if (i > L.length || i < 1)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}

int LocateElem(Sqlist& L, Elemtype e)
{
	int i;
	for (i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}

void PrintList(Sqlist& L)
{
	for (int i = 0; i < L.length; i++)
		printf("%3d", L.data[i]);
	printf("\n");
}

int main()
{
	Sqlist L;
	bool ret;
	Elemtype del;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;
	PrintList(L);

	ret = ListInsert(L, 2, 60);//insert
	if (ret)
		printf("插入成功\n");
	else
		printf("插入失败\n");
	PrintList(L);

	ret = ListDelet(L, 1, del);  //delet
	if (ret)
	{
		printf("删除成功\n");	
		printf("删除的值为%d\n", del);
		PrintList(L);
	}

	else
	{
		printf("删除失败");
	}

	int ele_pos;
	ele_pos = LocateElem(L,30);		// locate

	if (ele_pos)
	{
		printf("查找成功\n");
		printf("元素的位置为%d\n", ele_pos);
	}
	else
	{
		printf("查找失败");
	}

	return 0;
}