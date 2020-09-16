import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Arrays;

public class Film{
    private String name;
    private Studio studio;
    private LocalDate release;
    private String genre;
    private String plot;
    private Actor[] actors;
    // public static void main(String[] args)
    public Film(String name, Studio s, LocalDate ld,  String gen, String plt, Actor[] acts){
        this.name = name;
        this.studio = s;
        this.release = ld;
        this.genre = gen;
        this.plot = plt;
        this.actors = acts;
    }

    public String getName(){
        return this.name;
    }
    
    public Studio getStudio(){
        return this.studio;
    }

    public LocalDate getRelease(){
        return this.release;
    }

    public String getGenre(){
        return this.genre;
    }

    public String getPlot(){
        return this.plot;
    }

    public Actor[] getActors(){
        return actors;
    }

    public String getStudioLocation(){
        return studio.getLocation();
    }

    public boolean copyrighted(){
		return  2020 - this.release.getYear() <= 75 ;
    }

    public Actor[] sharedActors(Film flm){
        if (flm == null){
            return null;
        }
        ArrayList<Actor> list = new ArrayList<Actor>();
        Arrays.stream(flm.actors).filter(ele -> Arrays.asList(actors).contains(ele)).forEach(ele -> list.add(ele));
        Actor[] arr = new Actor[list.size()];
        for (int i = 0; i < list.size(); i++) {
            arr[i] = list.get(i);
        }
        return arr;
    }
      
}
