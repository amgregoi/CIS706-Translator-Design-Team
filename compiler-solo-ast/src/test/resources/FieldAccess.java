class FieldAccessFoo {
    public int i;
}

class FieldAccessBar {
    public int i;
    public FieldAccessFoo f;
}

public class FieldAccess {
    public static void main(String[] args) {
        int i;
        FieldAccessFoo f;
        FieldAccessBar b;

        f = new FieldAccessFoo();
        f.i = 0;
        i = f.i;
        StaticJavaLib.assertTrue(f.i == 0);
        StaticJavaLib.assertTrue(  i == 0);

        b = new FieldAccessBar();
        b.i = 1;
        i = b.i;
        StaticJavaLib.assertTrue(b.i == 1);
        StaticJavaLib.assertTrue(  i == 1);

        b.f = f;
        b.f.i = 2;
        i = b.f.i;
        StaticJavaLib.assertTrue(b.f.i == 2);
        StaticJavaLib.assertTrue(    i == 2);

        b.f.i = 3;
        f.i = b.f.i;
        StaticJavaLib.assertTrue(b.f.i == 3);
        StaticJavaLib.assertTrue(  f.i == 3);

        b.f.i = 4;
        f = b.f;
        StaticJavaLib.assertTrue(f.i == 4);
        
        f.i = 5;
        b.f = f;
        StaticJavaLib.assertTrue(b.f.i == 5);
        
        b.f.i++;
        StaticJavaLib.assertTrue(b.f.i == 6);
    }
}
