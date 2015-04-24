public class If {
	public static void main(String[] args) {
		int a;

		a = 0;
		if (true) {
		}
		StaticJavaLib.assertTrue(a == 0);
		
		a = 0;
		if (true) {
			a = 1;
		}
		StaticJavaLib.assertTrue(a == 1);
		
		a = 0;
		if (true) {
			a = 1;
			a = 2;
		}
		StaticJavaLib.assertTrue(a == 2);
		
		a = 0;
		if (true) {
		} else {
		}
		StaticJavaLib.assertTrue(a == 0);
		
		a = 0;
		if (true) {
			a = 1;
		} else {
		}
		StaticJavaLib.assertTrue(a == 1);

		a = 0;
		if (true) {
			a = 1;
		} else {
			a = 2;
		}
		StaticJavaLib.assertTrue(a == 1);

		a = 0;
		if (true) {
			a = 1;
		} else {
			a = 2;
			a = 3;
		}
		StaticJavaLib.assertTrue(a == 1);
		
		a = 0;
		if (false) {
		}
		StaticJavaLib.assertTrue(a == 0);

		a = 0;
		if (false) {
			a = 1;
		}
		StaticJavaLib.assertTrue(a == 0);

		a = 0;
		if (false) {
			a = 1;
		} else {
		}
		StaticJavaLib.assertTrue(a == 0);

		a = 0;
		if (false) {
			a = 1;
		} else {
			a = 2;
		}
		StaticJavaLib.assertTrue(a == 2);

		a = 0;
		if (false) {
			a = 1;
		} else {
			a = 2;
			a = 3;
		}
		StaticJavaLib.assertTrue(a == 3);

	}
}
