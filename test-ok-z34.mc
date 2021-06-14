//OPIS: inkrement u pozivu void funkcije
//RETURN: 1

int y;

void f(int a) {
	int b;
	b = 5;
	return;
}


int main() {
    int x;
	x = 0;
	f(x++);
    return x;
}

