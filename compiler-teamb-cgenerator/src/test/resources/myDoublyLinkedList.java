
class DLList
{
	public DLNode head;
	public DLNode tail;
	public int size;
}

class DLNode
{
	public DLNode next;
	public DLNode previous;
	public DLElement element;
}

class DLElement
{
	public int value;
}

public class myDoublyLinkedList {

	public static void main(String[] args) {
		DLList dlList;
		DLElement element;
		int i;
		
		dlList = dlNewList();
		
        for (i = 0; i < 10; i++)
        {
        	element = new DLElement();
            element.value = i + 1;
            dlAddElement(dlList, element);
        }
        
        for(i = 0; i < 5; i++)
        {
        	element = new DLElement();
        	element.value = dlGetAt(dlList, 5).value * 2;
        	dlInsertAt(dlList, 5, element);
        }

        i = dlList.size;
        while (dlList.size > 0)
        {
        	element = dlRemoveAt(dlList, 0);
        }
	}
	
	static DLList dlNewList()
	{
		DLList newList;
		
		newList = new DLList();
		newList.head = new DLNode();
		newList.tail = new DLNode();
		
		newList.head.next = newList.tail;
		newList.head.previous = null;
		
		newList.tail.next = null;
		newList.tail.previous = newList.head;
		
		newList.size = 0;
		
		return newList;
	}
	
	static void dlAddElement(DLList dlList, DLElement element)
	{
		DLNode newNode;
		
		newNode = new DLNode();
		newNode.element = element;
		
		newNode.previous = dlList.tail.previous;
		newNode.next = dlList.tail;
		
		dlList.tail.previous.next = newNode;
		dlList.tail.previous = newNode;
		
		dlList.size++;
		
	}
	
	static void dlInsertAt(DLList dlList, int Index, DLElement newElement)
	{
		DLNode indexedNode;
		DLNode newNode;
		int i;
		
		StaticJavaLib.assertTrue(Index < dlList.size);
		
		for(i = 0, indexedNode = dlList.head.next; i < Index; i++)
		{
			indexedNode = indexedNode.next;
		}
		
		newNode = new DLNode();
		
		newNode.element = newElement;
		newNode.previous = indexedNode.previous;
		newNode.next = indexedNode;
		
		indexedNode.previous.next = newNode;
		indexedNode.previous = newNode;
	}
	
	static DLElement dlGetAt(DLList dlList, int Index)
	{
		DLNode indexedNode;
		int i;
		
		StaticJavaLib.assertTrue(Index < dlList.size);
		
		for(i = 0, indexedNode = dlList.head.next; i < Index; i++)
		{
			indexedNode = indexedNode.next;
		}
		
		return indexedNode.element;
	}
	
	static DLElement dlRemoveAt(DLList dlList, int Index)
	{
		DLNode indexedNode;
		DLElement element;
		int i;

		StaticJavaLib.assertTrue(Index < dlList.size);
		
		for(i = 0, indexedNode = dlList.head.next; i < Index; i++)
		{
			indexedNode = indexedNode.next;
		}
		
		element = indexedNode.element;
		indexedNode.previous.next = indexedNode.next;
		
		if(indexedNode.next != null)
		{
			indexedNode.next.previous = indexedNode.previous;
		}
		
		dlList.size--;
		
		return element;
	}

}
