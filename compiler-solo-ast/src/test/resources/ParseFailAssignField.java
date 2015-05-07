public class ParseFailAssignField {
	public static void main(String[] args) {
		PFAF o;

		o.p. = null;
	}
}

class PFAF {
  public PFAF p;
}
