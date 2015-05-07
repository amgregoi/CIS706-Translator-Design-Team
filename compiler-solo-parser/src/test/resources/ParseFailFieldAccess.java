public class FieldAccessFoo {
  public FieldAccessFoo next;
}

public class ParseFailFieldAccess {
    public static void main(String[] args) {
        int i;
        FieldAccessFoo f;

        f = new FieldAccessFoo();
        f.next = f.(f.next);
    }
}
