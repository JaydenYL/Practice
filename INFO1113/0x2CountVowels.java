class CountVowels {
	public static void main(String[] args) {
		String s = "astrOnaUtaeiobcvzuse";
		System.out.printf("Number of vowels: %d", CountVowels.count(s));
	}
	
	static int count(String s){
		int len = s.length(), i = 0, num = 0;
		String vow = "aeiouAEIOU";
		while (i < len){
			for(int j = 0; j < 10; j++){
				if((s.charAt(i)) == vow.charAt(j)){
					num += 1;
					break;
				}
			}
			i += 1;
		}
		return num;
	}
}