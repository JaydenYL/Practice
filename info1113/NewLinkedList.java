public class NewLinkedList<T> {
	private int size  = 0;
	private  Node<T> beginner;
	
	public  NewLinkedList(){
		
	}
	void add(T newele){
		if (beginner == null){
			beginner = new Node<T>(newele);
		}else {
			Node<T> temp = beginner;
			while (temp.getNext() != null){
				temp = temp.getNext();
			}
			temp.setNext(newele);
		}
		this.size++;
	}
	
	public int size(){
		return this.size;
	}
	
}




class Node<T> {
	private T ele;
	private Node<T> nextNode;
	
	public Node(T value){
		this.ele = value;
	}
	
	Node<T> getNext(){
		return this.nextNode;
	}
	
	T getEle(){
		return this.ele;
	}
	
	void setNext(T next){
		this.nextNode = new Node<T>(next);
	}
}