//OPIS: switch iskaz bez default tokena
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
		
			a = a - 1;
	end_switch
}
