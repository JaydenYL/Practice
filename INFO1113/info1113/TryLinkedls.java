class TryLinkedls{
	public static void main(String[] args){
		NewLinkedList<Integer> linkedls = new NewLinkedList<Integer>();
		linkedls.add(3);
		System.out.println(linkedls.size());
		Integer i = 123;
		Integer j = 123;
		System.out.println(i == j);
		i = new Integer(100);
		j = new Integer(100);
		System.out.println(i == j);
	}
}