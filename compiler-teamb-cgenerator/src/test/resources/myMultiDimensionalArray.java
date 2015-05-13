class ArrayData
{
	public int value;
}

class MultiArray
{
	public ArrayData[] array;
	public int columns;
}
public class myMultiDimensionalArray {

	public static void main(String[] args) {
		MultiArray array;
		ArrayData data;
		int i;
		int j;
		
		array = ma2DArray(10,10);
		
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
			{
				data = new ArrayData();
				data.value = i * j;
				maPut(array, i, j, data);
			}
		}
		
		for(i = 9; i >= 0; i--)
		{
			for(j = 9; j >= 0; j--)
			{
				maGet(array, i, j);
			}
		}
	}
	
	static MultiArray ma2DArray(int rows, int columns)
	{
		MultiArray newArray;
		
		newArray = new MultiArray();
		newArray.columns = columns;
		newArray.array = new ArrayData[rows * columns];
		
		return newArray;
	}

	static void maPut(MultiArray array, int x, int y, ArrayData data)
	{
		int index;
		
		index = (y * array.columns) + x;
		
		array.array[index] = data;
	}
	
	static ArrayData maGet(MultiArray array, int x, int y)
	{
		int index;
		
		index = (y * array.columns) + x;
		return array.array[index];
	}
}
