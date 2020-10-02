import java.util.*;
import java.io.*;

class DVD{
	private String name;
	private String[] subtitledLanguages;
	private boolean highDefinition;
	private String publisher;
	public DVD(String name, String[] sl, boolean hd, String pb){
		this.name = name;
		this.subtitledLanguages = sl;
		this.highDefinition = hd;
		this.publisher = pb;
		
	}
	
	public boolean getHighDefinition(){
		return this.highDefinition;
	}
	
	public void setHighDefinition(boolean hd){
		this.highDefinition = hd;
	}
	
	static void readLinesEnd(String fileName, char end){
		if (fileName == null){
			return;
		}
		Scanner scan = null;
		try {
			scan = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			System.out.println("No such file");
			return;
		}
		boolean has = false;
		String line;
		while(scan.hasNextLine()){
			line = scan.nextLine();
			if(line.charAt(line.length() - 1) == end){
				System.out.println(line);
				has = true;
			}
		}
		if (! has){
			System.out.printf("No lines end with %c\n", end);
		}
	}
	
	public static int antiSubArrayCount(int[][] matrix, int[] sub){
		if(matrix == null || sub == null) {
			return -1;
		}
		int count = 0;
		for(int i = 0; i < matrix.length; i++){
			if(matrix[i] == null){
				continue;
			}
			boolean found = false;
			for(int j = 0; j < matrix[i].length - sub.length + 1; j++){
				for(int k =0; k < sub.length; k++){
					if (sub[k] != matrix[i][j+k]){
						break;
					}else if(k == sub.length-1){
						found = true;
						count ++;
						break;
					}
				}
				
				if (found){
					break;
				}
			}
		}
		
		return matrix.length - count;
	}
	
	
	
	
	
	
	public   static void main(String[] b){
		readLinesEnd("NewFile.txt", 'e');
		int[][] ar = new int[][] {{1,2,3,4}, {0,1,2,3}, {1,2,1,2}, {0, 0,0,0}};
		int[] sub = {1,2};
		System.out.println( antiSubArrayCount(ar, sub));
	}
	
	
}