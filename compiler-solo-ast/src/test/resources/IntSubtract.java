public class IntSubtract {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue( 2 -  3 == -1);
        StaticJavaLib.assertTrue( 2 - -3 ==  5);
        StaticJavaLib.assertTrue(-2 -  3 == -5);
        StaticJavaLib.assertTrue(-2 - -3 ==  1);

        StaticJavaLib.assertTrue(subtract( 2,  3) == -1);
        StaticJavaLib.assertTrue(subtract( 2, -3) ==  5);
        StaticJavaLib.assertTrue(subtract(-2,  3) == -5);
        StaticJavaLib.assertTrue(subtract(-2, -3) ==  1);
    }

    static int subtract(int i, int j) {
        return i - j;
    }
}



