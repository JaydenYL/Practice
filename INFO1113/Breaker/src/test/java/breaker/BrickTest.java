package breaker;

import org.junit.Test;
import static org.junit.Assert.*;

public class BrickTest {
	Brick bri_1 = new Brick(0, 0, "BRICK_BLUE", 1, "null");
	Brick bri_2 = new Brick(0, 0, "Brick_pink", 2, "paddleup");
	
	@Test public void  testBrickColor() {
		assert (bri_1.img == "brick_blue.png"): "color should be blue" ;
		assert (bri_2.img == "brick_pink.png"): "color should be pink" ;
	}
	
	
	@Test public void  testBrickCollision(){
		bri_1.collision();
		bri_2.collision();
		assert (bri_1.broken == true) : "bri_1 should be broken after the collision";
		assert (bri_2.broken == false) : "bri_2 should not be broken after the collision since its hp is 2"; 
	}
	
	@Test public void  testBrickPowerUp(){
		assert (bri_2.powerup == "paddleup" ) : "bri_2 has powerup of paddle up";
	}
	
	
	
}