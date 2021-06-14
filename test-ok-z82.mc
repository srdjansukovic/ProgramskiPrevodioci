//OPIS: post inkrement i if-else
//RETURN: 4

int main() {
	int x;
	int y;
	int z;
	x = 2;
	y = 4;
	z = 6;
	if(x != 2){
		y = 3 + x++;
	}
	else{
		x++;
		x++;
	}
    return x;
}

