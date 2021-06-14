//OPIS: inkrement u numexp-u
//RETURN: 8

int y;

int main() {
    int x;
    x = 2;
    y = 6;

    if(x++ == y) {
      y = 2;
    }
	else{
		y = 3;
	}

    if(x - 1 < y++)
      x++;
    return x + y;
}

