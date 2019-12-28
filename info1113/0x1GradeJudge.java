import java.util.*;

class GradeJudge {
	public static void main(String[] args) {
		System.out.print("Enter your grade: ");
		Scanner keyb = new Scanner(System.in);
		int gra = keyb.nextInt();
		String award = "_";
		if (gra > 100 || gra < 0){
			System.out.println("Invalid input!");
			System.exit(0);
		}
		if (gra >= 85 ){award = "High Distinction";}
		else if (gra >= 75) { award = "Distinction";}
		else if (gra >= 65) { award = "Credit";}
		else if (gra >= 50) { award = "Pass";}
		else if (gra >= 0 ) { award = "Fail";}
		System.out.println(award);
	}
}