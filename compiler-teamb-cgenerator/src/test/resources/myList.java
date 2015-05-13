class ListClass{
	public int[] list;
	public int size;
	public int capacity;
}

public class myList {
	public static void main(String[] args)
	{
		ListClass lc;
		
		lc = lNewList();

		lAddElement(lc, 10);
		lAddElement(lc, 9);
		lAddElement(lc, 8);
		lAddElement(lc, 7);
		lAddElement(lc, 6);
		lAddElement(lc, 5);
		lAddElement(lc, 4);
		lAddElement(lc, 3);
		lAddElement(lc, 2);
		lAddElement(lc, 1);
		
		lRemoveFirstElement(lc, 7);
		lRemoveFirstElement(lc,3);
		
	}
	
	static ListClass lNewList()
	{
		ListClass listClass;
		
		listClass = new ListClass();
		listClass.capacity = 3;
		listClass.list = new int[listClass.capacity];
		listClass.size = 0;
		listClass.capacity = 3;
		
		return listClass;
	}
	
	static void lAddElement(ListClass lc, int value)
	{
		int newCapacity;
		int[] tempArray;
		int[] lcList;
		int i;
		
		lcList = lc.list;
		
		if(lc.capacity <= lc.size)
		{
			newCapacity = lc.capacity * 2;
			tempArray = lc.list;
			lc.list = new int[newCapacity];
			for(i = 0; i < lc.size; i++)
			{
				lc.list[i] = tempArray[i];
			}
			lc.capacity = newCapacity;
		}

		lc.list[lc.size] = value;
		lc.size++;
	}
	
	static void lRemoveFirstElement(ListClass lc, int value)
	{
		int index;
		int nextIndex;
		
		index = 0;
		
		while(lc.list[index] != value && index < lc.size)
		{
			index++;
		}
		
		if(lc.list[index] != value){
			return;
		}
		
		for(nextIndex = index+1; nextIndex < lc.size; nextIndex++, index++)
		{
			lc.list[index] = lc.list[nextIndex];
		}
		
		lc.size--;
	}
}
