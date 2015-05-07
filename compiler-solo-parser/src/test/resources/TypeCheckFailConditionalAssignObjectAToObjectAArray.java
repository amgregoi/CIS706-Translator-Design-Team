public class TypeCheckFailConditionalAssignObjectAToObjectAArray {
    public static void main(String[] args) {
    	CAOATOAA o;
    	CAOATOAA[] O;
    	
    	o = new CAOATOAA();
    	O = new CAOATOAA[1];
    	
    	O = false ? O : o;
    }
}

class CAOATOAA {
	
}