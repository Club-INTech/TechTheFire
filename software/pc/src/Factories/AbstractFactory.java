/* ============================================================================
 * 							Abstract Factory interface
 * ============================================================================
 * 
 * This interface should be implemented by all factories troughout the robot.
 * Author : Martial
 */


public interface AbstractFactory 
{
	// Takes a string and parse it to instanciate the coressponding class
	public Object MakeFromString(String ClassName);
	
	// Takes the ClassID to instanciate this class
	public Object MakeFromID(int ClassID);
		
	// Verify the avariability of provided class
	public boolean canMake(String ClassName);
	public boolean canMake(int ClassID);
	
	
		
	// Map of supported types
	private	Hashtable knownTypes;
}
