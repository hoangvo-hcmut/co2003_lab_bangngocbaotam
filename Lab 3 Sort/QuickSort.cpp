static T* Partition(T* start, T* end) {
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

static void QuickSort(T* start, T* end) {
    if (start < end)
        {
            T* i = Partition(start, end);    
            cout << i - start << " ";
            QuickSort(start, i);
            QuickSort(i + 1, end);
        }
}
