class Extension{
	public static void main(String[] args) {
		int[] x = {3,2,4,7,4,8,2,7,1,9,5};
		int[][] result = partition(x, 3);
		for(int i = 0; i < result.length;i++){
			for (int j = 0; j < result[i].length;j++){
				System.out.print(result[i][j]+ ((j==result[i].length -1)? "\n":" "));
			}
		}
	}
	
	static int[][] partition(int[] array, int k){
		int wid = (int)Math.pow(2, k);
		double rem = array.length%wid;
		int hig = ((rem == 0)? (int)array.length/wid : (int)array.length/wid+1);
//		System.out.print(wid+" "+rem+" "+array.length/wid+" "+hig+ " \n--------\n");
		int[][] r_nums = new int[hig][wid];
		int len = array.length, i =0;
		while (i < len) {
			r_nums[(int)i/wid][i%wid] = array[i];
			i ++;
		}
		return r_nums;
	}
}