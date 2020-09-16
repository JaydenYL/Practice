public class Studio{
    private String name;
    private String location;
    private Film[] movies;

    public Studio(String n, String l, Film[] f){
        name = n;
        location = l;
        movies = f;
    }

    public String getName(){
        return name;
    }

    public String getLocation(){
        return location;
    }

    public Film[] getMovies(){
        return this.movies;
    }
}
