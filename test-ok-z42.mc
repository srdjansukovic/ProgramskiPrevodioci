//OPIS: ternarni operator komplikovaniji
//RETURN: 13

int y;

int main() {
	int a;
	int x;
	x = 4;	
	y = 5;
	a = 10 + (y > 5) ? x + 2 : 3;
    return a;
}

