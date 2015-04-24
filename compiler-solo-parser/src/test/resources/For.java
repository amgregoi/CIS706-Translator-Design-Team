public class For {
	public static void main(String[] args) {
		missingInitFor();
		forFor();
		multipleFor();
	}

	static void emptyFor() {
		for (;;) {
		}
	}

	static void initOnlyFor() {
		int i;

		for (i = 0;;) {
		}
	}

	static void condOnlyFor() {
		int i;

		i = 0;
		for (; i < 10;) {
		}
	}

	static void incOrDecOnlyFor() {
		int i;

		i = 0;
		for (;; i++) {
		}
	}

	static void missingIncOrDecFor() {
		int i;

		for (i = 0; i < 10;) {
		}
	}

	static void missingCondFor() {
		int i;

		for (i = 0;; i++) {
		}
	}

	static void missingInitFor() {
		int i;

		i = 0;
		for (; i < 10; i++) {
		}
		StaticJavaLib.assertTrue(i == 10);
	}

	static void forFor() {
		int i;

		for (i = 0; i < 10; i++) {
		}
		StaticJavaLib.assertTrue(i == 10);
	}

	static void multipleInitOnlyFor() {
		int i;
		int j;
		int k;

		for (i = 0, j = 0, k = 0;;) {
		}
	}

	static void multipleIncOrDecOnlyFor() {
		int i;
		int j;
		int k;

		i = 0;
		j = 0;
		k = 0;
		for (;; i++, j++, k++) {
		}
	}

	static void multipleFor() {
		int i;
		int j;
		int k;

		for (i = 0, j = 0, k = 0; i < 10; i++, j++, k++) {
		}
		StaticJavaLib.assertTrue(i == 10);
		StaticJavaLib.assertTrue(j == 10);
		StaticJavaLib.assertTrue(k == 10);
	}
}