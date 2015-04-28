public class IntNegate {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue(  -2 == -2);
        StaticJavaLib.assertTrue(-+-2 ==  2);

        StaticJavaLib.assertTrue(negate( 2) == -2);
        StaticJavaLib.assertTrue(negate(-2) ==  2);
    }
    
    static int negate(int i) {
        return -i;
    }
}
