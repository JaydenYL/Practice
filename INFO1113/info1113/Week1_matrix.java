import java.util.*;

class MatrixMult {
	public static void main(String[] args) {
		Scanner keyb = new Scanner(System.in);
		int m_1=keyb.nextInt(), n_1=keyb.nextInt(), m_2=keyb.nextInt(),  n_2=keyb.nextInt();
		int[][] mat_1 = new int[n_1][m_1], mat_2 = new int[n_2][m_2];
		getNumber(mat_1);
		getNumber(mat_2);
		if (m_1 != n_2){System.out.println("Invalid input.");System.exit(1);}
		int[][] multip = new int[n_1][m_2];
		for(int i = 0;i<multip.length;i++){
			for (int j = 0, sum;j< multip[i].length;j++){
				sum = 0;
				for (int k = 0; k<m_1;k++){
					sum += mat_1[i][k]*mat_2[k][j];
				}
				multip[i][j] = sum;
			}
		}
		showMatrix(multip);
	}
	
	
	
	public static void getNumber(int[][] mat){
		Scanner keyb = new Scanner(System.in);
		for(int i = 0, j;i<mat.length;i++){
			j = 0;
			for(; j<mat[i].length; j++){
				mat[i][j] = keyb.nextInt();
			}
		}
	}
	
	public static void showMatrix(int[][] mat){
		for(int i=0 ;i<mat.length;i++){
			for(int j=0 ;j<mat[i].length;j++){
				System.out.print(mat[i][j]+((i<mat[i].length-1)?" ":""));
			}
			System.out.println();
		}
	}
	
	
}