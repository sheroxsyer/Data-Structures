#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int choice;
	int tacoQuant=0;
	int enchQuant=0;
	int tamaQuant=0;
	int nachQuant=0;
	int drnkQuant=0;
	double subTotal;
	double tax;
	double totalDue;
	double tacoTotal=0;
	double enchTotal=0;
	double tamaTotal=0;
	double nachTotal=0;
	double drnkTotal=0;
	
	cout<<"			Welcome to Daniel's Mexicafeteria!"<<endl;
	cout<<"Please continue to make all your selections by using the item number on the left"<<endl;
	cout<<"When you are finished type 'E' to exit."<<endl;
	cout<<endl;
	cout<<"..................................MENU........................................"<<endl;
	cout<<"Item# Description--------------------------------------------------------Price"<<endl;
	cout<<"______________________________________________________________________________"<<endl;
	cout<<"[100] Taco dinner:  2 tacos, rice and beans...............................5.95"<<endl;
	cout<<endl;
	cout<<"[200] Enchilada dinner:  2 cheese enchiladas, rice and beans..............6.95"<<endl;
	cout<<endl;
	cout<<"[300] Tamale dinner:  2 pork tamales, rice and beans......................4.95"<<endl;
	cout<<endl;
	cout<<"[400] Loaded nachos: chips with beef or chicken, cheese and jalapenos.....3.95"<<endl;
	cout<<endl;
	cout<<"[500] DRINKS one-size and free refills......................................95"<<endl;
	cout<<endl;

	while(choice=100||200||300||400||500){
	cin>>choice;

	switch (choice)
	{
	case 100:
		tacoQuant=tacoQuant+1;
		tacoTotal=tacoQuant*5.95;
		break;
	case 200:
		enchQuant=enchQuant+1;
		enchTotal=enchQuant*6.95;
		break;
	case 300:
		tamaQuant=tamaQuant+1;
		tamaTotal=tamaQuant*4.95;
		break;
	case 400:
		nachQuant=nachQuant+1;
		nachTotal=nachQuant*3.95;
		break;
	case 500:
		drnkQuant=drnkQuant+1;
		drnkTotal=drnkQuant*.95;
		break;
	default:
		system("cls");
		system("color A");
		cout<<endl;
		cout<<endl;
		cout<<"You have ordered the following:"<<endl;
		cout<<"___________________"<<endl;
		if(tacoQuant!=0){
			cout<<tacoQuant<<"  #100      "<<tacoTotal<<endl;
		}
		if(enchQuant!=0){
			cout<<enchQuant<<"  #200      "<<enchTotal<<endl;
		}
		if(tamaQuant!=0){
			cout<<tamaQuant<<"  #300      "<<tamaTotal<<endl;
		}
		if(nachQuant!=0){
			cout<<nachQuant<<"  #400      "<<nachTotal<<endl;
		}
		if(drnkQuant!=0){
			cout<<drnkQuant<<"  #500      "<<drnkTotal<<endl;
		}
		cout<<fixed<<setprecision(2)<<endl;
		cout<<"___________________"<<endl;
		subTotal=(tacoTotal+enchTotal+tamaTotal+nachTotal+drnkTotal);
		tax=(subTotal*.075);
		totalDue=(subTotal+tax);
		cout<<"Subtotal     "<<subTotal<<endl;
		cout<<"Tax          "<<tax<<endl;
		cout<<"___________________"<<endl;
		cout<<"Total Due    "<<totalDue<<endl;
	}
	}
		
return 0;
}