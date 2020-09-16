import java.time.LocalDate;

public class Actor{
    private String name;
    private LocalDate dateOfBirth;
    private LocalDate dateOfDeath;
    private Film[] movies;
    // public static void main(String[] args)
    public Actor(String name, LocalDate birthDate, LocalDate deathDate, Film[] movies){
        this.name = name;
        this.dateOfBirth = birthDate;
        this.dateOfDeath = deathDate;
        this.movies = movies;
    }

    public String getName(){
        return this.name;
    }

    public LocalDate getBirth(){
        return this.dateOfBirth;
    }
    
    public String getBirthString(){
        return this.dateOfBirth.toString();
    }

    public LocalDate getDeath(){
        return this.dateOfDeath;
    }

    public String getDeathString(){
        if (this.dateOfDeath == null){
            return "Alive";
        }
        return this.dateOfDeath.toString();
    }

    public Film[] getMovies(){
        return this.movies;
    }
      
}
