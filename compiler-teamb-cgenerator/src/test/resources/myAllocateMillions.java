class AllocationArray
{
	public AllocationData[] array;
	public int size;
	public int lastIndex;
}

class AllocationData
{
	public int value;
}
public class myAllocateMillions {

	public static void main(String[] args) {
		AllocationArray array;
		AllocationData data;
		int size;
		int i;
		
		size = 1000000;
		
		array = aaNewArray(size);
		
		for(i = 0; i < size; i++)
		{
			data = new AllocationData();
			data.value = i;
			aaAddElement(array, data);
		}
		
		for(i = 0; i < size; i++)
		{
			data = aaRemoveElement(array);
		}
	}
	
	static AllocationArray aaNewArray(int size)
	{
		AllocationArray aArray;
		
		aArray = new AllocationArray();
		aArray.array = new AllocationData[size];
		aArray.size = size;
		aArray.lastIndex = 0;
		
		return aArray;
	}
	
	static void aaAddElement(AllocationArray array, AllocationData data)
	{
		StaticJavaLib.assertTrue(array.lastIndex < array.size);
		
		array.array[array.lastIndex] = data;
		array.lastIndex++;
	}
	
	static AllocationData aaRemoveElement(AllocationArray array)
	{
		AllocationData data;
		
		StaticJavaLib.assertTrue(array.lastIndex >= 0);
		
		array.lastIndex--;
		
		data = array.array[array.lastIndex];
		
		array.array[array.lastIndex] = null;
		
		return data;
	}

}
