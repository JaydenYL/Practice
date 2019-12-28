class People{
	public static void main(String[] args){
		man yu = new man();
		System.out.println(yu.getnum());
		man x = new man();
		System.out.println(x.getnum());
		man y = new man();
		System.out.print(y.getnum());
	}
}

class man{
	private static int num = 0;
	man(){
		num += 1;
	}
	
	int getnum(){
		return num;
	}
}