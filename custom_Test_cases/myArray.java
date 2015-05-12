class ArrayManager
{
	public ArrayManagerData[] array;
	public int length;
}

class ArrayManagerData
{
	public int value;
}

public class Array {
	public static void main(String[] args){
		ArrayManager arrayManager;
		ArrayManagerData data;
		int i;

		arrayManager = amNewArrayManager(15);
		
		for(i = 0; i < 15; i++)
		{
			data = new ArrayManagerData();
			data.value = i * 15;
			amInsertValue(arrayManager, i, data);
		}
		
		for(i = 0; i < 15; i++)
		{
			data = amGetValue(arrayManager, i);
		}
		
		for(i = 0; i < 15; i++)
		{
			if(i <= 7)
			{
				data = amPullValue(arrayManager, i);
			}
			else
			{
				amRemoveValue(arrayManager, i);
			}
		}
	}
	
	static ArrayManager amNewArrayManager(int size)
	{
		ArrayManager arrayManager;
		
		arrayManager = new ArrayManager();
		
		arrayManager.array = new ArrayManagerData[size];
		arrayManager.length = size;
		
		return arrayManager;
	}
	
	static void amInsertValue(ArrayManager array, int index, ArrayManagerData data)
	{
		array.array[index] = data;
	}
	
	static void amRemoveValue(ArrayManager array, int index)
	{
		array.array[index] = null;
	}
	
	static ArrayManagerData amGetValue(ArrayManager array, int index)
	{
		return array.array[index];
	}
	
	static ArrayManagerData amPullValue(ArrayManager array, int index)
	{
		ArrayManagerData data;
		
		data = amGetValue(array, index);
		amRemoveValue(array, index);
		
		return data;
	}
}
