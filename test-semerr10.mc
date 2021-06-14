//OPIS: poziv funkcije sa gde broj argumenata nije ispostovan

int f(int x, int y) {
    int a,b,c;
	return x + y;
}
void main() {
    int a,b,c;
	c = f(b);
}

