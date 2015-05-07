class Object22 {
	
}

class Object23{
	
}

public class TypeCheckFailAssignNamedObjectAToObjectB {
    public static void main(String[] args) {
    	Object23 oA;
    	Object22 oB;
    	
    	oB = new Object22();
    	oA = oB;
    }
}