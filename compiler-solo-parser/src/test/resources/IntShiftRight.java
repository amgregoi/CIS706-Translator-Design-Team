public class IntShiftRight {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue( 2 >> 1 ==  1);
        StaticJavaLib.assertTrue(-2 >> 1 == -1);

        StaticJavaLib.assertTrue(shiftRight( 2, 1) ==  1);
        StaticJavaLib.assertTrue(shiftRight(-2, 1) == -1);
    }

    static int shiftRight(int i, int j){
        return i >> j;
    }
}
    

