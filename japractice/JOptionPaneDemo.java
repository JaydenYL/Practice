import javax.swing.JOptionPane;

class JOptionPaneDemo
{
	public static void main(String[] args) 
	{
		String appleString = JOptionPane.showInputDialog("Enter number of apples:");
		int appleCount = Integer.parseInt(appleString);

		String orangeString = JOptionPane.showInputDialog("Enter number of oranges:");
		int orangeCount = Integer.parseInt(orangeString);

		int totalFruitCount = appleCount + orangeCount;
		JOptionPane.showMessageDialog(null, "The total number of fruits = " + totalFruitCount);
		System.exit(0);
	}
}