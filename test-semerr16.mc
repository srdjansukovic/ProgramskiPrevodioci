//OPIS: switch iskaz i nejedinstveni case literali
int main() {
	int a;
	switch a
		case 1
			a = a + 5;
			break;
		case 1
			a = a / 2;
		case 3
			{
				a = a * 8;
			}
		default
			a = a - 1;
	end_switch
}
