public class IfTrueMultiple {	
	public static void main(String[] args) {
        int a;

        a = 0;
        if (true) {
            a = 1;
            a = 2;
        }
        StaticJavaLib.assertTrue(a == 2);
    }
}
