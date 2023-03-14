//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//#include <cctype>
//#include <iomanip>
//
//using namespace std;
//
//const string ClientsFileName = "Clients.txt";
//
//struct sClient {
//	string AccountNumber = "";
//	string PinCode = "";
//	string Name = "";
//	string Phone = "";
//	double AccountBalance = 0;
//	bool MarkForDelete = false;
//};
//
//
//enum enUserChoice {Show = 1 , Add = 2 , Delete = 3 , Update = 4 , Find = 5 , Exit = 6};
//
//
//vector <sClient> LoadClientsDataFromFile(string);
//
//string ReadAccountNumber();
//
//void ReadNewClientText() {
//	sClient Client;
//
//
//	cout << "Enter Account Number? ";
//	getline(cin >> ws, Client.AccountNumber);
//	cout << "Enter PinCode? ";
//	getline(cin, Client.PinCode);
//	cout << "Enter Name? ";
//	getline(cin, Client.Name);
//	cout << "Enter Phone? ";
//	getline(cin, Client.Phone);
//	cout << "Enter AccountBalance? ";
//	cin >> Client.AccountBalance;
//
//
//}
//

//sClient ReadNewClient() {
//
//	sClient Client;
//
//	vector <sClient> vClients;
//
//
//	vClients = LoadClientsDataFromFile(ClientsFileName);
//
//	cout << "Enter Account Number? ";
//	getline(cin >> ws, Client.AccountNumber);
//
//	for (sClient& C : vClients) {
//
//		if (C.AccountNumber == Client.AccountNumber) {
//
//			cout << "\n Client with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
//			getline(cin >> ws, Client.AccountNumber);
//		}
//	}
//	cout << "Enter PinCode? ";
//	getline(cin, Client.PinCode);
//	cout << "Enter Name? ";
//	getline(cin, Client.Name);
//	cout << "Enter Phone? ";
//	getline(cin, Client.Phone);
//	cout << "Enter AccountBalance? ";
//	cin >> Client.AccountBalance;
//
//
//	
//	return Client;
//
//}
//
//string ConvertRecordToLine(sClient Client, string Seperator = "#//#") {
//
//
//	string stClientRecord = "";
//
//
//	stClientRecord += Client.AccountNumber + Seperator;
//	stClientRecord += Client.PinCode + Seperator;
//	stClientRecord += Client.Name + Seperator;
//	stClientRecord += Client.Phone + Seperator;
//	stClientRecord += to_string(Client.AccountBalance);
//
//
//	return stClientRecord;
//
//
//}
//
//vector<string> SplitString(string S1, string Delim) {
//	vector<string> vString;
//	short pos = 0;
//	string sWord;
//	// define a string variable  
//	// use find() function to get the position of the delimiters  
//	while ((pos = S1.find(Delim)) != std::string::npos)
//	{
//		sWord = S1.substr(0, pos);
//		// store the word   if (sWord != "")       
//		{
//			vString.push_back(sWord);
//		}
//		S1.erase(0, pos + Delim.length());
//	} if (S1 != "")
//	{
//		vString.push_back(S1); // it adds last word of the string.  
//	} return vString;
//}

