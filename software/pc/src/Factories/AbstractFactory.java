/* ============================================================================
 * 							Abstract Factory interface
 * ============================================================================
 * 
 * This interface should be implemented by all factories troughout the robot.
 * Author : Martial
 */


public interface AbstractFactory 
{
	public:
		// Takes a string and parse it to instanciate the coressponding class
		Object MakeFromString(String ObjDescription);
	
		// Takes the ClassID to instanciate this class
		Object MakeFromString(int ClassID);
	
	private:
		
		// Map of known supported types
		
}
