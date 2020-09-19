import java.time.LocalDate;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Arrays;
import java.util.Set;

public class VideoStore{
    private String name;
    private String location;
    private Map<Film, Integer> movies;

    
    public VideoStore(String n, String lc){
        this.name = n;
        this.location = lc;
        this.movies = new HashMap<Film, Integer>();
    }

    public String getName(){
        return this.name;
    }

    public String getLocation(){
        return this.location;
    }

    
    public Map getMovies(){
        return this.movies;
    }

    public void  addMovie(Film flm){
        if (flm == null) return;
        if (movies.containsKey(flm)){
            movies.put(flm, movies.get(flm)+1);
        } else {
            movies.put(flm, 1);
        }
    }

    public boolean rentMovie(Film flm){
        if (flm == null){
            return false;
        }
        if (! movies.containsKey(flm) || movies.get(flm) == 0){
            return false;
        }
        
        movies.put(flm, movies.get(flm)-1);
        return true;
    }

    public Film[] getMoviesByGenre(String gn){
        if (gn == null){
            return null;
        }
        ArrayList<Film> list = new ArrayList<Film>();
        for(Film ele : movies.keySet()){
            if (ele.getGenre().equals(gn)){
                list.add(ele);
            }
        }
        return FilmArray(list);
    }


// -------------------------------------------
    public Film[] getMoviesWithActors(Actor[] acts){
        if (acts == null){
            return null;
        }
        ArrayList<Film> list = new ArrayList<Film>();
        // Arrays.stream(movies.keySet().toArray()).filter(ele -> (Arrays.stream(acts).filter(e ->ele.getActors().contains(e)))).forEach(ele -> list.add(ele));


        // Set.stream(movies.keySet()).filter(ele -> (Arrays.stream(acts).filter(e ->ele.getActors().contains(e)))).foeEach(ele -> list.add(ele));
        for (Film ele : movies.keySet()){
            for(int i = 0; i < acts.length; i++){
                if ( ! Arrays.asList(ele.getActors()).contains(acts[i])){
                    break;
                } else if (i == acts.length -1 ){
                    list.add(ele);
                }
            }
        }
        

        return FilmArray(list);
    }


    public Film[] getMoviesByStudio(String std){
        if (std == null) {
            return null;
        }
        ArrayList<Film> list = new ArrayList<Film>();
        for(Film ele : movies.keySet()){
            if (ele.getStudio().getName().equals(std)){
                list.add(ele);
            }
        }

        return FilmArray(list);
    }


    public Film[] getAvailableMovies(){
        ArrayList<Film> list = new ArrayList<Film>();
        for(Film ele : movies.keySet()){
            if (movies.get(ele) > 0){
                list.add(ele);
            }
        }

        return FilmArray(list);
    }


    public Film[] getMoviesWithoutCopyright(){
        ArrayList<Film> list = new ArrayList<Film>();
        for(Film ele : movies.keySet()){
            if ( !ele.copyrighted()){
                list.add(ele);
            }
        }

        return FilmArray(list);
    }


    public Film[] FilmArray(ArrayList<Film> list){
        Film[] res = new Film[list.size()];
        for(int i = 0; i < res.length; i++) {
            res[i] = list.get(i);
        }
        return res;
    }


}

