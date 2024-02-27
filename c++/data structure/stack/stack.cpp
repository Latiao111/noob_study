#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;
#define Maxsize 50

typedef struct 
{	
	Elemtype data[Maxsize];
	int top;
}Sqstack;

void Initstack(Sqstack&s)
{
	s.top = -1;
}

bool Stackempty(Sqstack s)
{
	if (-1 == s.top)
		return true;
	return false;
}

bool Input(Sqstack& s, Elemtype i)
{	
	if (Maxsize - 1 == s.top)
		return false;
	s.data[++s.top] = i;
	return true;
}

bool Getop(Sqstack s,Elemtype &x)
{
	if (Stackempty(s))
		return false;
	x = s.data[s.top];
	return true;
}

bool Pop(Sqstack& s, Elemtype& x)
{
	if (Stackempty(s))
	{
		return false;
	}
	x = s.data[s.top--];
	return true;
}



int main()
{
	Sqstack s;
	Initstack(s);

	return 0;
}