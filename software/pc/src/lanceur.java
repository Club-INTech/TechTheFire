
<<<<<<< HEAD
public class lanceur 
{

	public static void main(String[] args) 
	{
		Container container = Container.initialiser();
		Log log = (Log)container.get_service("Log");
		
		log.debug("Test");
		log.warning("Test");
		log.critical("Test");
		
=======
public class lanceur
{
	private static Test test = new Test();
	public static void main(String[] args)
	{
		test.test();
>>>>>>> 213f1b59b2080b1f91e33781ab2a4c9d9d820955
	}

}
