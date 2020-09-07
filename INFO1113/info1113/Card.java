import java.security.*;

public class Card {
	protected  String name;
	public Card(String name){
		this.name = name;
	}
}


class CreditCard extends Card{
	String bank_name, expiry_date ,card_num;
	static boolean secuity_chip = true;
	
	public CreditCard(String name,String bank, String expiry, String num){
		super(name);
		this.bank_name = name;
		this.expiry_date = expiry;
		this.card_num = num;
	}
}


class StudentCard extends Card{
	int yearOfIssue;
	long id;
	static boolean magChip = true;

	public StudentCard(String name, int year, long id){
		super(name);
		this.yearOfIssue = year;
		this.id = id;
	}
}


class License extends Card{
	String address, stateOfIssue, cardNo, licenseNo;
	
	public License(String name,String address, String stateOfIssue,String cardNo, String licenseNo){
		super(name);
		this.address = address;
		this.stateOfIssue = stateOfIssue;
		this.cardNo = cardNo;
		this.licenseNo = licenseNo;
	}
}