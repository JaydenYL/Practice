import java.util.*;

class Questions2to6 {
	public static void main(String[] args) {
//		ArrayList<String> list_1 = new ArrayList<String>();
//		list_1.add("hello");
//		ArrayList list_2 = new ArrayList();
//		list_2.add("Hello world");
//		ArrayList list_3 = new ArrayList<String>();
//		list_3.add("hello, world");
//		CharacterOccur a = new CharacterOccur();
//		a.count();
//		Colour.storeColor();
		DynamicArray darray = new DynamicArray(16);
		darray.add(10);
		darray.add(11);
		darray.showElement();
	}
}



class Log{

}



class CharacterOccur{
//	public CharacterOccur(){
//		
//	}
	
	public static void count(){
		String s;
		Scanner keyb = new Scanner(System.in);
		System.out.println("Please input a string: ");
		s = keyb.next();
		Map<String,Integer> result = new HashMap<String, Integer>();
		for(int i = 0, len = s.length(); i < len; i++){
			try {
				result.put(s.substring(i, i+1), result.get(s.substring(i, i+1))+1);
			} catch (Exception e) {
				result.put(s.substring(i, i+1), 1);
			}
			
		}
		System.out.println(result);
	}
}

class Colour{
	static HashMap<String, int[]> clrs = new HashMap<String, int[]>();
	public static void storeColor(){
		
//		Scanner keyb = new Scanner(System.in);
		int[] x = {255, 0, 0};
		clrs.put("Red", new int[] {255, 0, 0});
		clrs.put("Purple",new int[] {120, 0, 200});
		clrs.put("Grass Green",new int[] {0, 150, 50});
		clrs.put("Brown",new int[] {150, 100, 50});
		System.out.println(clrs);
	}
	
	public static void add(String s1, String s2, String made_s3){
		int[] arr_1 = clrs.get(s1), arr_2 = clrs.get(s2), arr_3 = new int[3];
		for(int i = 0; i<3; i++){
			arr_3[i] = (arr_1[i]+arr_2[i]>255)?255:arr_1[i]+arr_2[i];
		}
		clrs.put(made_s3, arr_3);
	}
}

