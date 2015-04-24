public class TypeCheckFailIntEqualsBoolean {
    public static void main(String[] args) {
    	int i;
    	boolean b;
    	
    	i = 0;
    	b = true;
    	b = b == i;
    }
}