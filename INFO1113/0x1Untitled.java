class Questions4to9 {
	public static void main(String[] args) {
		int[] array = {1, 1, 5, 5, 5, 3, 8, 1};
		System.out.println(Questions4to9.contains(array,2));
		System.out.println(count(array, 2));
		System.out.println(countDuplicate(array));
		int[] x = {1,2,5,6,0,8,7};
		int[] y = {3,1,2,6,10};
		int[] result = intersection(x, y);
//		System.out.println(result);
//		for(int i = 0; i < result.length; i++){
//			System.out.print(result[i] + " ");
//		}
		float[] times = {(float)4.12, (float)4.11, (float)3.23, 2, (float)1.23, (float)-0.87, 0};
		float[] f_result = rank(times);
		for(int i = 0; i < f_result.length; i++){
			System.out.print(f_result[i] + ((i==f_result.length -1)? "\n":" "));
		}

		for(int i = 0; i < f_result.length; i++){
			System.out.printf("Athlete %d: +%.4f\n",i , f_result[i]-f_result[0]);
		}
	}
	
	static boolean contains(int[] nums, int ele){
		int len = nums.length;
		for (int i=0; i < len; i++) {
			if (nums[i] == ele){
				return true;
			}
		}
		return false;
	}
	
	
	static int count(int[] nums, int ele){
		int len = nums.length, counter = 0;
		for (int i=0; i < len; i++) {
			if (nums[i] == ele){
				counter += 1;
			}
		}
		return counter;
	}
	
	
	static int countDuplicate(int[] nums){
		int len = nums.length, max = 0, cur;
		for(int i=0; i<len; i++){
			cur = count(nums, nums[i]);
			max = (cur > max)? cur : max;
		}
		return max;
	}
	
	static int[] intersection(int[] x, int[] y){
		int len = y.length, j = 0;
		int[] nums = new int[len];
		for(int i = 0; i < len; i++){
			if (contains(x, y[i])){
				System.out.println(y[i]);
				nums[j] = y[i];
				j++;
			}
		}
		int[] r_nums = new int[j];
		for(int i =0; i<j;i++){
			r_nums[i] = nums[i];
		}
		return r_nums;
	}
	
	static float[] rank(float[] times){
		int j = 0, i = 0, len = times.length - 1;
		float mid;
		while (i < len){
			j = 0;
			while (j<len-i){
				if (times[j] > times[j+1]){
					mid = times[j];
					times[j] = times[j+1];
					times[j+1] = mid;
				}
				j ++;
			}
			i++;
		}
		return times;
	}
}