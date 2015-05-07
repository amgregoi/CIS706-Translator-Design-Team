public class IntSubtract {
    public static void main(String[] args) {
    	int x;
        StaticJavaLib.assertTrue( 2 -  3 == -1);
        StaticJavaLib.assertTrue( 2 - -3 ==  5);
        StaticJavaLib.assertTrue(-2 -  3 == -5);
        StaticJavaLib.assertTrue(-2 - -3 ==  1);

        StaticJavaLib.assertTrue(subtract( 2,  3) == -1);
        StaticJavaLib.assertTrue(subtract( 2, -3) ==  5);
        StaticJavaLib.assertTrue(subtract(-2,  3) == -5);
        StaticJavaLib.assertTrue(subtract(-2, -3) ==  1);
        
        if(2-3 < 5 - (2+3)){
        	x = 5;
        }
        x = 2;
    }

    static int subtract(int i, int j) {
        return i - j;
    }
}



