class StackElement
{
    public int i;
}

class StackNode
{
    public StackElement element;

    public StackNode next;
}

class StackClass
{
    public StackNode head;

    public StackNode last;

    public int size;
}

public class myStack {

	public static void main(String[] args) {
		StackClass sc;
        StackElement e;
        int i;

        sc = sNewStack();
        
        for (i = 0; i < 10; i++)
        {
            e = new StackElement();
            e.i = i + 1;
            sPush(sc, e);
        }

        while (sc.size > 0)
        {
            e = sPop(sc);
        }
	}
	
	static StackClass sNewStack()
	{
		StackClass sc;
		
		sc = new StackClass();
		sc.head = new StackNode();
		sc.last = sc.head;
		sc.size = 0;
		
		return sc;
	}
	
	static void sPush(StackClass sc, StackElement newElement)
	{
		StackNode newNode;
		
		newNode = new StackNode();
		newNode.element = newElement;
		newNode.next = sc.last;
		sc.last = newNode;
		sc.size++;
	}
	
	static StackElement sPop(StackClass sc)
	{
		StackNode result;
		
		result = sc.last;
		sc.last = sc.last.next;
        sc.size--;

        return result.element;
	}
	

}
