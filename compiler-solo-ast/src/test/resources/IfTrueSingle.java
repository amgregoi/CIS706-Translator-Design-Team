public class IfTrueSingle {
    public static void main(String[] args) {
        int a;

        a = 0;
        if (true) {
            a = 1;
        }
        StaticJavaLib.assertTrue(a == 1);
    }
}
