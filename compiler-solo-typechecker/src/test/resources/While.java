public class While {
    public static void main(String[] args) {
        int i;
		
        i = 0;
        while (i < 10) {
            i++;
        }
        StaticJavaLib.assertTrue(i == 10);
    }
}
