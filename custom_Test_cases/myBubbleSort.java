
public class BubbleSort {

	public static void main(String[] args) {
		int[] array;
		int size;
		boolean isSorted;
		
		array = new int[]{1,3,7,9,2,8,37,5,76,0,72,34,87,56,91,81};
		size = 16;
		
		array = BubbleSort(array, size);

		isSorted = (array[0] == 0 &&
				array[1] == 1 &&
				array[2] == 2 &&
				array[3] == 3 &&
				array[4] == 5 &&
				array[5] == 7 &&
				array[6] == 8 &&
				array[7] == 9 &&
				array[8] == 34 &&
				array[9] == 37 &&
				array[10] == 56 &&
				array[11] == 72 &&
				array[12] == 76 &&
				array[13] == 81 &&
				array[14] == 87 &&
				array[15] == 91);
		
		StaticJavaLib.assertTrue(isSorted);
	}
	
	static int[] BubbleSort(int[] inputArray, int arraySize)
	{
		int i;
		int tempSwap;
		boolean swapMade;
		
		swapMade = true;
		
		while(swapMade)
		{
			swapMade = false;
			for(i = 1; i < arraySize; i++)
			{
				if(inputArray[i] < inputArray[i-1])
				{
					swapMade = true;
					tempSwap = inputArray[i];
					inputArray[i] = inputArray[i-1];
					inputArray[i-1] = tempSwap;
				}
			}
		}
		
		return inputArray;
	}

}
