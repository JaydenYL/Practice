import java.util.*;

class Untitled {
	public static void main(String[] args) {
		
	}
	
	public void countDup(int[] a){
		HashMap<Integer,Integer> counts = new HashMap<Integer, Integer>();
		for (int i = 0; i < a.length; i++){
			if (counts.containsKey(a[i])){
				counts.put(a[i], counts.get(a[i])+1);
			}else{
				counts.put(a[i], 1);
			}
		}
	}
}

