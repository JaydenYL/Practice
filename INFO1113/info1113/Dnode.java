public class Dnode< T > {
	public T value;
	public Dnode<T> next;
	public Dnode<T> prev;
	
	public Dnode(T val, Dnode<T> previous){
		this.value = val;
		this.prev = previous;
		previous.next = this;
	}
	
}