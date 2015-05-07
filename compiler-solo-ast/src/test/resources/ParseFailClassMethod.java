public class ParseFailClassMethod
{
    public static void main(String[] args)
    {
        LateClass lc;
        int x;
        lc = new LateClass();
	x = PFCM.getI();
    }

}

class PFCM
{
    public int i;
    public static int getI() { return i; }
} 
