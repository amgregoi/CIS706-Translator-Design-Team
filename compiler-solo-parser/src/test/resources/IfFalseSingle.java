public class IfFalseSingle {
    public static void main(String[] args) {
        int a;

        a = 0;
        if (false) {
            a = 1;
        }
        StaticJavaLib.assertTrue(a == 0);
    }
}
