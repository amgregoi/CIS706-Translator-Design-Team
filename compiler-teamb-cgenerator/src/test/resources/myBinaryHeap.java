class HeapTree
{
	public HeapNode[] list;
	public int capacity;
	public int size;
	public int head;
	public boolean isEvenIndex;
}

class HeapNode
{
	public int index;
	public int leftChildIndex;
	public int rightChildIndex;
	public int parentIndex;
	public HeapData data;
}

class HeapData
{
	public int value;
}

public class myBinaryHeap {

	public static void main(String[] args) {
		HeapTree heapTree;
		HeapData data;
		int i;
		
		heapTree = hNewHeap();
		
		for(i = 0; i < 20; i++)
		{
			data = new HeapData();
			data.value = i;
			
			hInsertNode(heapTree,data);
		}
		
		do{
			hDeleteMaxNode(heapTree);
		} while(heapTree.size > 0);
	}
	
	static HeapTree hNewHeap()
	{
		HeapTree newTree;
		
		newTree = new HeapTree();
		newTree.capacity = 10;
		newTree.list = new HeapNode[newTree.capacity];
		newTree.head = 1;
		newTree.list[0] = new HeapNode();
		newTree.list[0].parentIndex = 0;
		newTree.size = 1;
		newTree.isEvenIndex = false;
		
		return newTree;
	}
	
	static void hInsertNode(HeapTree heapTree, HeapData data)
	{
		HeapNode newNode;
		HeapNode parent;
		HeapData swapData;
		int parentOffset;
		
		if(heapTree.size >= heapTree.capacity)
		{
			hDoubleListSize(heapTree);
		}
		
		newNode = new HeapNode();
		newNode.index = heapTree.size;
		newNode.leftChildIndex = 2 * newNode.index;
		newNode.rightChildIndex = newNode.leftChildIndex + 1;
		
		parentOffset = newNode.index;
		if(!heapTree.isEvenIndex){
			parentOffset = parentOffset - 1;
		}
		
		if(heapTree.size == 1)
		{
			newNode.parentIndex = 0;
		}
		else
		{
			newNode.parentIndex = parentOffset / 2;
		}
		newNode.data = data;
		
		heapTree.list[heapTree.size] = newNode;
		
		heapTree.size++;
		heapTree.isEvenIndex = !heapTree.isEvenIndex;

		if(newNode.parentIndex > 0)
		{
			parent = heapTree.list[newNode.parentIndex];
			
			while(newNode.parentIndex > 0 && newNode.data.value > parent.data.value)
			{
				swapData = newNode.data;
				newNode.data = parent.data;
				parent.data = swapData;
				
				newNode = parent;
				parent = heapTree.list[newNode.parentIndex];
			}
		}
	}
	
	static void hDoubleListSize(HeapTree heapTree)
	{
		HeapNode[] newList;
		int i;
		
		newList = new HeapNode[heapTree.capacity * 2];
		heapTree.capacity = heapTree.capacity * 2;
		
		for(i = 0; i < heapTree.size; i++)
		{
			newList[i] = heapTree.list[i];
		}
		
		heapTree.list = newList;
	}
	
	static void hDeleteMaxNode(HeapTree heapTree)
	{
		HeapNode lastElement;
		HeapNode balanceNode;
		HeapNode leftNode;
		HeapNode rightNode;
		HeapData swapData;
		
		if(heapTree.size == 1){
			heapTree.list[1] = null;
			heapTree.size = 0;
			return;
		}
		
		lastElement = heapTree.list[heapTree.size-1];
		heapTree.list[heapTree.size-1] = null;
		heapTree.size--;
		heapTree.list[1].data = lastElement.data;
		
		balanceNode = heapTree.list[1];
		leftNode = null;
		rightNode = null;
		
		while(balanceNode.leftChildIndex < heapTree.size)
		{
			leftNode = heapTree.list[balanceNode.leftChildIndex];
			if(balanceNode.rightChildIndex < heapTree.size){
				rightNode = heapTree.list[balanceNode.rightChildIndex];
			}
			else{
				rightNode = null;
			}
			
			if(balanceNode.data.value < leftNode.data.value)
			{
				swapData = balanceNode.data;
				balanceNode.data = leftNode.data;
				leftNode.data = swapData;
				balanceNode = leftNode;
			}
			else{
				if(balanceNode.data.value < rightNode.data.value)
				{
					swapData = balanceNode.data;
					balanceNode.data = rightNode.data;
					rightNode.data = swapData;
					balanceNode = rightNode;
				}
			}
		}
		
	}

}
