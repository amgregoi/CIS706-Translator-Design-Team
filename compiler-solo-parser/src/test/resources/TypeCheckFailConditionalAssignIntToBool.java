public class TypeCheckFailConditionalAssignIntToBool {
    public static void main(String[] args) {
    	boolean b;
    	int i;
     	
    	b = true;
    	i = 4;
    	b = b ? i : b;
    }
}