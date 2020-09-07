class Untitled {
	public static void main(String[] args) {
		int[] dups = {1,1,5,6,5,3,8,1,9,2,8};
		System.out.print(countDup(dups));
	}
	
	public static boolean contains(int[] a, int ele){
		for(int i = 0; i <a.length; i++){
			if(ele == a[i]){return true;}
		}
		return false;
	}


	public static int count(int[] a, int ele){
		int counter = 0;
		for(int i = 0; i<a.length; i++){
			if (a[i] == ele){
				counter ++;
			}
		}
		return counter;
	}
	
	public static int countDup(int[] a){
		int counter = 0;
		for (int i=0; i< a.length;i++){
			if ((! contains(slice(a, 0, i), a[i])) && (contains(slice(a, i+1, a.length), a[i]))){
				counter ++;
			}
		}
		return counter;
	}
	
	
	public static int[] slice(int[] ls, int a, int b){
		int[] re_ls = new int[b-a];
		for(int i = a, j = 0; i < b; i++){
			re_ls[j++] = ls[i];
		}
		return re_ls;
	}
}