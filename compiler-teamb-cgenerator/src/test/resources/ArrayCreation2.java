public class ArrayCreation2
{
	public static void main(String[] args)
	{
		int[] a;
		int b;
		int i;
		
		a = new int[5];
		i = 0;
		StaticJavaLib.assertTrue(true);

		for(i = 0 ; i < 5 ; i++)
		{
			StaticJavaLib.assertTrue(a[i] == (i+1));
		}
	}
}