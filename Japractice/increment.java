class Untitled {
	public static void main(String[] args) 
	{
		int n = 2, m = 4;
		System.out.println(m++);
		System.out.println(m);
		n++;
		System.out.printf("n is %d\n", n);
		n--;
		System.out.printf("n is %d\n", n);
		int len = "hello world".length();
		System.out.println("hello world".substring(6, 11));
		System.out.println("   hello world    ".trim()+"______");
		System.out.println("hello world".replace("o", "0"));
		System.out.println("hello world".toUpperCase());
		String test = "abcdefg";
		System.out.println(test.charAt(1));
		System.out.print("1234567\rabcdefg");
	}
}