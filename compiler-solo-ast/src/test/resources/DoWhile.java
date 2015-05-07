public class DoWhile {
    public static void main(String[] args) {
        int i;
        
        i = 0;
        do{
            i++;
        } while (i < 10);
        StaticJavaLib.assertTrue(i == 10);
    }
}
