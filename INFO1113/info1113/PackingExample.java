public class PackingExample {
	public static void unpack(Object packedData) { 
		Integer[] myInts = (Integer[]) packedData; 
		System.out.println(myInts[0]); 
		System.out.println(myInts[1]);
		System.out.println(myInts[0] + myInts[1]); 
	}
	public static void main(String[] args) {
		Integer[] array_int = new Integer[] {1, 2};
		System.out.println(array_int[1]+array_int[0]);
		unpack(array_int);
	}
}