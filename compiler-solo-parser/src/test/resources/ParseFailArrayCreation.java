public class ParseFailArrayCreation
{
    public static void main(String[] args)
    {
        AC[] acs;
        
        acs = new AC[2] { null, new AC() };
    }
}

class AC
{
    
}
