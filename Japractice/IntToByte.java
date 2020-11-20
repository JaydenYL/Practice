public class IntToByte{
	public static void main(String[] args){
		int a = 0xff;
		byte[] a_bytes = convertToByte(a);
		System.out.println(a_bytes[3]);
		int b = convertToInt(a_bytes);
		System.out.println(b);
	}


	public static byte[] convertToByte(int n){ //using big endianness
		byte[] bytes = new byte[4]; 
		bytes[0] = (byte)(n >> 24);
		bytes[1] = (byte)(n >> 16);
		bytes[2] = (byte)(n >> 8);
		bytes[3] = (byte)n;
		return bytes;
	}


	public static int convertToInt(byte[] b){
		return (b[3] & 0xFF) |
		((b[2] & 0xFF) << 8) |
		((b[1] & 0xFF) << 16)|
		((b[0] & 0xFF) << 24);
	}
	
}