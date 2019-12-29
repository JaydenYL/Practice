class Questions1to4{
	public static void main(String[] args) {
		Card my_card = new Card("LIU YU");
		CreditCard my_visa = new CreditCard("LIU YU", "CBA", "01/01/2022", "12345678909876543");
		StudentCard my_uni_card = new StudentCard("LIU YU", 2019, 490095315);
		License my_diver = new License("LIU YU", "camperdown", "NSW", "EE12345", "NS12312079");
		System.out.println(my_uni_card.id);
		System.out.println(my_visa.card_num);
	}
}