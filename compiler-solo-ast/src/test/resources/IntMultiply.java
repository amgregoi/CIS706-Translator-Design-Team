public class IntMultiply {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue( 2 *  3 ==  6);
        StaticJavaLib.assertTrue( 2 * -3 == -6);
        StaticJavaLib.assertTrue(-2 *  3 == -6);
        StaticJavaLib.assertTrue(-2 * -3 ==  6);

        StaticJavaLib.assertTrue(multiply( 2,  3) ==  6);
        StaticJavaLib.assertTrue(multiply( 2, -3) == -6);
        StaticJavaLib.assertTrue(multiply(-2,  3) == -6);
        StaticJavaLib.assertTrue(multiply(-2, -3) ==  6);
    }
       
    static int multiply(int i, int j) {
        return i * j;
    }
}
