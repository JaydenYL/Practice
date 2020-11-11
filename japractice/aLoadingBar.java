import java.util.*;
import java.util.concurrent.TimeUnit;
import java.util.Random;

class aLoadingBar {
	
	public static void main(String[] args) {
		char[] ar = new char[]{'|', '/', '-', '\\'};
		Random rand = new Random();
		int j = 0;
		for(double i = 0 ; i < 20; ){
			if(rand.nextInt(100) < 35){
				System.out.printf("\b\033[32m-%c", ar[j++]);
				j = j%4;
				System.out.flush();
				i ++;
			}
			try {
//				TimeUnit.MILLISECONDS.sleep(40);
				Thread.sleep(50);
			} catch (Exception e) {
				
			}
			
			System.out.printf("\b%c", ar[j++]);
			System.out.flush();
			j = j%4;
		}
		System.out.printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	}
}