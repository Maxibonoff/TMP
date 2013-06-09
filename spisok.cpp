#include <iostream>
#include <time.h>

using namespace std;

struct list
{
  int value;
	list* next;

	void InsertHead (int a, list *&p, list *&pF) //добавление элемента в начало списка
	{
		p = new list;
		p->value = a;
		p->next=pF;
		pF=p;

	}

	void GetValue (int n, list*p, list *pF) //получение элемента из списка по его номеру
	{
		for (int i = 0; i < n; i++)
		{
			p = pF;
			pF = pF->next;
		}
		cout <<"value: " <<p->value <<endl;
	}
	
	void remove (int n, list *p, list *pF) //удаление элемента из списка по номеру
	{

		int i;
		for (i = 0; i < (n-1); i++)
		{
			p = pF;
			pF = pF->next;
		}
		pF = pF->next;

		for (i += 2; i < n; i++)
		{
			p = pF;
			pF = pF->next;
		}
	}
};


int main()
{
	srand(time(NULL));
	list *pFirst = NULL; //указатель на начало списка
	list *p; //указатель на список
	int n = 5; //кол-во элементов в списке

	for (int i = 0; i < n; i++) //изначально, заполним список
	{
		p->InsertHead(rand() % 100, p, pFirst);
	}

	//Выводим список
	while (p)
	{
		cout << p->value << endl;
		p = p->next;
	}

	//Выводим значение элемента из списка
	int m;
	cout <<"Enter number of element in list: ";
	cin >> m;
	p->GetValue(m, p, pFirst);

	//Удаляем значение из списка
	int k;
	cout <<"Enter number of element, which you would like to delete: ";
	cin >> k;
	for (int i = 0; i<n; i++)
	{
		if ((i+1) == k)
		{
			p->remove(k+1, p, pFirst);  
		}
		else // выведем список
		{
			p->GetValue(i+1,p,pFirst);
			cout<<"\n";
		}
	}

	return 0;
}
