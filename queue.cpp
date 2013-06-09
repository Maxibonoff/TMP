#include <iostream>
#include <time.h>

using namespace std;
int n; //размерность очереди

struct Queue
{
  int *arr;
	int first;
	int last;
	int count;
};

void Initial (int N, Queue *&p) //Инициализация стека
{
	p = new Queue[N];
	p->arr = new int[N];
	p->first = 0;
	p->last = 0;
	p->count = 0;
}

bool Full (Queue *&p)//Проверка на полноту
{
	if (p->count == n)
		return true;
	else
		return false;
}

bool Empty (Queue *&p)//Проверка на пустоту
{
	if (p->count == 0)
		return true;
	else
		return false;
}

void add (int a, Queue *&p)//Добавление в очередь
{
	if (Full(p) == false)
	{
		p->arr[p->last] = a;
		p->last ++;
		if (p->last == n)
		p->last = 0;
		p->count ++;
	}
	else
		cout <<"Error! Queue is full" << endl;
}

void del (Queue *&p)//Удаление из очереди
{
	if (Empty(p) == false)
	{
		p->arr[p->first] = 0;
		p->first ++;
		if (p->first == n)
		p->first = 0;
		p->count --;
	}
	else
		cout <<"Error! Queue is empty" << endl;
}

void Show(Queue *p) //Вывод очереди
{
	int i,temp; 
	for (i = p->first, temp=0; temp < p->count ; temp ++, i++) 
	{ 
		if (i == n) 
			i = 0; 
		cout << p->arr[i] << " "; 
	}
}

int main()
{
	Queue *p;
	cout <<"Enter dimention of queue: ";
	cin >> n;
	Initial (n, p);// Инициализируем очередь

	for (int i = 0; i < n; i++) //заполняем ее
		add (rand() % 10, p);

	Show (p);
	cout << endl;
	cout <<"After delete" <<endl;
	del (p);
	Show (p);
	return 0;
}

