package breaker;

import processing.core.PApplet;
import processing.core.PImage;
import processing.core.PGraphics;
import processing.core.PFont;
import java.util.*;

public class App extends PApplet {
    
    PImage bkimg , pad , bal , bkg;
    ArrayList<Ball> balls = new ArrayList<Ball>();
    ArrayList<PowerUp> magic = new ArrayList<PowerUp>();
    ArrayList<Brick> bricks = new ArrayList<Brick>();
    ArrayList<Paddle> paddles = new ArrayList<Paddle>();
    GameManager manager = new GameManager("three_bricks");
    
    public void settings() {
        size(520, 400);
        Sound.playLoop("bgm.wav");
    }
    

    public void setup() {
        frameRate(60);
        bkimg = loadImage("bkg.png"); pad = loadImage("paddle.png"); bal = loadImage("ball.png"); 
        PFont f = createFont("PressStart2P-Regular.ttf", 24);
        textFont(f);
    }


    public void draw() {
        background(bkimg);
        for(Paddle paddle_1 : paddles){
            image(pad, (int)paddle_1.x, (int)paddle_1.y, (int)paddle_1.width, (int)paddle_1.height);
            if (paddle_1.paddleup) text(paddle_1.timer/60+" s", 0, 360);
        }
        
        for (Brick b : bricks){
            if(!(b==null) && !b.broken)  image(loadImage(b.img), b.x, b.y);
        }

        for (Ball b : balls){
            image(bal, (int)b.x, (int)b.y);
        }
        
        for (PowerUp p : magic){
            image(loadImage(p.image), (int)p.x, (int)p.y);
        }
    
        int status = manager.condition;
        switch (status) {
            case 1: // game beginning
                text("play", 220, 200);
                text(manager.currentlevel, 220 , 260);
                if (mousePressed && Math.abs(mouseX - 260) < 20 && Math.abs(mouseY - 200) < 20 || (manager.currentlevel != manager.firstlevel && manager.showMessage(mousePressed))){
                    manager.initailize(balls, bricks, paddles, magic);
                }
                break;
            case 2: // playing game
                manager.tick(balls, bricks, magic, paddles);
                break;
            case 3: // lose or win 
                text("Next", 240, 200);
                manager.showMessage(mousePressed);
                break;
            case 4:
                text("Game Over", 160, 200);
                manager.showMessage(mousePressed);
                break;
            case 5:
                text("YOU WIN", 180, 200);
                manager.showMessage(mousePressed);
        }
    }


    public void keyPressed(){
        if (key == 'A' || key == 'a' || keyCode == LEFT)   paddles.get(0).lf_move = true;
        else if (key == 'D' || key == 'd' || keyCode == RIGHT)    paddles.get(0).rt_move = true;
    }
    
    
    public void keyReleased(){
        paddles.get(0).lf_move = false;
        paddles.get(0).rt_move = false;
    }
    

    public static void main(String[] args) {
        PApplet.main("breaker.App");
    }
}