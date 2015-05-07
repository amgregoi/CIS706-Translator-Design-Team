public class IfTrueEmpty {
    public static void main(String[] args) {
        int a;

        a = 0;
        if (true) {
        }
        StaticJavaLib.assertTrue(a == 0);
    }
}
