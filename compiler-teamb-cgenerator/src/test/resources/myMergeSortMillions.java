class MergeSort
{
	public MergeSortData[] array;
	public int length2;
	public MergeSortData[] tempMergArr;
}
class MergeSortData
{
	public int i;
}
public class myMergeSortMillions {

	public static void main(String[] args) {
		MergeSort ms;
		MergeSortData[] array;
		MergeSortData data;
		int i;
		int size;
		
		size = 1000;
		array = new MergeSortData[size];
		ms = new MergeSort();
		
		for(i = 0; i < size; i++)
		{
			data = new MergeSortData();
			data.i = size - i;
			array[i] = data;
		}
		
		msMergeSort(ms, array, size);
		
		for(i = 0; i < size; i++)
		{
			StaticJavaLib.assertTrue(ms.array[i].i == i+1);
		}
	}

	static void msMergeSort(MergeSort ms, MergeSortData[] inputArr, int length2) {
        ms.array = inputArr;
        ms.length2 = length2;
        ms.tempMergArr = new MergeSortData[ms.length2];
        msDoSort(ms, 0, ms.length2 - 1);
    }
 
    static void msDoSort(MergeSort ms, int lowerIndex, int higherIndex) {
         int middle;
        if (lowerIndex < higherIndex) {
            middle = lowerIndex + (higherIndex - lowerIndex) / 2;
            msDoSort(ms, lowerIndex, middle);
            msDoSort(ms, middle + 1, higherIndex);
            msMerge(ms, lowerIndex, middle, higherIndex);
        }
    }
 
    static void msMerge(MergeSort ms, int lowerIndex, int middle, int higherIndex) {
    	int i;
    	int j;
    	int k;
    	
        for (i = lowerIndex; i <= higherIndex; i++) {
            ms.tempMergArr[i] = ms.array[i];
        }
        i = lowerIndex;
        j = middle + 1;
        k = lowerIndex;
        while (i <= middle && j <= higherIndex) {
            if (ms.tempMergArr[i].i <= ms.tempMergArr[j].i) {
                ms.array[k] = ms.tempMergArr[i];
                i++;
            } else {
                ms.array[k] = ms.tempMergArr[j];
                j++;
            }
            k++;
        }
        while (i <= middle) {
            ms.array[k] = ms.tempMergArr[i];
            k++;
            i++;
        }
 
    }

}
