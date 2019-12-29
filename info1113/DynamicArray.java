public class DynamicArray {
	private int[] array; 
	private long size; 
	private long capacity;
	
	public static void main(String[] args){
		
	}
	
	public DynamicArray(int capacity){
		this.array = new int[capacity];
		this.capacity = capacity;
		this.size = 0;
	}

	/**
	 * @param index gets the value from a specific index
	 * @return element stored at index
	*/
	public int get(int index){
		return this.array[index];
	}

	 /**
	 * Sets an element at a specified index
	 * @param element to be stored at index
	 * @param index index which element will be stored
	 */
	public void set(int element, int index){
		this.array[index] = element;
	}
	 /**
	 * Adds an element at the end of the list
	 * @param element to be stored at size
	*/
	public void add(int element){
		this.array[(int)this.size++] = element;
		if (this.size == this.capacity){
			int[] temp = new int[2*(int)this.size];
			for(int i = 0;i < size; i++){
				temp[i] = this.array[i];
			}
			this.capacity *= 2;
			this.array = temp;
		}
	}
	/**
	 * @param index Removes an element from a specific index
	 * @return element returns the element that has been removed
	*/
	public int remove(int index){
		int[] temp = new int[(int)this.capacity];
		int re_int = this.array[index];
		for(int i = 0; i < this.size - 1; i++){
			temp[i] = (i>=index)?this.array[i+1]:this.array[i];
		}
		this.array = temp;
		this.size--;
		return re_int;
	}

	public void showElement(){
		System.out.print("{ ");
		for(int i = 0,len = (int)this.size;i<len;i++){
			System.out.print(this.array[i]+((i<len-1)?", ":" }\n"));
		}
	}
}