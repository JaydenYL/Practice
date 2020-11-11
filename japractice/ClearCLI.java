import java.util.*;

class ClearCLI {
	public static void main(String[] args) {
		String s = "hello";
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		System.out.println("int is " + a);
		scan.nextLine();
		String sss = scan.nextLine();
		System.out.println("line is " + sss);
		System.out.print("\033[H\033[2J");
		System.out.flush();
	}
}