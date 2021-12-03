#include<iostream>
#include<Windows.h>
#include<conio.h>   //to be able to use getch() method
#include<iomanip>

using namespace std;

class A
{
public:
	int cap = 5;
	int* array=new int[cap];
	int topNum = -1;
	void pop();
	void push(int);
	int top();
	void print();
	int search(int);
};
void A::push(int k)
{
	if (topNum == -1)
	{
		topNum++;
		array[topNum] = k;
	}
	else if (topNum + 1 == cap)
	{
		int* tempArray = new int[cap * 2];
		cap = cap * 2;
		for (int i = 0; i < cap; i++)
		{
			tempArray[i] = array[i];
		}
		array = tempArray;
		topNum++;
		array[topNum] = k;
	}
	else
	{
		topNum++;
		array[topNum] = k;
	}
}

void A::pop()
{
	if (topNum == -1)
	{
		cout << "No element to pop, it is empty\n";
		return;
	}
	//	topNum--;
	else if (topNum < (cap / 2))
	{
		int* auxArray = new int[(cap / 2)+1]; //auxillary
		topNum--;
		for (int i = 0; i < topNum+1; i++)
		{
			auxArray[i] = array[i];
		}
		cap = 1+(cap / 2);
		array = auxArray;
	}
	else
	{
		topNum--;
	}

}

int A::top()
{
	return array[topNum];
}

int A::search(int d)
{
	int index;
	if (topNum == -1)
	{
		cout << "Stack is already empty" << endl;
		return NULL;
	}
	bool flag = false;
	for (int i = 0; i <= topNum; i++)
	{
		if (array[i] == d)
		{
			index = i;
			flag = true;
			break;
		}
	}
	if (flag == true)
	{
		cout << "The element you are looking for is at " << index << ". index (Zero Based) " << endl;
		return index;
	}
	cout << "There is no such element in stack" << endl;
	return NULL;
}


void A::print()
{
	cout << "Cap is " << cap << "\t";
	cout << "Stack is: ";
	for (int i = 0; i < topNum+1; i++)
	{
		if (i % 4 == 0)
		{
			cout << "\n";
			cout << "\t  ";
		}
		cout<<setw(4) << array[i] ;
	}
	cout << "\n\n";

}

int main()
{
	
	A n;
	
	for (int s = 0; s < 21; s++)
	{
		n.push(s);
		n.print();
	}
	{
		cout << setfill('-') << setw(35) << " " << endl;
		cout << " - - - - - Time to pop() - - -\n";
		cout << setfill('-') << setw(35) << " " << endl<<setfill(' ');
	}
	for (int s = 0; s < 21; s++)
	{
		n.pop();
		n.print();

	}
	
	
	system("Pause");
	return 0;
}