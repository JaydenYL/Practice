import java.util.*;

class SelectionSort {
	public static void main(String[] args) {
		List<Integer> ints = new ArrayList<Integer>();
		ints.add(4);
		ints.add(8);
		ints.add(1);
		ints.add(3);
		sort(ints);
		for (Integer i : ints){
			System.out.println(i);
		}
}
	
	public static void sort(List<Integer> ls){
		if (ls.size() == 0) return;
		Integer min = Integer.MAX_VALUE;
		int min_idx = 0;
		for(int i = 0 ; i < ls.size();i++){
			Integer cur = ls.get(i);
			if(min>cur){
				min = cur;
				min_idx = i;
			}
		}
		
		Integer tmp = ls.get(min_idx);
		ls.set(min_idx, ls.get(0));
		ls.set(0, tmp);
		sort(ls.subList(1, ls.size()));
	}
}