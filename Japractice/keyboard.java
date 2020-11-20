import java.util.*;

public class keyboard {
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		System.out.print("Enter an integer: ");
		int n = keyboard.nextInt();
		System.out.print("Enter a string: ");
		keyboard.nextLine();
		String s1 = keyboard.nextLine();
		System.out.print("Enter the second string: ");
		String s2 = keyboard.nextLine();
		System.out.println("\n\n----n----\n"+n);
		System.out.println("----s1---\n"+s1);
		System.out.println("----s2---\n"+s2);
		System.out.println("------end-------");
	}
}