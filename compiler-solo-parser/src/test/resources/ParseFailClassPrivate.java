public class ParseFailClassPrivate
{
    public static void main(String[] args)
    {
        PFCP lc;
        int x;
        x = 1;
        lc = new PFCP();
        x = lc.next.i + x;
    }

}

class PFCP
{
    LateClass next;
    public int i;
} 
