class Card {
	private String sender, receiver, contents;
	private boolean received;
	public Card(String s, String r, String c){
		this.sender = s;
		this.receiver = r;
		this.contents = c;
		this.received = false;
	}
		
	public boolean inTransit(){
		return !this.received;
	}
	
	public static boolean HasArrived(Card p){
		return !p.inTransit();
	}
	
	public void AlreadyArrived(){
		this.received = true;
	}
}


public class Postcard{
	public static void main(String[] args){
		Card abc = new Card("I", "You", "happy birthday!");
		Card cde = new Card("YOU", "ME", "hello");
		System.out.println(abc.inTransit());
		abc.AlreadyArrived();
		System.out.println(abc.inTransit());
	}

}