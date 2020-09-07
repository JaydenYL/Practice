import java.util.HashMap;



class Fabonacci {
	
	public static HashMap<Integer,Integer> fabnums = new HashMap<Integer,Integer>();
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt(), d = scan.nextInt();
		int digit = (int)Math.pow(10, d+1);
		int result = Fab(n, digit);
		System.out.println(result);
		System.out.println(getDigit(result, d));
		System.out.println(fabnums);
		System.out.println(getDigit(1234, 2));
		
	}
	

	public static Integer Fab(Integer n, int digit){
		if (n == 1 || n== 2) return 1;
		if (fabnums.containsKey(n)) return fabnums.get(n);
		int fab = (Fab((n-1), digit) + Fab((n-2), digit))%digit;
		fabnums.putIfAbsent(n, fab);
		return fab;
		
	}
	
	public static int getDigit(int num, int n){
		return (n == 1) ? num %10 : getDigit(num/10, n-1);
	}
	
}