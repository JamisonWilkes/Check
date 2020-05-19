#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string line;
	cout << "Please enter the name of your file" << endl;
	cin >> line;
	ifstream input(line);

	if (!input.good())
	{
		cerr << "Unable to open rolodex.txt";
		exit(1);
	}

	//while (getline(input, line))
	//	cout << line << endl;

	double balance = 0;
	cout.setf(ios::fixed);    // fixed point output, no scientific notation
	cout.precision(2);

	while (!input.eof())
	{
		string depositOrCharge;
		getline(input, depositOrCharge, ':');
		cout << left << setw(20) << depositOrCharge;

		string date;
		getline(input, date, ':');
		cout << setw(20) << date;

		string placeCharged;
		getline(input, placeCharged, ':');
		cout << setw(35) << placeCharged;

		string amount;
		getline(input, amount);
		cout  << setw(5) << "$" << right << setw(10) <<  stod(amount) << endl;

		if (depositOrCharge == "deposit")
				balance += stod(amount);
		else balance -= stod(amount);

	
	}
	cout << endl;
	cout << right << setw(85) << "Balance:$ " << balance;
	return 0;
}
