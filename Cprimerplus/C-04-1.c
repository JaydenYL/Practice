// rand1() , srand1()

static unsigned long int next = 1; 

int rand1(void)
{
	next = next*1103515245 + 12345;
	return (unsigned int ) (next/65536) % 32768;
}

void srand1(unsigned int seed)
{
	next = seed;
}