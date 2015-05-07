public class TypeCheckFailNullEqualsVoid {
    public static void main(String[] args) {
    	StaticJavaLib.assertTrue(null == returnVoid());
    }
    
    static void returnVoid() {
    	return;
    }
}
