class DrawTree{
	public static void main(String[] args) {
		System.out.println("Tree_1 demo:");
		tree_1();
		System.out.println("\nTreewithloop demo:");
		treewithloop();
	}
	
	static void tree_1(){
		System.out.println("   *");
		System.out.println("  ***");
		System.out.println(" *****");
		System.out.println("*******");
		System.out.println("  ***");
	}
	
	static void treewithloop(){
		int i = 3;
		for(;i >=0;i--){
			for(int j = 0; j < i; j ++){
				System.out.print(" ");
			}
			for(int j = 0; j < 7-2*i; j++){
				System.out.print("*");
			}
			System.out.print("\n");
		}
		System.out.print("  ***");
	}
}