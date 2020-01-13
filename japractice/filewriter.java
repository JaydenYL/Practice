import java.io.*;


class filewriter {
	public static void main(String[] args) {
		File f = new File("hello_01.txt");
		if (f.exists()){
			System.out.print("File already exits");
			System.exit(0);
		}
		try {
			PrintWriter writer = new PrintWriter(f);
			for (int i=0; i < 10; i++) {
				writer.println(i);
			}
			writer.println("12345");
			writer.println("hello world");
			writer.close();
			System.out.println("Finish writing");
		} catch (FileNotFoundException e) {
			System.out.println("File not found");
			e.printStackTrace();
		}
	}
}