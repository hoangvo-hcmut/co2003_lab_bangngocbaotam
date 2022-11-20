template <class T>
void Sorting<T>::oddEvenSort(T *start, T *end)
{
    int size = end - start;
    bool flag = false;
    while (!flag) {
        flag = true;
    
        for (int i = 0; i <= size - 2; i = i + 2) 
        { 
            if (start[i] > start[i+1]) 
            { 
                int temp = start[i];
                start[i] = start[i+1];
                start[i+1] = temp;
                flag = false; 
            } 
        }
        
        for (int i = 1; i <= size - 2; i = i + 2) 
        { 
            if (start[i] > start[i+1]) 
            { 
                int temp = start[i];
                start[i] = start[i+1];
                start[i+1] = temp;
                flag = false; 
            } 
        }
        
        Sorting<int>::printArray(start, end);
    }
}
