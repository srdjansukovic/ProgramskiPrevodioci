//OPIS: poziv funkcije sa gde parametri i argumenti nisu istog tipa

int f(int x, int y) {
    int a,b,c;
	return x + y;
}
void main() {
    int a,b,c;
	unsigned d;
	c = f(b, d);
}

