package breaker;

public class PowerUp {
	
	public String kind;
	public String image;
	public double x, y;
	public int speed = 3, height = 16, width = 16;
	
	public PowerUp(String s, double x, double y){
		this.x = x;
		this.y = y;
		this.kind = s;
		if (s.equalsIgnoreCase("multiball")){
			image = "ball_powerup.png";
		} else if (s.equalsIgnoreCase("paddleup")){
			image = "paddle_powerup.png";
		}
	}


	public void tick(){
		this.move();
	}


	public void move(){
		this.y += speed;
	}
	
}