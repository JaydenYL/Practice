import java.util.Arrays;
import java.util.*;

class Untitled {
	public static void main(String[] args) {
		Scanner keyb = new Scanner(System.in);
		System.out.print("Enter a integer; ");
		int n = keyb.nextInt();
		for(int i = 1; i <= n; i++){
//			System.out.println(Arrays.toString(trangle(i)));
			int[] nums = trangle(i);
			for(int j = 0 ; j < nums.length ; j++){
				System.out.print(nums[j] + ((j < nums.length-1)? " " : "\n"));
			}
		}
	}


	public static int[] trangle(int n){
		if(n == 1) return new int[] {1};
		int[] ls = new int[n];
		ls[0] = 1;
		ls[n-1] = 1;
		for (int i = 1; i < n-1; i++){
			ls[i] = trangle(n-1)[i-1]+trangle(n-1)[i];
		}
		return ls;
	}
}