public class BooleanAnd {
    public static void main(String[] args) {
        StaticJavaLib.assertTrue((true  && true)  == true);
        StaticJavaLib.assertTrue((true  && false) == false);
        StaticJavaLib.assertTrue((false && true)  == false);
        StaticJavaLib.assertTrue((false && false) == false);

        StaticJavaLib.assertTrue(and(true,  true)  == true);
        StaticJavaLib.assertTrue(and(true,  false) == false);
        StaticJavaLib.assertTrue(and(false, true)  == false);
        StaticJavaLib.assertTrue(and(false, false) == false);
    }

    static boolean and(boolean b, boolean c) {
        return b && c;
    }
}