#include <bits/stdc++.h>
#include "Sort.h"

using namespace std;

Sort::Sort(int elements_count, int minimum, int maximum)
{
	this->elements_count = elements_count;
    this->elements = new int[elements_count];
    for(int i=0;i < elements_count; i++){
        this->elements[i] = minimum + (rand() % (maximum - minimum + 1));
    }
}

Sort::Sort(initializer_list<int> list)
{
	this->elements_count = (int)list.size();
    this->elements = new int[this->elements_count];

	for(int i=0; i < elements_count; i++){
		
	}
}

Sort::Sort(string list)
{
	// count 
	//	-> functie ce returneaza numarul de aparitii ale unei valori intr-un range
	//	-> primeste 3 parametri: iterator catre primul, catre ultimul element din range si valoarea cautata
	//	ex: count(list.begin(), list.end(), ',')
	// https://www.geeksforgeeks.org/cpp/std-count-cpp-stl/
	//
	// container_type::iterator it -> obiect ce acceseaza elementele unui container.
	// https://www.geeksforgeeks.org/cpp/iterators-c-stl/
	for (string::iterator ch = list.begin(); ch < list.end(); ch++)
	{

	}
}

int main()
{
	// elemente random
	Sort sort1 = Sort(5, 10, 50);
	sort1.BubbleSort(true);
	sort1.Print();

	// lista de initializare
	Sort sort2 = Sort({ 2, 6, 7, 9, 5, 4, 8, 6, 7, 10 });
	sort2.QuickSort();
	sort2.Print();

	// vector
	vector<int> numere = { 2, 6, 9, 7, 3, 6, 4, 8 };
	Sort sort3 = Sort(numere, 8);
	sort3.BubbleSort();
	sort3.Print();

	// nr variabil de parametri
	Sort sort4 = Sort(6, 5, 9, 7, 3, 6, 4);
	sort4.InsertSort(true);
	sort4.Print();

	// string
	Sort sort5 = Sort("10,40,100,5,70");
	sort5.QuickSort(true);
	sort5.Print();

	printf("%d\n", sort5.GetElementsCount());
	printf("%d", sort5.GetElementFromIndex(4));
}