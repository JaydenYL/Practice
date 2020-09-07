public class  DoubleLinkedList{

	public Dnode<T> head;
	public Dnode<T> tail;
	private int size ;

	public DoubleLinkedList(){
		head = null;
		tail = null;
		size = 0;
	}
	
	public T get(int idx){
// index > 0  or < 0
// tail = null ? 
		Dnode<T> cursor = this.head
		int c = 0;
		while ( c < idx){ 
			cursor = cursor.next ;
		}
		return cursor.value;
	}
	
	public void add( T val){
		if(this.tail == null){
			this.head = new Dnode<T>(val, null);
		}else{
			this.tail.next = new Dnode<T>(val, null);
			this.tail = this.tail.next;
		}
	}
	

	
	public void remove( Dnode<T> ){
		
	}
	
	

	public int size(){
		return this.size;
	}
	
}

