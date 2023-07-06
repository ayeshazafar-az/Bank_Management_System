//file handling (present)
//class (present)
//function overloading (present)
//inheritance (present)
//if-of stream (present)
//SYED ABDULLAH RAZA(ACS213056)
//HAFIZ HAMID AHMED KHAN (ACS213005)
//AYESHA ZAFAR(ACS213060)


//HEADERFILES
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

class account //class
{
	int acno;
	char name[50];
	int deposit;
	char type;
	public:
	void Aboutbank()
	{
		cout<< "|***STATE BANK OF PAKISTAN***|\n\n";
		cout<<"\t\t\t\t|    BANK TOTAL REVENUE:     |\n";
		cout<<"\t\t\t\t|        20 MILLION. \t     |\n\n";
	}
	void create_account();
	void show_account() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
};
class aboutbank :public account // Inheritance
{
public:
	aboutbank()
	{
		Aboutbank();
	}
};
//FUNCTION DEFINE:
void account::create_account()
{
	system("CLS");

	cout << "\n\t\t\tEnter the Account No. : " << "\n\t\t\tAtleast 8 Digits:\t";
	cin >> acno;
	cout << "\n\n\t\t\tEnter the Name of the Account holder (first name only): ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\n\t\t\tEnter Type of the Account (C/S) : ";
	cin >> type;
	type = toupper(type);
	cout << "\n\t\t\tEnter The Initial amount : ";
	cin >> deposit;
	cout << "\n\n\t\t\tAccount Created..";
}

void account::show_account() const
{
	cout << "\n\t\t\tAccount No. : " << acno;
	cout << "\n\t\t\tAccount Holder Name: ";
	cout << name;
	cout << "\n\t\t\tType of Account : " << type;
	cout << "\n\t\t\tBalance amount : " << deposit;
}

void account::modify()
{
	cout << "\n\t\t\tAccount No. : " << acno;
	cout << "\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\n\t\t\tModify Type of Account : ";
	cin >> type;
	type = toupper(type);
	cout << "\n\t\t\tModify Balance amount : ";
	cin >> deposit;
}
void account::dep(int x)
{
	deposit += x;
}
void account::draw(int x)
{
	deposit -= x;
}
void account::report() const
{
	cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << "\t" << deposit << endl;
}
int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}


//FILE HANDLING FUNCTION PROTOTYPE
void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);

int main()//main function
{
	system("color 1E");
	char ch;
	int num;
	do
	{
		system("CLS");
		cout << "\n\n\t\t\t\t|****************************|";
		cout << "\n\n\t\t\t\t|   ======================   |\n";
		cout << "\t\t\t\t|   BANK MANAGEMENT SYSTEM   |";
		cout << "\n\t\t\t\t|   ======================   |\n\n\t\t\t\t";
		aboutbank bank;
		
		cout << "\t\t\t\t|      ::MAIN MENU::         |" << endl;
		cout << "\t\t\t\t|                            |" << endl;
		cout << "\t\t\t\t|1. NEW ACCOUNT              |";
		cout << "\n\t\t\t\t|2. DEPOSIT AMOUNT           |";
		cout << "\n\t\t\t\t|3. WITHDRAW AMOUNT          |";
		cout << "\n\t\t\t\t|4. BALANCE ENQUIRY          |";
		cout << "\n\t\t\t\t|5. ALL ACCOUNT HOLDER LIST  |";
		cout << "\n\t\t\t\t|6. CLOSE AN ACCOUNT         |";
		cout << "\n\t\t\t\t|7. MODIFY AN ACCOUNT        |";
		cout << "\n\t\t\t\t|8. EXIT                     |";
		cout << "\n\n\t\t\t\t|****************************|";
		cout << "\n\n\t\t\t\t Select Your Option (1-8): ";
		cin >> ch;


		switch (ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			system("CLS");
			cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			system("CLS");
			cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			system("CLS");
			cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("CLS");
			cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
			delete_account(num);
			break;
		case '7':
			system("CLS");
			cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
			modify_account(num);
			break;
		case '8':
			system("CLS");
			cout << "\n\n\t\t\tBrought To You By THE STRIVERS ";
			cout << "\n\n\t\t\t********************** " << endl;
			cout << "\t\t\t|GROUP MEMBERS:      |" << endl;
			cout << "\t\t\t|                    |" << endl;
			cout << "\t\t\t|Syed Abdullah Raza  |" << endl;
			cout << "\t\t\t|Ayesha Zafar        |" << endl;
			cout << "\t\t\t|Hafiz Hamid Khan    |" << endl;
			cout << "\t\t\t********************** ";
			cout << "\n\n\t\t\t\tThank you for using our banking system ";
			break;
			default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (ch != '8');
	system("pause");
	return 0;
}


void write_account()//filehandling
{
	account ac;
	ofstream outFile;//ofstream
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n)
{
	account ac;
	bool flag = false;
	ifstream inFile;//ifstream
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
		cout << "\n\t\t\tBALANCE DETAILS\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
		if (ac.retacno() == n)
		{
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\n\t\t\tAccount number does not exist";
}

void modify_account(int n)
{
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
	File.read(reinterpret_cast<char*> (&ac), sizeof(account));
	if (ac.retacno() == n)
		{
			ac.show_account();
			cout << "\n\n\t\t\tEnter The New Details of account" << endl;
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t\t\tRecord Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n\t\t\tRecord Not Found ";
}

void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	
	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
	if (ac.retacno() != n)
		{
			outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
		}
	}
	
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat", "account.dat");
	cout << "\n\nRecord Deleted ..";
}

void display_all()
{
	system("CLS");
	account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "========================================================\n";
	cout << "A/c no.\t\t  NAME\t\tType\t\tBalance\n";
	cout << "========================================================\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}


void deposit_withdraw(int n, int option)
{
		int amt;
		bool found = false;
		account ac;
		fstream File;
		File.open("account.dat", ios::binary | ios::in | ios::out);
		if (!File)
		{
			cout << "File could not be open !! Press any Key...";
			return;
		}
		while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			if (option == 1)
			{
				cout << "\n\n\t\t\tTO DEPOSIT AMOUNT";
				cout << "\n\n\t\t\tEnter The amount to be deposited: ";
				cin >> amt;
				ac.dep(amt);
			}
			if (option == 2)
			{
				cout << "\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout << "\n\n\t\t\tEnter The amount to be withdraw: ";
				cin >> amt;
				int bal = ac.retdeposit() - amt;
				if (bal < 0)
				cout << "\n\t\t\tInsufficience balance";
				else
				ac.draw(amt);
			}
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur);//fn1353
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t\t\tRecord Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
	cout << "\n\n\t\t\tRecord Not Found ";
}