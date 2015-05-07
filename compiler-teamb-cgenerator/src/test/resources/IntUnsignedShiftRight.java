public class IntUnsignedShiftRight {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue( 2 >>> 1 == 1);
        StaticJavaLib.assertTrue(-2 >>> 1 == 2147483647);

        StaticJavaLib.assertTrue(unsignedShiftRight( 2, 1) == 1);
        StaticJavaLib.assertTrue(unsignedShiftRight(-2, 1) == 2147483647);
    }
    
    static int unsignedShiftRight(int i, int j){
        return i >>> j;
    }
}
