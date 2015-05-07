class Object50 {
	
}

public class TypeCheckFailNegateObject {
    public static void main(String[] args) {
    	Object50 o;
    	
    	o = new Object50();
    	o = -o;
    }
}