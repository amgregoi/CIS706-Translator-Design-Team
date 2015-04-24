class Object18 {

}

public class TypeCheckFailAssignNamedObjectAArrayToObjectA {
	public static void main(String[] args) {
		Object18 o;
		Object18[] O;

		O = new Object18[1];
		o = O;
	}
}