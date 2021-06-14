//OPIS: vise parametara
//RETURN: 16

int f(int a, int b, int c){
	return a + b + c;
}

int main() {
	int x;
	int y;
	int z;
	x = 2;
	y = 4;
	z = 6;
	x = f(x, y, z);
    return x + y;
}

