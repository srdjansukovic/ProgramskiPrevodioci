//OPIS: switch iskaz bez end_switch tokena
int main() {
	int a;
	switch a
		case 1
			a = a + 5;
			break;
		case 2
			a = a / 2;
		case 3
			{
				a = a * 8;
			}
		default
			a = a - 1;

}
