public class IfFalseSingleElseSingle {
    public static void main(String[] args) {
    	int a;
    	
        a = 0;
        if (false) {
            a = 1;
        } else {
            a = 2;
        }
        StaticJavaLib.assertTrue(a == 2);
    }
}
