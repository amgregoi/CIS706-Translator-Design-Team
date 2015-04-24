class A
{
    public int x;
}

class B
{
    public int x;
}

public class SymbolTableTest
{
    public static void main(String[] args)
    {
        A a;
        B b;
        int z;
        a = new A();
        b = new B();
        z = a.x + b.x;
    }
}
