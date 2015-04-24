public class TypeCheckFailIntPlusBadExpression {
    public static void main(String[] args) {
    	int i;
    	
    	i = i + (1 > 2 ? 1 : false);
    }
}