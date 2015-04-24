public class ForBooleanArrayAccessConditional {
    public static void main(String[] args) {
    	boolean[] B;
    	boolean b;
    	
    	b= false;
    	B = new boolean[1];
    	B[0] = false;
    	for (; B[0]; )
    	{
    		b = true;
    	}
    	StaticJavaLib.assertTrue(b == false);
    }
}