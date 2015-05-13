class ParallelArray
{
	public int[] integers;
	public boolean[] bools;
	public int size;
}

public class myParallelArrays {

	public static void main(String[] args) {
		ParallelArray array;
		int i;
		int result;
		boolean value;
		
		array = paNewArray(20);
		value = true;
		
		for(i = 0; i < 20; i++)
		{
			paPut(array, i, i*2, value);
			value = !value;
		}
		
		for(i = 0; i < 20; i++)
		{
			result = paGetInt(array, i);
			value = paGetBool(array, i);
		}
		
	}
	
	static ParallelArray paNewArray(int size)
	{
		ParallelArray newArray;
		
		newArray = new ParallelArray();
		newArray.size = size;
		newArray.integers = new int[size];
		newArray.bools = new boolean[size];
		
		return newArray;
	}
	
	static void paPut(ParallelArray array, int index, int integer, boolean bool2)
	{
		int[] x;
		boolean[] y;
		StaticJavaLib.assertTrue(index < array.size);
		x = array.integers;
		y = array.bools;
		x[index] = integer;
		y[index] = bool2;
	}
	
	static int paGetInt(ParallelArray array, int index)
	{
		StaticJavaLib.assertTrue(index < array.size);
		
		return array.integers[index];
	}
	
	static boolean paGetBool(ParallelArray array, int index)
	{
		StaticJavaLib.assertTrue(index < array.size);
		
		return array.bools[index];
	}

}
