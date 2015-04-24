class Object51 {
	
}

public class TypeCheckFailObjectEqualsBoolean {
    public static void main(String[] args) {
    	Object51 o;
    	boolean b;
    	
    	o = new Object51();
    	b = true;
    	b = o == b;
    }
}