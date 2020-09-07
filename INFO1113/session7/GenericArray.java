class GenericArray<T> {
	private T[] array;
	
	public GenericArray(){
		
	}
	
	
	public T set(int index, T element){
		if (index < 0 || index >= size()) return null;
		array[index] = element;
		return element;
		
	}
	
	public T get(int index) throws Exception{
		
		if (index < 0 || index >= size()) throw new IndexOutOfBoundsException();
		return array[index];
	}
	
	@SuppressWarnings("unchecked")
	public long resize(long newsize){
		T[] newarray = (T[])(new Object[(int)newsize]);
		long oldsize = size();
		for(int i = 0 ; i < oldsize ; i++){
			newarray[i] = array[i];
		}
		array = newarray;
		return oldsize;
	}
	
	
	public long size(){
		return array.length;
	}
}