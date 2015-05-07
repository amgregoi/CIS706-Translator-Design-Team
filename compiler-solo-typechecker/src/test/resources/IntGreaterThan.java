public class IntGreaterThan {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue(2 > 3 == false);
        StaticJavaLib.assertTrue(3 > 2 == true);
        StaticJavaLib.assertTrue(2 > 2 == false);

        StaticJavaLib.assertTrue(greaterThan(2, 3) == false);
        StaticJavaLib.assertTrue(greaterThan(3, 2) == true);
        StaticJavaLib.assertTrue(greaterThan(2, 2) == false);
    }

    static boolean greaterThan(int i, int j) {
        return i > j;
    }
}
