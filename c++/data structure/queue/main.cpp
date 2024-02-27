#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;
#define Maxsize 50

typedef struct {
	Elemtype data[Maxsize];
	int front; int rear;
}Queue;

void Initqueue(Queue& q)
{
	q.front = q.rear = 0;
}

bool QueueEmpty(Queue q)
{
	if (q.front == q.rear )
		return true;
	return false;

}

bool Input(Queue& q, Elemtype e)
{
	if (q.front == (q.rear + 1))
		return false;
	q.data[q.rear] = e;
	q.rear=(q.rear + 1) % Maxsize;
}

bool Output(Queue& q, Elemtype& e)
{
	if (q.front == (q.rear + 1))
		return false;
	e = q.data[q.front];
	q.front = (q.front + 1) % Maxsize;
}

int main()
{
	Queue q;
	Elemtype e;
	Initqueue(q);
	Input(q, 5);
	Input(q, 6);
	Input(q, 7);
	Input(q, 8);
	Output(q, e);
	printf("%d", e);
	return 0;
}