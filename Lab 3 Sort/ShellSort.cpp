static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
    int size = end - start;
    int key, j;
    for (int i = 1; i * cur_segment_total + segment_idx < size; ++i) {
        key = start[i * cur_segment_total + segment_idx];
        j = i - 1;
            
        while (j >= 0 && start[j * cur_segment_total + segment_idx] > key) 
        {  
            start[(j + 1) * cur_segment_total + segment_idx] = start[j * cur_segment_total + segment_idx];  
            j = j - 1;  
        }  
        start[(j + 1) * cur_segment_total + segment_idx] = key;
    }
}

static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
     for (int i = num_phases - 1; i >= 0; --i) {
        for (int segment = 0; segment < num_segment_list[i]; ++segment) {
            sortSegment(start, end, segment, num_segment_list[i]);
        } 
        cout << num_segment_list[i] << " segments: ";
        printArray(start, end);
    }
}
