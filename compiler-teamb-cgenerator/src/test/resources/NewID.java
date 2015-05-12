class NewIDFoo {
	public NewIDFoo x;
	public NewIDFoo x2;
	public NewIDFoo x3;
	public int x4;
	public boolean y;
}

public class NewID {
    public static void main(String[] args) {
        NewIDFoo f;
        NewIDFoo[] g;
        NewIDFoo[] h;

        f = new NewIDFoo();
        g = new NewIDFoo[4];
        h = new NewIDFoo[] {f, g[0]};
    }
}
    
