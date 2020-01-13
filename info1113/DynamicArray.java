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


	public int get(int index){
		return this.array[index];
	}


	public void set(int element, int index){
		this.array[index] = element;
	}


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