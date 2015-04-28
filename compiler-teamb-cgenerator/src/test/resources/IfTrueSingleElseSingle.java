public class IfTrueSingleElseSingle {
    public static void main(String[] args) {
        int a;

        a = 0;
        if (true) {
            a = 1;
        } else {
            a = 2;
        }
        StaticJavaLib.assertTrue(a == 1);
    }
}
