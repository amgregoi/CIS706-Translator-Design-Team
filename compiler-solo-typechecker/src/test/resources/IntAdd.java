public class IntAdd {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue( 2 +  3 ==  5);
        StaticJavaLib.assertTrue( 2 + -3 == -1);
        StaticJavaLib.assertTrue(-2 +  3 ==  1);
        StaticJavaLib.assertTrue(-2 + -3 == -5);

        StaticJavaLib.assertTrue(add( 2,  3) ==  5);
        StaticJavaLib.assertTrue(add( 2, -3) == -1);
        StaticJavaLib.assertTrue(add(-2,  3) ==  1);
        StaticJavaLib.assertTrue(add(-2, -3) == -5);
    }
    
    static int add(int i, int j) {
        return i + j;
    }
}
