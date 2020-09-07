public class Nums {
	public int[] array = new int[] {};
	
	public void put(int ele){
		int[] ls = new int[this.array.length+1];
		for (int i = 0; i < ls.length; i++){
			ls[i] = (i < ls.length-1)? this.array[i] : ele;
		}
		this.array = ls;
	}
}

