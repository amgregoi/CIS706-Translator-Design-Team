public class IfFalseEmpty {
    public static void main(String[] args) {
        int a;

        a = 0;
        if (false) {
        }
        StaticJavaLib.assertTrue(a == 0);
    }
}
