public class IfTrueSingleElseEmpty {
    public static void main(String[] args) {
        int a;

        a = 0;
        if (true) {
            a = 1;
        } else {
        }
        StaticJavaLib.assertTrue(a == 1);
    }
}
