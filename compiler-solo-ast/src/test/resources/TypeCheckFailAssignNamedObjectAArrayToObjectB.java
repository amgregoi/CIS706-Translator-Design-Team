class Object19 {

}

class Object20{
	
}

public class TypeCheckFailAssignNamedObjectAArrayToObjectB {
	public static void main(String[] args) {
		Object20 o;
		Object19[] O;

		O = new Object19[1];
		o = O;
	}
}