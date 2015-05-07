class Object65 {
	
}

class Object66 {
	
}

public class TypeCheckFailObjectAEqualsReturnedObjectB {
    public static void main(String[] args) {
    	Object65 o;
    	
    	o = new Object65();
    	StaticJavaLib.assertTrue(o != returnOtherObject());
    }
    
    static Object66 returnOtherObject(){
    	return new Object66();
    }
}