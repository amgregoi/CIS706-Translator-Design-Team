public class IntDivide {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue( 2 /  3 ==  0);
        StaticJavaLib.assertTrue( 2 / -3 ==  0);
        StaticJavaLib.assertTrue(-2 /  3 ==  0);
        StaticJavaLib.assertTrue(-2 / -3 ==  0);
        StaticJavaLib.assertTrue( 3 /  2 ==  1);
        StaticJavaLib.assertTrue( 3 / -2 == -1);
        StaticJavaLib.assertTrue(-3 /  2 == -1);
        StaticJavaLib.assertTrue(-3 / -2 ==  1);

        StaticJavaLib.assertTrue(divide( 2,  3) ==  0);
        StaticJavaLib.assertTrue(divide( 2, -3) ==  0);
        StaticJavaLib.assertTrue(divide(-2,  3) ==  0);
        StaticJavaLib.assertTrue(divide(-2, -3) ==  0);
        StaticJavaLib.assertTrue(divide( 3,  2) ==  1);
        StaticJavaLib.assertTrue(divide( 3, -2) == -1);
        StaticJavaLib.assertTrue(divide(-3,  2) == -1);
        StaticJavaLib.assertTrue(divide(-3, -2) ==  1);
    }       
    
    static int divide(int i, int j) {
        return i / j;
    }
}


