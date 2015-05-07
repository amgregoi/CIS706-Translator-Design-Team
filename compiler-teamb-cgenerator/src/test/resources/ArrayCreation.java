public class ArrayCreation
{
    public static void main(String[] args)
    {
        AC[] acs;
        
        acs = new AC[] { null, new AC() };
        acs[1].temp = new int[]{1,2,3};
        acs[1].x = 5;
        
    }
}

class AC
{
    public int[] temp;
    public int x;
}