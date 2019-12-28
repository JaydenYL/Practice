import java.util.*;

class Question3to10 {
	public static void main(String[] args) {
		Athlete[] athletes = Athlete.Instantiate();
		System.out.println(athletes.length);
		Athlete.sort_athlete(athletes);
		for(int i = 0; i<athletes.length; i++){
			System.out.println(athletes[i].name +": "+athletes[i].time);
		}
	}
}

class Plant{
	boolean isAlive;
	int moistureLovel;
	String name;
	int hight;
	
	public Plant(boolean isAlive, int moistureLovel, String name, int h){
		this.isAlive = isAlive;
		this.moistureLovel = moistureLovel;
		this.name = name;
		this.hight = h;
	}
	
	void setnickname(String n){
		this.name = n;
	}
	
	String getnickname(){
		return this.name;
	}
	
	void water(){
		this.moistureLovel = 100;
	}
	
	boolean isDead(){
		return !this.isAlive;
	}
}

class Athlete{
	String name;
	float time;
	
	public Athlete(String name, float time){
		this.name = name;
		this.time = time;
	}
	
	static Athlete[] Instantiate(){
		Scanner keyb = new Scanner(System.in);
		String[] temp;
		String words;
		Athlete[] atheles = new Athlete[100];
		Athlete man;
		int count = 0;
		while (true){
			words = keyb.nextLine();
			if (words.equals("")){break;}
			temp = words.split(",");
			if(temp.length != 2){System.out.println("Invalid format"); continue;}
			try {
				man = new Athlete(temp[0], Float.parseFloat(temp[1]));
				atheles[count++] = man;
			} catch (Exception e) {
				System.out.println("Invalid input");
				continue;
			}
		}
		//resize the array
		Athlete[] r_array = new Athlete[count];
		for(int i = 0; i < count; i++){
			r_array[i] = atheles[i];
		}
		return r_array;
	}
	
	static void sort_athlete(Athlete[] athletes){
		int j = 0, i = 0, len = athletes.length - 1;
		Athlete mid;
		while (i < len){
			j = 0;
			while (j<len-i){
				if (athletes[j].time > athletes[j+1].time){
					mid = athletes[j];
					athletes[j] = athletes[j+1];
					athletes[j+1] = mid;
				}
				j ++;
			}
			i++;
		}
	}
}

class Pet{
	String name, species;
	String[] nicknames;
	int age;
	boolean trained;
	
	public Pet(String name, int age, String species, boolean trained){
		this.name = name;
		this.age = age;
		this.species = species;
		this.trained = trained;
	}
	
	public boolean equals(Pet p){
		if((this.name == p.name) && (this.age == p.age) && (this.species == p.species)){
			return true;
		}
		return false;
	}
	
	public void addNickname(String nickname){
		int len = this.nicknames.length + 1, i = 0;
		String[] temp = new String[len];
		for( ;i<len-1;i++){
			temp[i] = this.nicknames[i];
		}
		temp[i] = nickname;
		this.nicknames = temp;
	}
}

class CityPoint{
	int[] coor;
	String name, desc;
	
	public CityPoint(String name, String desc, int[] xy){
		this.name = name;
		this.desc = desc;
		this.coor = xy;
	}
	
	static CityPoint[] drive(int x1, int y1,int x2, int y2, CityPoint[][] city ){
		int total = Math.abs(x1+y1-x2-y2), num = 0;
		if ((x1 != x2) && (y1 != y2)) {total--;}
		CityPoint[] r_array = new CityPoint[total];
		if (x1 < x2){
			for (int i = x1; i<=x2; i++){
				r_array[num++] = city[y1][i];
			}
		}else {
			for (int i = x1; i>=x2; i--){
				r_array[num++] = city[y1][i];
			}
		}
		if (y1 < y2){
			for(int i = y1;i<=y2;i++){
				r_array[num++] = city[x2][i];
			}
		}else {
			for(int i = y1;i>=y2;i--){
				r_array[num++] = city[x2][i];
			}
		}
		return r_array;
	}
}