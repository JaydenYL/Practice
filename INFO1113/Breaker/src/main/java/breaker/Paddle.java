package breaker;

import java.util.ArrayList;
import java.util.Iterator;

class Paddle {
	
	public double x, y = 390, speed = 3 ;
	public int  width = 40, height = 10,  timer = 0;
	boolean lf_move = false, rt_move = false, paddleup = false;

	
	public Paddle(double x){
		this.x = x;
	}
	
	
	public void tick(double v , ArrayList<Ball> balls, ArrayList<PowerUp> magic) {
		if (this.lf_move) this.move( true);
		else if (this.rt_move) this.move(false);
		rebounded(balls);
		rebounded(magic, balls);
		if (paddleup) timer -- ;
		if (timer == 0 && paddleup) {
			paddleup = false;
			this.width -= 10;
		}
	}


	public void move( boolean left){
		int index = left ? -1 : 1;
		this.x += index*this.speed;
		x = (x <= 0)? 0 : x;
		x = (x >= 520 - this.width) ?  520 - this.width: x;
	}


	public void interpolationX(Ball bal){
		double deltaX = bal.x - (this.x + this.width/2 - 2) ;
		double vx , vy;
		vx = deltaX/(this.width/5);
		vy = Math.abs(vx)-5;
		if (vy == 0)  vy-- ;
		bal.setSpeed(vx, vy);
	}


	public void rebounded(ArrayList<Ball> bals){
		Iterator<Ball> itr = bals.iterator();
		while (itr.hasNext()){
			Ball bal = itr.next();
			if ((bal.x + bal.width > this.x) &&
				(bal.x < this.x + this.width) &&
				(bal.y + bal.height + bal.speed_y > this.y) && 
				(bal.y + bal.speed_y < this.y + this.height)){
					Sound.playSound("bounce.wav");
					interpolationX(bal);
			}
			if (bal.y > 400) itr.remove();
		}
	}


	public void rebounded(ArrayList<PowerUp> magic, ArrayList<Ball> bals){
		Iterator<PowerUp> itr = magic.iterator();
		while (itr.hasNext()) {
			PowerUp m = itr.next();
			if ((m.x + m.width > this.x) &&
				(m.x < this.x + this.width) &&
				(m.y + m.height + m.speed > this.y) && 
				(m.y + m.speed < this.y + this.height)){
				if (m.kind.equalsIgnoreCase("multiball")){
					for(int i = 0, size = bals.size(); i< size; i ++){
						Ball tmp = bals.get(i);
						bals.add(new Ball(tmp.x, tmp.y, -0.5*tmp.speed_x-0.57*tmp.speed_y,-0.5*tmp.speed_y + 0.57*tmp.speed_x));
						bals.add(new Ball(tmp.x, tmp.y, -0.5*tmp.speed_x+0.57*tmp.speed_y,-0.5*tmp.speed_y - 0.57*tmp.speed_x));
					}
				} else if (m.kind.equalsIgnoreCase("paddleup")) {
					if (! this.paddleup){
						this.width += 10;
						this.timer += 3600;
						this.paddleup = true;
					}
				}
				itr.remove();
			}
		}
	}
}