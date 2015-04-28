public class ArrayIndex {
    public static void main(String[] str) 
	{
        
        int i;
        int[] a;
		int[] b;
        
		i = 0;
		a = new int[] {1, 2, 3};
		b = new int[3];
		
        b[i] = a[a[i]];
		b[a[i]*i] = a[b[a[i]]];
		
    }
}
