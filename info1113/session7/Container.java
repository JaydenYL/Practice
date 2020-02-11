public class Container<T> {
	private T ele;
	
	public Container(T ele){
		this.ele = ele;
	}
	
	public boolean isNull(){
		return this.ele == null;
	}
	
	public T set(T new_ele){
		T tmp = this.ele;
		this.ele = new_ele;
		return tmp;
	}
	
	public T get(){
		return this.ele;
	}
	
}