//OPIS: switch iskaz bez break sa propadanjem
//RETURN: 7
int main() {
	int a;
	a = 2;
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
	end_switch

	return a;
}
