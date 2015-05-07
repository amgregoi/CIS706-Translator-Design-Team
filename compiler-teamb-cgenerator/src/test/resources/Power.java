public class Power
{
    public static void main(String[] args)
    {
        power(3, 2);
    }

    static int power(int m, int n)
    {
        int result;
        int i;

        StaticJavaLib.assertTrue(n >= 1);
        result = 1;
        i = 0;
        while (i < n)
        {
            result = result * m;
            i = i + 1;
        }

        return result;
    }
}
