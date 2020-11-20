import java.util.*;



public class circle {
	private static final double PI = 3.14159;
	
	public static void main(String[] args) {
		System.out.printf("Please enter the radius (in inches): ");
		Scanner keyboard = new Scanner(System.in);
		double radius = keyboard.nextDouble();
		System.out.printf("The area of this circle is: %10.5f square inches", PI*radius*radius);
	}
}