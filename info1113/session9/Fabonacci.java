import java.util.HashMap;;

class Fabonacci {
	
	public static HashMap<Integer,Integer> fabnums = new HashMap<Integer,Integer>();{
		fabnums.putIfAbsent(Integer.valueOf(1), Integer.valueOf(1));
		fabnums.putIfAbsent(2,1);
		System.out.println(fabnums);
	}
	
	public static void main(String[] args) {
		System.out.println(fabnums);
		System.out.println(fabnums.containsKey(Integer.valueOf(2)));
		int i = 1;
		while(i<5){
		System.out.println(Fab(i));
		i++;
		}
		System.out.println(fabnums);
	}
	

	public static Integer Fab(Integer n){

		if (n == 1 || n== 2) return 1;
		if (fabnums.containsKey(n)) return fabnums.get(n);
		else{
			int fab = Fab(n-1) + Fab(n-2);
			fabnums.putIfAbsent(n, fab);
			return fab;
		}
	}
	
}