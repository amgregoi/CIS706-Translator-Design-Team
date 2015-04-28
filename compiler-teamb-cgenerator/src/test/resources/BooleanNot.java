public class BooleanNot {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue(!false == true);
        StaticJavaLib.assertTrue(!true  == false);

        StaticJavaLib.assertTrue(not(false) == true);
        StaticJavaLib.assertTrue(not(true)  == false);
    }

    static boolean not(boolean b) {
        return !b;
    }
}

