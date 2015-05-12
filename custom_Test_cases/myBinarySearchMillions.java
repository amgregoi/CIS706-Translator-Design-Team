class BinarySearchData
{
	public int i;
}
public class BinarySearchMillions {

	public static void main(String[] args) {
		BinarySearchData[] array;
		BinarySearchData data;
		int size;
		int i;
		int result;
		
		size = 5000000;
		array = new BinarySearchData[size];
		
		for(i = 0; i < size; i++)
		{
			data = new BinarySearchData();
			data.i = i;
			array[i] = data;
		}

		result = BinarySearch(array, 0, size, size/2);
		StaticJavaLib.assertTrue(array[result].i == size/2);
		result = BinarySearch(array, 0, size, size/3);
		StaticJavaLib.assertTrue(array[result].i == size/3);
		result = BinarySearch(array, 0, size, size/4);
		StaticJavaLib.assertTrue(array[result].i == size/4);
		result = BinarySearch(array, 0, size, 2*size/3);
		StaticJavaLib.assertTrue(array[result].i == 2*size/3);
		result = BinarySearch(array, 0, size, 3*size/4);
		StaticJavaLib.assertTrue(array[result].i == 3*size/4);
	}
	
	static int BinarySearch(BinarySearchData[] array, int begin, int end, int value)
	{
		int index;
		int comparisonValue;
		
		
		index = ((end-begin)/2) + begin;
		
		comparisonValue = array[index].i;
		
		if(comparisonValue == value)
		{
			return index;
		}
		else
		{
			if(end-begin == 1)
			{
				return -1;
			}
		}
		
		if(comparisonValue > value)
		{
			return BinarySearch(array, begin, index-1, value);
		}
		else
		{
			return BinarySearch(array, index+1, end, value);
		}
	}

}
