class ANIObject {
    public int[] ai;
    public next ANIObject;
    public int i;
}

public class ComplexFieldArrayAccess {
    public static void main(String[] args) {
        ANIObject[] ai;

        ai = new ANIObject[2];
        ai[0] = new ANIObject();
        ai[0].next = ai[1];
        ai[1] = new ANIObject();
        ai[1].next = ai[0];

        ai[ai[0].next.i].next.next.ai[ai[1].next.next.next.i].next.i = 4;
    }
}
