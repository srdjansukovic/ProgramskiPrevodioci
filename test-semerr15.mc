//OPIS: switch iskaz i razliciti tipovi case literala
int main() {
	int a;
	switch a
		case 1
			a = a + 5;
			break;
		case 2u
			a = a / 2;
		case 3
			{
				a = a * 8;
			}
		default
			a = a - 1;
	end_switch
}
