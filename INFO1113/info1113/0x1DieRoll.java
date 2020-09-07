class DieRoll {
	public static void main(String[] args) {
		int n;
		for(int i = 0; i < 20; i++){
			n = (int)(Math.random()*6) + 1;
			System.out.print(n + " ");
		}
	}
}