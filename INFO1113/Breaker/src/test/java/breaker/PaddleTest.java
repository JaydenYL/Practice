package breaker;

import org.junit.Test;
import static org.junit.Assert.*;

public class PaddleTest {
	Paddle paddle_1 = new Paddle(0);
	
	@Test public void  testPaddleCoordn() {
		assert (paddle_1.x == 0 && paddle_1.y == 390) : "paddle should has correct coordinate";
	}
	
	@Test public void  testPaddleMove() {
		paddle_1.move(false);
		assert (paddle_1.x == 3) : "paddle should has correct coordinate" ;
	}
	
	@Test public void  testPaddleCollision() {
		paddle_1.move(true);
		Ball bal = new Ball(0, 390, 0, 5);
		paddle_1.interpolationX(bal);
		assert (bal.speed_y != 5) : " test interpolationX" ;
	}
	
}