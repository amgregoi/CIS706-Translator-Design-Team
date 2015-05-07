public class IntComplement {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue(~-5 ==  4);
        StaticJavaLib.assertTrue( ~4 == -5);

        StaticJavaLib.assertTrue(complement(-5) ==  4);
        StaticJavaLib.assertTrue(complement( 4) == -5);
    }
    
    static int complement (int i){
        return ~i;
    }
}