//
//sClient ConvertLinetoRecord(string Line, string Seperator = "#//#") {
//	sClient Client;
//	vector<string> vClientData;
//	vClientData = SplitString(Line, Seperator);
//	Client.AccountNumber = vClientData[0];
//	Client.PinCode = vClientData[1];
//	Client.Name = vClientData[2];
//	Client.Phone = vClientData[3];
//	Client.AccountBalance = stod(vClientData[4]);//cast string to double;
//
//	return Client;
//}
//
//
//void SaveDataLineToFile(string FileName, string stLine) {
//
//	fstream MyFile;
//
//	MyFile.open(FileName, ios::out | ios::app);
//
//	if (MyFile.is_open()) {
//
//		MyFile << stLine << endl;
//
//		MyFile.close();
//	}
//
//}
//
//vector <sClient> SaveDataLineToFileUsingVector(string FileName, vector <sClient> vClient) {
//
//	fstream MyFile;
//
//	MyFile.open(FileName, ios::out);
//
//	string DataLine;
//
//	if (MyFile.is_open()) {
//
//
//		for (sClient& C : vClient) {
//
//			if (C.MarkForDelete == false) {
//
//				DataLine = ConvertRecordToLine(C);
//				MyFile << DataLine << endl;
//
//			}
//
//
//		}
//
//
//		MyFile.close();
//	}
//	return vClient;
//
//}
//
//
//vector <sClient> LoadClientsDataFromFile(string FileName) {
//
//	fstream MyFile;
//	vector <sClient> vClients;
//
//	MyFile.open(FileName, ios::in);
//
//	if (MyFile.is_open()) {
//
//		string Line;
//		sClient Client;
//
//		while (getline(MyFile, Line)) {
//
//			Client = ConvertLinetoRecord(Line);
//			vClients.push_back(Client);
//
//		}
//	}
//
//
//	MyFile.close();
//
//	return vClients;
//
//}
//
//
//void AddNewClients() {
//
//	sClient Client;
//	Client = ReadNewClient();
//	SaveDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
//
//
//
//}
//
//void GoToMainMenuScreen();
//
//void AddClients() {
//
//	char AddMore = 'Y';
//
//	do {
//		system("cls");
//		cout << "Adding New Client:\n\n";
//		AddNewClients();
//		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
//		cin >> AddMore;
//
//
//	} while (toupper(AddMore) == 'Y');
//
//	GoToMainMenuScreen();
//
//}
//
//void PrintClientRecord(sClient Client)
//{
//	cout << "| " << setw(15) << left << Client.AccountNumber;
//	cout << "| " << setw(10) << left << Client.PinCode;
//	cout << "| " << setw(40) << left << Client.Name;
//	cout << "| " << setw(12) << left << Client.Phone;
//	cout << "| " << setw(12) << left << Client.AccountBalance;
//}
//
//void PrintAllClientsData(vector <sClient> vClients) {
//	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
//	cout << "\n_______________________________________________________";     cout << "_________________________________________\n" << endl;
//	cout << "| " << left << setw(15) << "Accout Number";
//	cout << "| " << left << setw(10) << "Pin Code";     cout << "| " << left << setw(40) << "Client Name";
//	cout << "| " << left << setw(12) << "Phone";     cout << "| " << left << setw(12) << "Balance";
//	cout << "\n_______________________________________________________";     cout << "_________________________________________\n" << endl;
//
//
//	for (sClient Client : vClients) {
//
//		PrintClientRecord(Client);
//		cout << endl;
//
//	}
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//}
//
//void PrintClientCard(sClient Client) {
//	cout << "\n_______________________________________________________";
//	cout << "\nThe following are the client details:\n";
//	cout << "\nAccout Number: " << Client.AccountNumber;
//	cout << "\nPin Code     : " << Client.PinCode;
//	cout << "\nName         : " << Client.Name;
//	cout << "\nPhone        : " << Client.Phone;
//	cout << "\nAccount Balance: " << Client.AccountBalance;
//	cout << "\n_______________________________________________________";
//
//}
//
//string ReadAccountNumber() {
//
//
//	string AccountNumber;
//
//	cout << "\n Please Enter Account Number? ";
//	cin >> AccountNumber;
//
//	return AccountNumber;
//
//
//
//}
//
//
//bool FindClientByAccountNumber(string AccountNumber, vector <sClient>& vClient, sClient& Client) {
//
//
//	
//	for (sClient& C : vClient) {
//		if (C.AccountNumber == AccountNumber) {
//
//			Client = C;
//
//			return true;
//
//
//		}
//		else {
//			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
//			return false;
//		}
//	
//
//	}
//	return false;
//}
//
//bool MarkClientForDelete(string AccountNumber, vector <sClient> &  vClient) {
//
//	for (sClient& C : vClient) {
//		if (C.AccountNumber == AccountNumber) {
//
//			C.MarkForDelete = true;
//			return true;
//
//		}
//
//
//}
//	return false;
//}
//
//
//
//bool DeleteClientByAccountNumber(string  AccountNumber , vector <sClient> & vClient ) {
//
//	sClient Client;
//	char Answer = 'n';
//
//
//	
//	if (FindClientByAccountNumber(AccountNumber, vClient , Client)) {
//
//		PrintClientCard(Client);
//		cout << "\n\nAre you sure you want delete this client? y/n ? ";
//		cin >> Answer;
//		if (Answer == 'y' || Answer == 'Y') {
//
//
//			MarkClientForDelete(AccountNumber , vClient);
//			SaveDataLineToFileUsingVector(ClientsFileName, vClient );
//
//		vClient = 	LoadClientsDataFromFile(ClientsFileName);
//
//		cout << "\n\nClient Deleted Successfully.";
//
//		return true;
//
//		}
//
//	} else {
//
//		return false;
//	}
//}
//
//
//sClient ChangeClientRecord(string AccountNumber) {
//	sClient Client;
//
//	Client.AccountNumber = AccountNumber;
//
//	cout << "Enter PinCode? ";
//	getline(cin >> ws, Client.PinCode);
//	cout << "Enter Name? ";
//	getline(cin, Client.Name);
//	cout << "Enter Phone? ";
//	getline(cin, Client.Phone);
//	cout << "Enter AccountBalance? ";
//	cin >> Client.AccountBalance;
//
//	return Client;
//
//
//}
//
//bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClient) {
//	sClient Client;
//	char Answer = 'n';
//
//	if (FindClientByAccountNumber(AccountNumber, vClient, Client)) {
//		PrintClientCard(Client);
//		cout << "\n\nAre you sure you want update this client? y/n ? ";
//		cin >> Answer;
//		if (Answer == 'y' || Answer == 'Y') {
//
//
//			for (sClient& C : vClient) {
//
//				if (C.AccountNumber == AccountNumber) {
//
//					C = ChangeClientRecord(AccountNumber);
//					break;
//
//				}
//			
//
//			}
//
//
//
//			SaveDataLineToFileUsingVector(ClientsFileName, vClient);
//
//
//			cout << "\n\nClient Updated Successfully.";
//
//			return true;
//
//		}
//	}
//}
//
//
//void MainMenuText() {
//	cout << "=========================================\n";
//	cout << setw(30) << "Main Menu Screen" << setw(20) << endl;
//	cout << "=========================================\n";
//	cout << "     [1] Show Client List." << endl;
//	cout << "     [2] Add New Client." << endl;
//	cout << "     [3] Delete Client." << endl;
//	cout << "     [4] Update Client Info." << endl;
//	cout << "     [5] Find Client." << endl;
//	cout << "     [6] Exit." << endl;
//	cout << "=========================================\n";
//	cout << "Choose what do you want to do? [1 to 6]? ";
//}
//
//
//void MainMenuScreen(short &  Number) {
//	do {
//		MainMenuText();
//		cin >> Number;
//		if (cin.fail()) {
//			cin.clear();
//			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			MainMenuText();
//			cin >> Number;
//		}
//	} while (Number < 1 || Number > 6 || cin.fail());
//}
//
//void ResetScreen() {
//
//	system("cls");
//
//}
//
//void DeleteClientScreen() {
//	cout << "\n-----------------------------\n";
//	cout << "    Delete Client Screen" ;
//	cout << "\n------------------------------\n";
//
//
//}
//
//void UpdateClientInfoScreen() {
//	cout << "\n-----------------------------\n";
//	cout << "    Update Client Info Screen";
//	cout << "\n------------------------------\n";
//
//
//}
//
//void FindClientScreen() {
//	cout << "\n-----------------------------\n";
//	cout << "    Find Client Screen";
//	cout << "\n------------------------------\n";
//
//
//}
//
//void ExitProgramScreen() {
//	cout << "\n-----------------------------\n";
//	cout << "    Program Ends :-)";
//	cout << "\n------------------------------\n";
//}
//
//void UserChoice(short &);
//
//void GoToMainMenuScreen() {
//	short Number = 0;
//	cout << "\nPress any key to go back to Main Menu...";
//	system("pause>0");
//	system("cls");
//	MainMenuScreen(Number);
//	UserChoice(Number);
//}
//
//void UserChoice(short & Number) {
//	vector <sClient> vClients;
//	vClients = LoadClientsDataFromFile(ClientsFileName);
//	string AccountNumber;
//	sClient Client;
//
//	switch (Number) {
//
//	case enUserChoice::Show:
//		ResetScreen();
//		 PrintAllClientsData(vClients);
//		 GoToMainMenuScreen();
//		 break;
//
//	case enUserChoice::Add:
//		ResetScreen();
//		AddClients();
//
//		break;
//
//	case enUserChoice::Delete:
//		DeleteClientScreen();
//		AccountNumber = ReadAccountNumber();
//		DeleteClientByAccountNumber(AccountNumber , vClients);
//	
//
//		break;
//
//	case enUserChoice::Update:
//		UpdateClientInfoScreen();
//		AccountNumber = ReadAccountNumber();
//		UpdateClientByAccountNumber(AccountNumber , vClients);
//
//		break;
//
//	case enUserChoice::Find:
//		ResetScreen();
//		FindClientScreen();
//		AccountNumber = ReadAccountNumber();
//
//	if (FindClientByAccountNumber(AccountNumber, vClients, Client) ) {
//     	PrintClientCard(Client);
//
//	}
//
//	GoToMainMenuScreen();
//
//
//		break;
//
//	case enUserChoice::Exit:
//		ResetScreen();
//		ExitProgramScreen();
//		break;
//
//	}
//}
//
//
//void StartChoice() {
//	short Number = 0;
//	MainMenuScreen(Number);
//	UserChoice(Number);
//
//
//}
//
//
//
//
//int main()
//{
//	StartChoice();
//
//	return 0;
//}


