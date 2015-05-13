class HeapSort
{
	public int length2;
}

class HeapSortData
{
	public int i;
}

public class myHeapSortMillions {

	public static void main(String[] args) {
		HeapSort hs;
		HeapSortData[] array;
		HeapSortData data;
		int size;
		int i;
		
		size = 1000000;
		array = new HeapSortData[size];
		hs = new HeapSort();
		
		for(i = 0; i < size; i++)
		{
			data = new HeapSortData();
			data.i = size - i;
			array[i] = data;
		}
		
		sort(hs, array, size);
		
		for(i = 0; i < size; i++)
		{
			StaticJavaLib.assertTrue(array[i].i == i+1);
		}
	}
    static void sort(HeapSort hs, HeapSortData[] arr, int length2)
    {       
    	int i;
    	
        heapify(hs, arr, length2);        
        for (i = hs.length2; i > 0; i--)
        {
            swap(arr,0, i);
            hs.length2 = hs.length2-1;
            maxheap(hs, arr, 0);
        }
    }     

    static void heapify(HeapSort hs, HeapSortData[] arr, int length2)
    {
    	int i;
        hs.length2 = length2-1;
        for (i = hs.length2/2; i >= 0; i--)
        {
            maxheap(hs, arr, i);     
        }
    }
    
    static void maxheap(HeapSort hs, HeapSortData[] arr, int i)
    { 
    	int left;
    	int right;
    	int max;
    	
        left = 2*i ;
        right = 2*i + 1;
        max = i;
        if (left <= hs.length2 && arr[left].i > arr[i].i)
        {
            max = left;
        }
        if (right <= hs.length2 && arr[right].i > arr[max].i)  
        {
            max = right;
        }
 
        if (max != i)
        {
            swap(arr, i, max);
            maxheap(hs, arr, max);
        }
    }    
    
    static void swap(HeapSortData[] arr, int i, int j)
    {
        int tmp;
        
        tmp= arr[i].i;
        arr[i].i = arr[j].i;
        arr[j].i = tmp; 
    }    

}
