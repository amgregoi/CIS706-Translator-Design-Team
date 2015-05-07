public class ParseFailDerefNull {
	public static void main(String[] args) {
		PFDN o;

		o = null.next;
	}
}

class PFDN {
	PFDN next;
}
