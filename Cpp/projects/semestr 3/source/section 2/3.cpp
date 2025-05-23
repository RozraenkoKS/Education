#include <iostream>
#include <vector>
	void merge(int list[], int start, int end, int mid);

	void mergeSort(int list[], int start, int end)
	{
		int mid;
		if (start < end) {

			mid = (start + end) / 2;
			mergeSort(list, start, mid);
			mergeSort(list, mid + 1, end);
			merge(list, start, end, mid);
		}
	}

	void merge(int list[], int start, int end, int mid)
	{
		int mergedList[8];
		int i{};
		int j{};
		int k{};
		i = start;
		k = start;
		j = mid + 1;

		while (i <= mid && j <= end) 
		{
			if (list[i] < list[j]) {
				mergedList[k] = list[i];
				k++;
				i++;
			}
			else {
				mergedList[k] = list[j];
				k++;
				j++;
			}
		}

		while (i <= mid) 
		{
			mergedList[k] = list[i];
			k++;
			i++;
		}

		while (j <= end) 
		{
			mergedList[k] = list[j];
			k++;
			j++;
		}

		for (i = start; i < k; i++) 
		{
			list[i] = mergedList[i];
		}
	}
int main()
	{
		int list[8] = {3, 19, 8, 0, 48, 4, 5, 12};
		mergeSort(list, 0, 7);
		for (int i = 0; i < 8; i++)
		{
			std::cout << list[i] << ' ';
		}
		return 0;
	}
