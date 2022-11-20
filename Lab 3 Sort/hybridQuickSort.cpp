template <class T>
T *Sorting<T>::Partition(T *start, T *end)
{
    T p = start[0];    // pivot
	int i = 0;
	int j = end - start;
	do
	{
		do
		{
			i++;
		} while (start[i] <= p);
		do
		{
			j--;
		} while (start[j]>p);
		swap(start[i], start[j]);
	} while (i<j);
	swap(start[i], start[j]);
	swap(start[0], start[j]);
	return start + j;
}

template <class T>
void Sorting<T>::insertionSort(T *start, T *end)
{
    for (int i = 0; i<end - start; i++){
		char min = start[i];
		int id = i;
		for (int j = i; j<end - start; j++){
			if (start[j]<min){
				id = j;
				min = start[j];
			}
		}
		int temp = start[i];
		start[i] = start[id];
		start[id] = temp;
	}
}

template <class T>
void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size)
{
    if (end == start) return;
	int size = end - start;
	if (size < min_size){
		cout << "Insertion sort: ";
		printArray(start, end);
		insertionSort(start, end);
	}
	else{
		cout << "Quick sort: ";
		printArray(start, end);
		T *pivot = Partition(start, end);
		hybridQuickSort(start, pivot,min_size);
		hybridQuickSort(pivot + 1, end,min_size);
	}
}
