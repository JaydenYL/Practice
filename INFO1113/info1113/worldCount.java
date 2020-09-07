import java.io.*;
import java.util.*;

class wordCount {
	public static void main(String[] args) {
		File f = new File("example.txt");
		String s;
		try (Scanner scan = new Scanner(f)) {
			s = scan.nextLine();
			System.out.print(s);
			System.out.print("----");
			
		} catch (Exception e) {
			
		}
	}
}