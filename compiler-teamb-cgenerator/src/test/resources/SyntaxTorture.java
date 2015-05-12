class Empty {

}

class ManyTypes {
	public int i;

	public boolean b;

	public Empty e;

	public int[] i_array;

	public boolean[] b_array;

	public Empty[] e_array;

}

public class SyntaxTorture {
	public static void main(String[] str) {
		int i;
		int[] i_array;
		int j;
		boolean b;
		boolean[] b_array;
		ManyTypes m;
		ManyTypes[] m_array;
		int x1;
		int x2;

		i = 0;
		j = i;
		b = true;
		if ((i <= 0)) {
			while (~9 <= i && i == -1) {
				i = i + i;
			}
			
			b = false;
			while (true && b) {
				i++;
			}
			
			i--;
			for (i = 0; !(i != 0); i--,i++,i--) {
				i = i >>> +-1;
				returnInt();
				SyntaxTorture.returnVoid();
			}
		}
		
		do {
			i++;
		} while (+7 << ~(-5) == j);
		
		m = new ManyTypes();
		m.b = false;
		i = 4;
		m_array = new ManyTypes[i];
		m_array[0] = m;
		i_array = new int[] { 0, i, 0, 7 };
		j = 0;
		m.i = 0;
		m_array[i_array[m.i]] = m_array[j];
		
		for (i = 2, i = j; j < (+i << 4) && j == i; j++, i--) {
		}

		b = false;
		m = b ? null : ((m));

		b_array = new boolean[] { true };
		m.b_array = b_array;
		b_array = returnBooleanArray(m.b_array);
		m = null;
		b_array = new boolean[] { true };
		x1 = returnInt();
		x2 = returnIntArray()[2];
	}

	static int aa;

	static boolean bb;

	static Empty cc;

	static int[] dd;

	static boolean[] ee;

	static Empty[] ff;

	static int returnInt() {
		int i;
		i = 0;
		return i;
	}

	static boolean returnBoolean(boolean b) {
		boolean c;
		int i;
		c = true;
		i = 0;
		return !!((!c) && (false || true) || (i > 2 && i >= -1) || 3 == i
				&& (+4 != i) || 3 < 5 && ~1 <= -+~2);
	}

	static Empty returnEmpty(int i, Empty e) {
		int j;
		Empty f;
		f = new Empty();
		return f;
	}

	static int[] returnIntArray() {
		int[] i;
		
		i = new int[(1 + ((2 - 3) * 4) / (5 % 6 << 7) >> (8) >>> 9) + 3];
		return i;
	}

	static boolean[] returnBooleanArray(boolean[] b) {
		boolean[] c;
		c = new boolean[] { true, false, false };
		return (c);
	}

	static Empty[] returnObjectArray(int[] i, Empty[] e) {
		return e;
	}

	static void returnVoid() {
	}

	static int g;
}