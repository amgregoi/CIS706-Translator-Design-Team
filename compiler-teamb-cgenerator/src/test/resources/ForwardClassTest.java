
public class ForwardClassTest
{
    public static void main(String[] args)
    {
        Foo2 a;
        
        a = new Foo2();
        a.b = new Bar();
        a.b.x = 5;
    }
}

class Foo2
{
    public Bar b;
}

class Bar
{
    public int x;
}
