class SelectionSortData
{
	public int value;
}

public class SelectionSort {

	public static void main(String[] args) {
		SelectionSortData[] array;
		SelectionSortData data;
		int i;
		int size;
		
		size = 100;
		array = new SelectionSortData[size];
		
		for(i = 0; i < size; i++)
		{
			data = new SelectionSortData();
			data.value = size - i;
			array[i] = data;
		}
		
		ssSort(array, size);
	}
	
	static void ssSort(SelectionSortData[] array, int length)
	{
		int minindex;
		int i;
		int j;
		
		for(j = 0; j < length; j++)
		{
			minindex = j;
			for(i = j+1; i < length; i++)
			{
				if(array[i].value < array[minindex].value)
				{
					minindex = i;
				}
			}
			
			if(minindex != j)
			{
				ssSwap(array[j], array[minindex]);
			}
		}
	}
	
	static void ssSwap(SelectionSortData first, SelectionSortData second)
	{
		int temp;
		
		temp = first.value;
		first.value = second.value;
		second.value = temp;
	}

}
