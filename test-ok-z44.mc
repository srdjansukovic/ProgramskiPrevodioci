//OPIS: ternarni operator u pozivu funkcije
//RETURN: 8

int f(int a){
	return a;
}

int main() {
	int y;
	int x;
	x = 5;
	y = 3;
    return f((y > 5) ? 2 : x + 3);
}

