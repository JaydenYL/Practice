import java.io.*;

class Untitled {
	public static void main(String[] args){
		try {
			System.out.println("Enter a char");
			byte[] b = new byte[1];
			while (true){
				char val = (char)System.in.read(b);
				if (val == '\n'){
					System.out.println("hello");
				} else {
					System.out.println("world");
				}
			}
		} catch (IOException e){
			e.printStackTrace();
		}
	}
}