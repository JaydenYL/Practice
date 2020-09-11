package breaker;

import java.util.ArrayList;

class Ball {

	public double speed_x, speed_y, x, y;
	public int width = 5, height = 5;
	
	public Ball(double x, double y, double vx, double vy) {
		this.x = x;
		this.y = y;
		this.setSpeed(vx, vy);
	}


	public void tick(ArrayList<Brick> bricks, ArrayList<PowerUp> magic){
		this.move();
		for (Brick b : bricks){
			if (!(b==null) && !b.broken){
				this.rebounded(b, magic);
				if (b.broken) Sound.playSound("collision.wav");
				if (b.broken && !b.powerup.equals("null")){
					magic.add(new PowerUp(b.powerup, this.x, this.y));
				}
			}
		}
	}
	
	
	public void rebounded(Brick bri, ArrayList<PowerUp> magic){
		if  ((this.x + this.width + this.speed_x > bri.x) &&
				(this.x + this.speed_x < bri.x + bri.width)  && 
				(this.y + this.height > bri.y ) && (this.y < bri.y + bri.height)){
				this.speed_x *= -1;
				bri.collision();
			}
		
		if ((this.x + this.width > bri.x) &&
			(this.x < bri.x + bri.width) &&
			(this.y + this.height + this.speed_y > bri.y) && 
			(this.y + this.speed_y < bri.y + bri.height)){
				this.speed_y *= -1;
				bri.collision();
			}
	}


	public void move(){
		x += speed_x;
		y += speed_y;

		if (y <=0 ){
			y = 0;
			Sound.playSound("wall.wav");
			speed_y *= -1;
		}
		
		if (x <= 0 ){
			x = 0;
			Sound.playSound("wall.wav");
			speed_x *= -1;
		}
		
		if( x >= 515){
			x = 515;
			Sound.playSound("wall.wav");
			speed_x *= -1;
		}
	}
	
	public void setSpeed(double vx, double vy){
		this.speed_y = vy;
		this.speed_x = vx;
	}

	
}