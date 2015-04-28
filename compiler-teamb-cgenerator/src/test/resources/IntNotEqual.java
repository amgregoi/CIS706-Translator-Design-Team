public class IntNotEqual {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue(2 != 3 == true);
        StaticJavaLib.assertTrue(3 != 2 == true);
        StaticJavaLib.assertTrue(2 != 2 == false);

        StaticJavaLib.assertTrue(notEqual(2, 3) == true);
        StaticJavaLib.assertTrue(notEqual(3, 2) == true);
        StaticJavaLib.assertTrue(notEqual(2, 2) == false);
    }

    static boolean notEqual(int i, int j) {
        return i != j;
    }
}
    
