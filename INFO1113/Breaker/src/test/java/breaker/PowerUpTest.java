package breaker;

import org.junit.Test;
import static org.junit.Assert.*;

public class PowerUpTest {

	
	@Test
	public void  testMove(){
		PowerUp pp = new  PowerUp("null", 200, 200);
		pp.move();
		assert pp.y == 203 : "Powerup.should fall down";
	}
	
	@Test
	public void testTick(){
		PowerUp pp = new  PowerUp("null", 200, 200);
		pp.tick();
		assert pp.y == 203 : "tick() should call move()";
	}
	
	@Test public void testWidth(){
		PowerUp pp = new  PowerUp("null", 200, 200);
		pp.tick();
		assert (pp.width == 16 && pp.height == 16) : "test the height and the width of the powerup";
	}
	
	@Test public void testImage(){
		PowerUp pp = new  PowerUp("multiball", 200, 200);
		assert (pp.image == "ball_powerup.png") :" the image of power up should be correct";
	}
	
	
	@Test public void testPowerupImage(){
		PowerUp pp = new  PowerUp("paddleup", 200, 200);
		assert (pp.image == "paddle_powerup.png") :" the image of power up should be correct";
	}
	
}