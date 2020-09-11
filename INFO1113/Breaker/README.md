# Breaker

<br>

This is a simple brick destroy game which only has single player mode. I tried to develop the local multiplayer mode but i got in trouble with keyboard. I also tried to build local area network, just by ```import java.net.*; ```  =). As a result, I just add sound in the game.\
<br>
<br>

## Instruction

<br>

**Move**:  
* left : ```A``` , ```left arrow key ```
* right: ```D``` , ```right arrow key```

**Power Up**:
* Multi-ball ('multiball' in json), there are now 3 balls on screen
* Bigger Paddle for 60 seconds

**Level**:
* the Entry level : ```three_bricks.json```,  first_level: ```level_1.json```, second_level: ```level_2.json```
* Level will be provided by ```.json``` file which is as same dictionary as ```README.md``` .
* In ```App.java``` line 16 ,  you can modify the file of entry level  


**Gaming**:
* When you pass a level, there will be a 2 seconds pause or you can press mouse to continue.
* After winning , it will back to the entry level.

## Last but not least
Have a good time!