import java.io.*;
import java.util.*;

public class Filedeal{
	static String words;
	static Scanner fileread;

	public static void main(String[] args) {
		File f = new File("helloworld.txt");
		try {
			fileread = new Scanner(f);
			words = fileread.nextLine();
			
		} catch (Exception e) {
			System.err.println("File not found!");
			e.printStackTrace();
		}
		
		System.out.println(words);
	}
}