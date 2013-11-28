
public class lanceur {

	public static void main(String[] args) {
		
		SerialManager serialManager = new SerialManager();
		
		serialManager.checkSerial();
		serialManager.createSerial();
		String i = serialManager.serieAsservissement.communiquer("?", 1);
		
		System.out.println(i);
		serialManager.serieAsservissement.close();
	}

}
