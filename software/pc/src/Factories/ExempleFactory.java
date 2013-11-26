/* ============================================================================
 * 								Exemple Factory 
 * ============================================================================
 * 
 * Just an exemple of what can ben  done with the Factory interface.
 * This exemple is a singleton, because most factories are in real world 
 * applications.
 * Author : Martial
 */

/*
 *	TODO : 	See how to transmit constructors arguments trough MakeFrom methods 
 *			(templates ??)
 */

public class ExempleFactory implements AbstractFactory
{
	// ========================
	// Singleton matters :
	// ========================
	
	// Define the only instance of this factory
	private static final ExempleFactory INSTANCE = new ExempleFactory();
	 
	// Factory's getter 
    public static ExempleFactory getInstance() 
    {
        return INSTANCE;
    }
    
    
	// ========================
	// Factory matters :
	// ========================
    

	// Important: private constructor
    // called at first use of this factory
	private ExempleFactory() 
	{
		// List of all types tha can be built
		knownTypes.put(1,"Pizza")
		knownTypes.put(2,"Trompet")
		knownTypes.put(3,"Mamoth")
	}
    
	// Takes the ClassID to instanciate this class
	public Object MakeFromString(int ClassID)
	{
		return MakeFromString(knownTypes[ClassID]);
	}

	// Takes a string and parse it to instanciate the coressponding class
	public Object MakeFromString(String ObjDescription)
	{
		if (ObjDescription == "Pizza")
			return MakePizza();
		else if (ObjDescription == "Trompet")
			return MakeTrompet();
		else if (ObjDescription == "Mamoth")
			return MakeMamoth();
		
	}

	// Verify the avariability of provided class (either ID or Class Name)
	public boolean canMake(int ClassID)
	{
		return knownTypes.containsKey(canMake);
	}
	public boolean canMake(String ClassName)
	{
		return knownTypes.containsValue(ClassName);
	}
	
	

	// ========================
	// Building matters :
	// ========================
	
	// Constructors of known types
    private Pizza MakePizza()
    {
    	// Delicious pizza delivered directly to INTech
    }
    

    private Trompet MakeTrompet()
    {
    	// Remplace ronald troll when th amplifier is HS
    }
    

    private Mamoth MakeMamoth()
    {
    	// Particularly well known target for ping pong balls 
    }
    
    
}
