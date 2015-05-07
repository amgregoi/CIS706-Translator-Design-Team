public class IntLessThan {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue(2 < 3 == true);
        StaticJavaLib.assertTrue(3 < 2 == false);
        StaticJavaLib.assertTrue(2 < 2 == false);

        StaticJavaLib.assertTrue(lessThan(2, 3) == true);
        StaticJavaLib.assertTrue(lessThan(3, 2) == false);
        StaticJavaLib.assertTrue(lessThan(2, 2) == false);
    }
    
    static boolean lessThan(int i, int j) {
        return i < j;
    }
}
    
