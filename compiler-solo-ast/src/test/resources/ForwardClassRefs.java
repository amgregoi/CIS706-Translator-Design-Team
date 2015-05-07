public class ForwardClassRefs
{
    public static void main(String[] args)
    {
        LateClass lc;
        int x;
        x = 1;
        lc = new LateClass();
        x = lc.next.i + x;
    }

}

class LateClass
{
    public LateClass next;
    public int i;
} 