/***********************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

void ShowMainMenu();
void ShowTransactionsMenu();
struct sClient {
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
	bool MarkForDelete = false;
};


enum enMainMenuOptions {
	eListClients = 1,
	eAddNewClient = 2,
	eDeleteClient = 3,
	eUpdateClient = 4,
	eFindClient = 5,
	eTransactions = 6,
	eExit = 7
};

enum enTransactionsMenuOption {

	eDeposit = 1,
	eWithdraw = 2,
	eTotalBalances = 3,
	eMainMenue = 4


};

vector<string> SplitString(string S1, string Delim) {
	vector<string> vString;
	short pos = 0;
	string sWord;
	// define a string variable  
	// use find() function to get the position of the delimiters  
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		// store the word   if (sWord != "")       
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	} if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.  
	} return vString;
}



sClient ConvertLinetoRecord(string Line, string Seperator = "#//#") {
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//cast string to double;

	return Client;
}


string ConvertRecordToLine(sClient Client, string Seperator = "#//#") {


	string stClientRecord = "";


	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);


	return stClientRecord;


}


void PrintClientCard(sClient Client) {
	cout << "\n_______________________________________________________";
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code     : " << Client.PinCode;
	cout << "\nName         : " << Client.Name;
	cout << "\nPhone        : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n_______________________________________________________";

}


vector <sClient> LoadClientsDataFromFile(string FileName) {

	fstream MyFile;
	vector <sClient> vClients;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {

		string Line;
		sClient Client;

		while (getline(MyFile, Line)) {

			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);

		}
	}


	MyFile.close();

	return vClients;

}

bool ClientExistsByAccountNumber(string AccountNumber , string FileName) {

	fstream MyFile;

	MyFile.open(FileName , ios::in);

	if (MyFile.is_open()) {

		string Line;
		sClient Client;

		while (getline(MyFile, Line)) {

			Client = ConvertLinetoRecord(Line);

			if (Client.AccountNumber == AccountNumber) {

				MyFile.close();
				return true;
			}
		}

		MyFile.close();

	}
	return false;
}

sClient ReadNewClient() {
	sClient Client;


	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);


	while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName)) {

		cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? "; 
		getline(cin >> ws, Client.AccountNumber);

	}



	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}


short ReadMainMenuOption() {

	short Choice = 0;
	cout << "Choose what do you want to do? [1 to 7]? ";
	cin >> Choice;
	return Choice;

}

void ShowEndScreen() {
	cout << "\n-----------------------------------\n"; 
	cout << "\tProgram Ends :-)";  
	cout << "\n-----------------------------------\n";
}

void GoBackToMainMenu() {

	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenu();

}

void PrintClientRecordLine(sClient Client) {

	cout << "| " << setw(15) << left << Client.AccountNumber; 
	
	cout << "| " << setw(10) << left << Client.PinCode;  
	cout << "| " << setw(40) << left << Client.Name; 
	cout << "| " << setw(12) << left << Client.Phone;   
	cout << "| " << setw(12) << left << Client.AccountBalance;


}



void SaveDataLineToFile(string FileName, string stLine) {

	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open()) {

		MyFile << stLine << endl;

		MyFile.close();
	}

}
vector <sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients) {

	fstream MyFile;   
	MyFile.open(FileName, ios::out);//overwrite
	
	
	string DataLine; 
	if (MyFile.is_open())   
	{ for (sClient C : vClients)      
	{ if (C.MarkForDelete == false)     
	{ //we only write records that are not marked for delete.  
		
		DataLine = ConvertRecordToLine(C);            
		MyFile << DataLine << endl;           
	}   
	} 
	MyFile.close();   
	} return vClients;

} 



bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client) {
	for (sClient C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		} 
	
	}
	
	return false; 

}

bool MarkClientForDelete(string AccountNumber, vector <sClient> &  vClient) {

	for (sClient& C : vClient) {
		if (C.AccountNumber == AccountNumber) {

			C.MarkForDelete = true;
			return true;

		}


}
	return false;
}


bool DeleteClientByAccountNumber(string  AccountNumber, vector <sClient>& vClient) {

	sClient Client;
	char Answer = 'n';



	if (FindClientByAccountNumber(AccountNumber, vClient, Client)) {

		PrintClientCard(Client);
		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {


			MarkClientForDelete(AccountNumber, vClient);
			SaveCleintsDataToFile(ClientsFileName, vClient);

			vClient = LoadClientsDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";

			return true;

		}

	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}


sClient ChangeClientRecord(string AccountNumber) {
	sClient Client;  
	Client.AccountNumber = AccountNumber;    
	cout << "\n\nEnter PinCode? ";    
	getline(cin >> ws, Client.PinCode);   
	cout << "Enter Name? ";  
	getline(cin, Client.Name); 
	cout << "Enter Phone? ";   
	getline(cin, Client.Phone); 
	cout << "Enter AccountBalance? ";    
	cin >> Client.AccountBalance;
	return Client;
}



bool UpdateClientByAccountNumber(string  AccountNumber, vector <sClient>& vClient) {

	sClient Client;
	char Answer = 'n';



	if (FindClientByAccountNumber(AccountNumber, vClient, Client)) {

		PrintClientCard(Client);
		cout << "\n\nAre you sure you want update this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {


			for (sClient& C : vClient) {

				if (C.AccountNumber == AccountNumber) {

					C = ChangeClientRecord(AccountNumber);
					break;

				}
			}
			SaveCleintsDataToFile(ClientsFileName , vClient);

			cout << "\n\nClient Updated Successfully.";

			return true;

		}

	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}




string ReadClientAccountNumber() {

	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;


}

void AddNewClient() {
	sClient Client;
	Client = ReadNewClient();
    SaveDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}


void AddNewClients() {
	char AddMore = 'Y';
	do { 
		system("cls");
		cout <<"Adding New Client:\n\n";  
		AddNewClient();    
		cout <<"\nClient Added Successfully, do you want to add more clients? Y/N? "; 
		cin >> AddMore;    
	} while (toupper(AddMore) == 'Y'); 

}



void ShowAllClientsScreen() {

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)."; 
	cout << "\n_______________________________________________________";  
	cout << "_________________________________________\n" << endl;   
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code"; 
	cout << "| " << left << setw(40) << "Client Name";   
	cout << "| " << left << setw(12) << "Phone";  
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";  
	cout << "_________________________________________\n" << endl;


	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else
		for (sClient& Client : vClients) {

			PrintClientRecordLine(Client);
			cout << endl;

	   }

}

void ShowAddNewClientsScreen() {
	cout << "\n-----------------------------------\n"; 
	cout << "\tAdd New Clients Screen"; 
	cout << "\n-----------------------------------\n";

	AddNewClients();

}



void ShowDeleteClientScreen() {

	cout << "\n-----------------------------------\n";  
	cout << "\tDelete Client Screen";   
	cout << "\n-----------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	string AccountNumber = ReadClientAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClients);


}

void ShowUpdateClientScreen() {
	cout << "\n-----------------------------------\n";
	cout << "\tUpdate Client Info Screen";
	cout << "\n-----------------------------------\n";


	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();   
	UpdateClientByAccountNumber(AccountNumber, vClients);

}

void ShowFindClientScreen() {

	cout << "\n-----------------------------------\n";   
	cout << "\tFind Client Screen"; 
	cout << "\n-----------------------------------\n";


	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	sClient Client; string AccountNumber = ReadClientAccountNumber();
	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
		PrintClientCard(Client);
	}
	else {
		cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
	}


}

void GoBackToTransactionsMenu() {

	cout << "\n\nPress any key to go back to Transactions Menue...";
	system("pause>0");
	ShowTransactionsMenu();

}



bool DepositBalaneToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients) {
	char Answer = 'n';

	cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y') {

		for (sClient& C : vClients) {

			if (C.AccountNumber == AccountNumber) {

				C.AccountBalance += Amount;
				SaveCleintsDataToFile(ClientsFileName, vClients);
				cout << "done successfully new balance is " << C.AccountBalance;

				return true;

			}

		}
	}
	return false;
}

void ShowDepositScreen() {
	cout << "\n-----------------------------------\n";
	cout << "\tDeposit Screen";
	cout << "\n-----------------------------------\n";
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();
	while (!FindClientByAccountNumber(AccountNumber, vClients, Client)) {
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";

		AccountNumber = ReadClientAccountNumber();
		} 
		PrintClientCard(Client);
		double Amount = 0;
		cout << "\n Please Enter Deposit amount? ";
		cin >> Amount;

		DepositBalaneToClientByAccountNumber(AccountNumber , Amount , vClients);

	}



void ShowWithdrawScreen() {

	cout << "\n-----------------------------------\n";
	cout << "\tWithdraw Screen";
	cout << "\n-----------------------------------\n";


	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();
	while (!FindClientByAccountNumber(AccountNumber, vClients, Client)) {
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";

		AccountNumber = ReadClientAccountNumber();
	}

		PrintClientCard(Client);
		cout << "\n Please Enter Withdraw amount? ";


		double Amount = 0;
		cin >> Amount;

		if (Amount > Client.AccountBalance) {
			cout << "Amount Exceeds the balance, you can withdraw up to " << Client.AccountBalance;
			cout << "\n Please enter another amount ";
			cin >> Amount;

		}

		DepositBalaneToClientByAccountNumber(AccountNumber,Amount * -1 , vClients);
}

void PrintClientTransactions(sClient Client) {

	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowTotalBalances() {

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	double TotalBalances = 0;

	if (vClients.size() == 0) {
		cout << "\t\t\t\tNo Clients Available In the System!";
	}
	else {

		for (sClient& Client : vClients) {

			PrintClientTransactions(Client);
			cout << endl;
			TotalBalances += Client.AccountBalance;

		}

		cout << "\n\t\t\t\t\t Client Balances = " << TotalBalances;
	}

}

void ShowTotalBalancesScreen() {

	 ShowTotalBalances();

}



short ReadTransactionsMenuOption() {
	short Choice = 0;
	cout << "Choose what do you want to do? [1 to 4]? ";
	cin >> Choice;
	return Choice;

}

void PerformTransactionsMenuOptions(enTransactionsMenuOption TransactionsMenuOption) {

	switch (TransactionsMenuOption)
	{
	case enTransactionsMenuOption::eDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionsMenu();
		break;
	case enTransactionsMenuOption::eWithdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionsMenu();

		break;
	case enTransactionsMenuOption::eTotalBalances:
		system("cls");
		ShowTotalBalancesScreen();
		GoBackToTransactionsMenu();

		break;
	case enTransactionsMenuOption::eMainMenue:
		ShowMainMenu();

		break;
	}

}





void ShowTransactionsMenu() {

	system("cls");
	cout << "===========================================\n";
	cout << "\t\tTransactions Menu Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances.\n";
	cout << "\t[4] Main Menue.\n";
	cout << "===========================================\n";

	PerformTransactionsMenuOptions( (enTransactionsMenuOption)	ReadTransactionsMenuOption() );

}



void PerformMainMenuOptions(enMainMenuOptions MainMenuOption) {

	switch (MainMenuOption)
	{
	case enMainMenuOptions::eListClients:
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenu();
		break;
	case enMainMenuOptions::eAddNewClient:
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenu();

		break;
	case enMainMenuOptions::eDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenu();

		break;
	case enMainMenuOptions::eUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenu();

		break;
	case enMainMenuOptions::eFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenu();

		break;


	case enMainMenuOptions::eTransactions: 
		system("cls");
		ShowTransactionsMenu();

		break;


	case enMainMenuOptions::eExit:
		system("cls");
		ShowEndScreen();
		break;
	
	}

}


void ShowMainMenu() {

	system("cls");
	cout << "===========================================\n";   
	cout << "\t\tMain Menue Screen\n";   
	cout << "===========================================\n";   
	cout << "\t[1] Show Client List.\n";  
	cout << "\t[2] Add New Client.\n";    
	cout << "\t[3] Delete Client.\n";   
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Exit.\n";    
	cout << "===========================================\n";
	PerformMainMenuOptions((enMainMenuOptions) ReadMainMenuOption());
}


int main() {

	ShowMainMenu();

	system("pause>0");
}

/*
deposit doesn't save 
withdraw doesn't save
*/
