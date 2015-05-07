public class ParseFailNestedIfWhile {
	public static void main(String[] args) {
		int a;

		while (a < 10) {
  		  if (true) 
	            a++;	
		  } else {
		    a = a + 2;
                  }
	        }
	}
}
