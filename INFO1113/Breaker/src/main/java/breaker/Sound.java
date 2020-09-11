package breaker;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;

import java.io.File;

public class Sound {
	
	public static Clip fileload(String filename) {
		try {
			AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(new File("src/main/resources/"+filename));
			Clip clip = AudioSystem.getClip();
			clip.open(audioInputStream);
			return clip;
		} catch(Exception ex) {
			System.out.println("Error with playing sound.");
			ex.printStackTrace();
		}
		return null;
	}
	
	public static void playSound( String name){
		fileload(name).start();
	}
	
	public static void playLoop(String name){
		fileload(name).loop(Clip.LOOP_CONTINUOUSLY);
	}
	
}