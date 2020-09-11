package breaker;

import org.junit.Test;
import static org.junit.Assert.*;

public class BallTest {
	Ball bal = new Ball(0, 390, 0 ,-5);
	
	@Test public void  testBallmove(){
		bal.move();
		assert (bal.y == 385) : "ball should move" ;
	}
	
	@Test public void  testSetSpeed(){
		bal.setSpeed(2, 3);
		assert (bal.speed_x == 2) : "test the setSpeed function";
		assert (bal.speed_y == 3) : "test the setSpeed function";
	}
	
}