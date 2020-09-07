import java.util.Iterator;


public class MyLinkedList<T> implements Iterable<T>{
	
	public Node<T> head;
	private long size;
	
	public MyLinkedList(Node<T> head){
		this.size = 0;
		this.head = head;
	}
	
	
	public MyLinkedList(){
		this(null);
	}
	
	
	public long size(){
		return this.size;
	}
	
	
	public void add(T value){
		if(head == null) this.head = new Node<T>(value);
		else{
			Node<T> cursor = head;
			while (cursor.next != null){
				cursor = cursor.next;
			}
			cursor.next = new Node<T>(value);
		}
		size++;
	}
	
	
	public void set(int index, T value){
		if (index < 0 || index >= size) return ;
		
	}
	
	
	public T remove(int index) {
		if (index < 0 || index >= this.size) return null;
		T e = null;
		long counter = 0;
		Node<T> current = head;
		if (index == 0) {
			e = head.value;
			this.head = this.head.next;
		} else {
			while (current.next != null && counter < index-1){
				current = current.next;
				counter ++;
			}
			e = current.next.value;
			current.next = current.next.next;
			
		}
		return e;
	}
	
	
	public void insert(T ele, int index){
		if (index <0 || index >= size) return;
		Node<T> cur = head;
		int counter = 0;
		Node<T> node = new Node<T>(ele);
		if (index == 0){
			node.next = head;
			this.head = node;
		} else {
			while( cur != null && counter < index -1){
				cur = cur.next;
				counter ++;
			}
			node.next = cur.next;
			cur.next = node;
		}
	}
	
	
	public Node<T> getNode(int idx){
		if (idx < 0 || idx >= size) return null;
		Node<T> cursor = head;
		int i = 0;
		while (i < idx){
			cursor = cursor.next;
			i ++;
		}
		return cursor;
	}
	
	public MyIter<T> iterator(){
		return new MyIter<T>(head);
	}
	
}



class Node<E>{
	
	public  E value;
	public Node<E> next;
	
	public Node(E v){
		this.value = v;
		next = null;
	}
	
	public E getEle(){
		return this.value;
	}

}



class MyIter<T> implements Iterator<T>{
	private Node<T> cur;
	
	public MyIter(Node<T> head){
		cur = head;
	}
	
	public boolean hasNext(){
		return cur != null;
	}
	
	public T next(){
		T v = this.cur.value;
		this.cur = cur.next;
		return v;
	}
}