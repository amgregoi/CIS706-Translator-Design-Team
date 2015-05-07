public class ParseFailClassConstructor
{
    public static void main(String[] args)
    {
        PFCC lc;
        int x;
        x = 1;
        lc = new PFCC(x);
        x = lc.i;
    }

}

class PFCC
{
    public int i;
} 
