
public class lanceur {

	public static void main(String[] args) {
		Container container = Container.initialiser();
		Log log = (Log)container.get_service("Log");
		
		log.debug("Test");
		log.warning("Test");
		log.critical("Test");
		
	}

}
