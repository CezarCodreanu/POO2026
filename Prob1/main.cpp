#include <bits/stdc++.h>
#include "Sort.h"

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
	std::vector<int> numere = { 2, 6, 9, 7, 3, 6, 4, 8 };
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