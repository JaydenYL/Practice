import java.util.*;

class sort3 {
	public static void main(String[] args) {
		int x , y, z, n;
		Scanner keyb = new Scanner(System.in);
		System.out.print("Enter 3 integer: ");
		x = keyb.nextInt();
		y = keyb.nextInt();
		z = keyb.nextInt();
		if (x < y){n = y; y = x; x = n;}
		if (y < z){n = z; z = y; y = n;}
		if (x < y){n = y; y = x; x = n;}
		System.out.printf("%d %d %d", x, y, z);
	}
}