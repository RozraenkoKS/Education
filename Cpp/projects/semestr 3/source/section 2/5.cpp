#include <iostream>

int Search_Binary(int arr[], int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])       
			right = midd - 1;    
		else if (key > arr[midd]) 
			left = midd + 1;   
		else                      
			return midd;           

		if (left > right)          
			return -1;
	}
}

int main()
{

	const int size { 12 };
	int array[size] {};
	int key {};
	int index{}; 

	for (int i = 0; i < size; i++)
	{
		array[i] = i + 1;
		std::cout << array[i] << " ";
	}

	std::cin >> key;

	index = Search_Binary(array, 0, size, key);

	if (index >= 0)
		std::cout << "The index is " << index << '\n';
	else
		std::cout << "No key" << '\n';

	return 0;
}