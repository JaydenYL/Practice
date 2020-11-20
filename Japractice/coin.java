import java.util.*;

class Untitled {
	public static void main(String[] args) {
		System.out.print("$: ");
		Scanner in = new Scanner(System.in);
		float money = in.nextFloat();
		System.out.println();
		double[] change = new double[]{100, 50, 20, 10, 5, 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
		int i = 0;
		while (money > 0)
		{
			if ((int)(money/change[i]) != 0) System.out.println( (i<7 ? (int)change[i]:change[i]) + " X " + (int)(money/change[i]) );
			money %= change[i];
			i += 1;
//			System.out.println(money);
		}
	}
}