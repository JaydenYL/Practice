class program1 {
	public static void main(String[] args) {
		MyLinkedList<String> mylink = new MyLinkedList<String>();
		mylink.add("hello");
		mylink.add("java");
		mylink.add("python");
		mylink.insert("insertString", 1);
//		mylink.add("world");
//		mylink.remove(3);
//		System.out.println(mylink.remove(0));
		for (String s : mylink){
			System.out.println(s);
		}
	}
}