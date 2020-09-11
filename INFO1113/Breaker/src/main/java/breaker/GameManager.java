package breaker;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.util.Iterator;
import java.util.ArrayList;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;


public class GameManager {

	public int condition , timer;

	public String firstlevel, currentlevel, nextlevel;
	
	public boolean lose;

	public GameManager(String first_file){
		condition = 1;
		firstlevel = first_file;
		currentlevel = firstlevel;
	}
		
	
	public void tick(ArrayList<Ball> balls, ArrayList<Brick> bris, ArrayList<PowerUp> magic, ArrayList<Paddle> pds){
		for (Ball b : balls){
			b.tick( bris,  magic);
		} for (PowerUp m : magic) {
			m.tick();
		}
		
		for(Paddle p : pds){
			p.tick(p.speed, balls, magic);
		}
		
		if (gameOver(balls)) condition = 4;
		if (gameWin(bris)){ 
			condition = (nextlevel != null) ? 3 : 5;
		}
	}
	
	
	public boolean gameOver(ArrayList<Ball> balls){
		for (Ball b : balls){
			if (b.y < 400){
				return false;
			}
		}
		this.timer = 120;
		Sound.playSound("lose.wav");
		this.currentlevel = firstlevel;
		this.lose = true;
		return true;
	}
	
	
	public  boolean gameWin(ArrayList<Brick> bricks){
		for (Brick b : bricks){
			if (! b.broken ) {
				return false;
			}
		}
		if ( nextlevel != null) this.currentlevel = nextlevel;
		this.timer = 120;
		return true;
	}
	
	
	public boolean showMessage(boolean keypressed){
		this.timer -- ;
		if (keypressed ) timer = 0;
		if (timer <= 0 ) {
			timer = 0;
			if (condition == 5){
				currentlevel = firstlevel;
			}
			condition = 1;
	
			return true;
		}
		return false;
	}
	


	public void initailize(ArrayList<Ball> balls, ArrayList<Brick> bris, ArrayList<Paddle> pds, ArrayList<PowerUp> magic) {
		balls.removeAll(balls);
		balls.add(new Ball(260, 385, 0 , -5));
		bris.removeAll(bris);
		String file = (!lose) ? currentlevel : firstlevel;
		bris.addAll(fileLoad(file+".json"));
//		System.out.println(currentlevel);
		pds.removeAll(pds);
		pds.add(new Paddle(240));
		magic.removeAll(magic);
		this.condition = 2;
		this.lose = false;
		Sound.playSound("begin.wav");
	} 
	

	
	public ArrayList<Brick> fileLoad(String filename){
			
		ArrayList<Brick> brks = new ArrayList<Brick>();
		JSONParser parser = new JSONParser();
		
		try (Reader reader = new FileReader(filename)) {
			
			JSONObject jsonObject = (JSONObject) parser.parse(reader);
			try{
				nextlevel = (String)jsonObject.get("next_level");
			} catch (Exception e) { } 
			
			String level_name = (String) jsonObject.get("name");
			
			JSONArray msg = (JSONArray) jsonObject.get("bricks");
			
			Iterator<JSONObject> iterator = msg.iterator();
			
			while (iterator.hasNext()) {
				JSONObject tmp_obj = iterator.next();
				int tmp_x = ((Long)(tmp_obj.get("x"))).intValue();
				int tmp_y = ((Long)(tmp_obj.get("y"))).intValue();
				int hp = 1;
				String pp = "";
				try {
					hp = ((Long)(tmp_obj.get("hp"))).intValue();
				} catch (Exception e) {}
				try {
					pp = (String)tmp_obj.get("powerup");
				} catch (Exception e) {}
				pp = (pp == null) ? "null" : pp;
				String tmp_id = (String)tmp_obj.get("id");
				Brick tmp_brick = new Brick(tmp_x,tmp_y , tmp_id, hp, pp);
				brks.add(tmp_brick);
			}
			
		} catch (IOException  e) {
			e.printStackTrace();
		} catch (ParseException e) {
			e.printStackTrace();
		}
		return brks;
	}


}