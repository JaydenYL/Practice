package breaker;

public class Brick{
	
	public int x, y, hp;
	public String img , powerup = "null";
	public int width = 20, height = 10;
	public boolean broken = false;
	
	public Brick(int x, int y, String color , int hp, String pp ){
		this.x = x;
		this.y = y;
		this.hp = hp;
		this.powerup = pp;
		if( color.equalsIgnoreCase("BRICK_BLUE")) {
			img = "brick_blue.png";
		} else if (color.equalsIgnoreCase("BRICK_PINK")){
			img = "brick_pink.png";
		} else if (color.equalsIgnoreCase("BRICK_GREEN")) {
			img = "brick_green.png";
		} else if (color.equalsIgnoreCase("BRICK_RED")) {
			img = "brick_red.png";
		}
	}
	
	public void collision(){
		this.hp--;
		if (hp <= 0) this.broken = true;
	}
}
