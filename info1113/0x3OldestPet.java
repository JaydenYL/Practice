class OldestPet {
	public static void main(String[] args) {
		Pet a = new Pet("alpha", 2, "None", true);
		Pet b = new Pet("beta", 3, "None", true);
		Pet c = new Pet("Cindy", 5, "None", true);
		Pet d = new Pet("Doggy", 3, "None", true);
		Pet e = new Pet("Erma", 8, "None", true);
		Pet f = new Pet("Frank", 6, "None", true);
		Pet[] pets = {a, b, c, d, e, f};
		System.out.println(OldestPet.oldest(pets).name);
	}

	public static Pet oldest(Pet[] pets){
		int len = pets.length, max = -1;
		Pet r_pet = new Pet("", 0, "", true);
		for(int i = 0; i < len; i++){
			if (pets[i].age > max){
				max = pets[i].age;
				r_pet = pets[i];
			}
		}
		return r_pet;
	}
}