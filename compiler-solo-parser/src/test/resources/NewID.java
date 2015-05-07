class NewIDFoo {
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
    
