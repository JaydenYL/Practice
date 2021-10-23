import org.junit.Test;
import static org.junit.Assert.*;


public class PotatoTest {
    Kitchen kit = new Kitchen();
    @Test
    public void testRaw() {
        assertEquals("This is a raw potato.",  new Potato().toString());
    }

    @Test
    public void testOnce() {
        assertEquals("This is a baked potato.",  kit.cookPotato());
    }

    @Test
    public void testTwice() {
        assertEquals("This is a baked potato. It went in the oven twice for some reason. Perhaps the chef is new.",  kit.doubleCookPotato());
    }

    @Test
    public void testBurnt() {
        assertEquals("This is a burnt potato.",  kit.burnPotato());
    }

}
