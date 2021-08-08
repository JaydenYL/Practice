import java.util.*;
import javax.management.*;

enum NodeType {PLACEHOLDER, NUMBER, OPERATOR}

class Node {
	NodeType type;
	char chr;
	double value;
	Node left;
	Node right;
	Node parent;
	
	public Node(String ch){
		this.type = (!ch.equalsIgnoreCase("X")) ? NodeType.OPERATOR : NodeType.PLACEHOLDER;
		this.chr = ch.charAt(0);
	}
	
	public Node(double value) {
		this.type = NodeType.NUMBER;
		this.value = value;
	}
	
	public static Node newNode(String info){
		if (info.equals("+") || info.equals("-") || 
			info.equals("*") || info.equals("/") ||
			info.equals("^")) {
				return new Node(info);
		} else if (info.equalsIgnoreCase("x")) {
			return new Node(info);
		} else {
			return new Node(Double.parseDouble(info));
		}
	}
	
	public double calculate(double num){
		if (this.type == NodeType.OPERATOR) {
			switch (this.chr) {
				case '+':
					return left.calculate(num) + right.calculate(num);
				case '-':
					return left.calculate(num) - right.calculate(num);
				case '*':
					return left.calculate(num) * right.calculate(num);
				case '/':
					return left.calculate(num) / right.calculate(num);
				case '^':
					return Math.pow(left.calculate(num), right.calculate(num));
			}
		} else if (this.type == NodeType.PLACEHOLDER) {
			return num;
		}
		return value;
		
	}
	
	
	public  Node getNextAvailable() {
		Node cur = this;
		while (cur.right != null) {
			cur = cur.parent;
		}
		return cur;
	}
	
	
	public void pre_traverse(){
		System.out.println(type);
		if (left == null) return;
		left.pre_traverse();
		right.pre_traverse();
	}

}


class Expression {
	
	// Round x to n decimal places.
	public static double round(double x, int n) {
		return Math.floor(x * Math.pow(10, n) + 0.5) / Math.pow(10, n);	
	}
	
	
	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		String[] ary = stdin.nextLine().split(" ");
		String[] numbers = stdin.nextLine().split(" ");
	
		Node root = buildTree(ary);
		double ans;
		for(int i = 0; i < numbers.length; i++){
			ans = round(root.calculate(Double.parseDouble(numbers[i])), 5);
			System.out.print(ans);
			System.out.print((i == numbers.length -1)? "\n" : " ");
		}
		
	}
	
	public static Node buildTree(String[] ary) {
		Node root = Node.newNode(ary[0]);
		Node cur = root;
		Node tmp;
		for (int i = 1; i < ary.length; i++){
			
			tmp = Node.newNode(ary[i]);
			tmp.parent = cur;
			if (cur.left == null) {
				cur.left = tmp;
				if (tmp.type == NodeType.OPERATOR){
					cur = tmp;
				}
			} else if (cur.right == null) {
				cur.right = tmp;
				if (tmp.type == NodeType.OPERATOR){
					cur = tmp;
				} else {
					if (i != ary.length - 1)
						cur = cur.getNextAvailable();
				}
			} else {
				System.out.println("Error!");
				System.exit(1);
			}
		}
		
		return root;
		
	}
	
	
}