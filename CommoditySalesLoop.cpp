// Sources of logic assistance: 
// Gaddis, T. (2018). Starting out with C++: From control structures through objects. Pearson. 
// https://learn.microsoft.com/en-us/cpp/standard-library/string

#include <iostream> // To use cin/cout
#include <iomanip> // To access setw for output width
#include <string> // String library to access to_string
using namespace std;

// Constant Variable Initialization
const string TITLE = "Commodity Sales Loop Program";
const string AUTHOR_LINE = "By Forrest Moulin";
const int FIRST_COL_WIDTH = 35;

int main()
{
	cout << TITLE << endl
		<< AUTHOR_LINE << endl << endl;

	// Dynamic Variable Initialization
	int numTransactions = 1, unitsEntered = 0, transactionColumnLength = 0;

	double avgUnitsPerOrder, smallestTransaction,
		largestTransaction, totalRevenue = 0.00, avgRevenue, priceEntered,
		transactionTotal = 0.00, soldUnits = 0.00;

	// Make any setprecision values fixed
	cout << fixed;

	cout << "For each transaction, please enter the number of units sold,"
		<< endl << "followed by a space and the price per unit."
		<< endl << "Do not include a dollar sign. Correct example: 50 12.50"
		<< endl << "Enter -99 0 to stop the program." << endl << endl;

	cout << "Transaction # " << numTransactions << ": ";

	cin >> unitsEntered >> priceEntered;

	soldUnits = unitsEntered;
	transactionTotal = unitsEntered * priceEntered;
	totalRevenue += transactionTotal;

	// On first iteration, transaction is both smallest & largest
	smallestTransaction = transactionTotal;
	largestTransaction = transactionTotal;

	numTransactions++;

	// Loop while either variable does not match the required value
	while (unitsEntered != -99 || priceEntered != 0.00)
	{
		cout << "Transaction # " << numTransactions << ": ";
		cin >> unitsEntered >> priceEntered;

		// Validate user input
		if (unitsEntered <= 0 && unitsEntered != -99)
		{
			cout << "Units entered should be greater than 0."
				<< endl << "Please try again." << endl << endl;
			// Restart while loop
			continue;
		}

		if (unitsEntered == -99 && priceEntered == 0.00)
		{	// Exit while loop to finish the program
			break;
		}

		// Calculate transaction total with user input
		soldUnits += unitsEntered;
		transactionTotal = unitsEntered * priceEntered;
		totalRevenue += transactionTotal;

		// Algorithm to find smallest transaction
		if (transactionTotal < smallestTransaction)
		{
			// Set new smallest value
			smallestTransaction = transactionTotal;
		}
		// Algorithm to find largest transaction
		else if (transactionTotal > largestTransaction)
		{
			// Set new largest value
			largestTransaction = transactionTotal;
		}
		// Keep track of # of transactions
		numTransactions++;
	}
	// Exclude exit transaction (-99 0)
	numTransactions--;

	// Final report calcuations
	avgRevenue = totalRevenue / numTransactions;
	avgUnitsPerOrder = soldUnits / numTransactions;

	transactionColumnLength = to_string(largestTransaction).length() - 3;

	// Final transaction report output (2 columns)
	cout << endl << "Commodity Sales Transaction Report Processed Successfully!"
		<< endl << left << setw(FIRST_COL_WIDTH)
		<< "Number of transactions processed:"
		<< right << setw(transactionColumnLength + 1)
		<< numTransactions << endl

		// Make sold units appear as int
		<< left << setw(FIRST_COL_WIDTH) << setprecision(0)
		<< "Number of units sold:" << right
		<< setw(transactionColumnLength + 1) << soldUnits << endl

		// Reset double precision to 2
		<< left << setw(FIRST_COL_WIDTH) << setprecision(2)
		<< "Average units per transaction:" << right
		<< setw(transactionColumnLength + 1) << avgUnitsPerOrder << endl

		<< left << setw(FIRST_COL_WIDTH) << "Smallest transaction amount:"
		<< "$" << right << setw(transactionColumnLength)
		<< smallestTransaction << endl

		<< left << setw(FIRST_COL_WIDTH) << "Largest transaction amount:"
		<< "$" << right << setw(transactionColumnLength)
		<< largestTransaction << endl

		<< left << setw(FIRST_COL_WIDTH) << "Total revenue:" << "$"
		<< right << setw(transactionColumnLength) << totalRevenue << endl

		<< left << setw(FIRST_COL_WIDTH) << "Average revenue per transaction:"
		<< "$" << right << setw(transactionColumnLength) << avgRevenue << endl;
}
/*
* CONSOLE OUTPUT
* Commodity Sales Loop Program
* By Forrest Moulin
*
* For each transaction, please enter the number of units sold,
* followed by a space and the price per unit.
* Do not include a dollar sign. Correct example: 50 12.50
* Enter -99 0 to stop the program.
*
* Transaction # 1: 50 10.00
* Transaction # 2: 40 12.50
* Transaction # 3: 30 15.00
* Transaction # 4: 20 15.00
* Transaction # 5: -99 0
*
* Commodity Sales Transaction Report Processed Successfully!
* Number of transactions processed:         4
* Number of units sold:                   140
* Average units per transaction:        35.00
* Smallest transaction amount:       $ 300.00
* Largest transaction amount:        $ 500.00
* Total revenue:                     $1750.00
* Average revenue per transaction:   $ 437.50
*/
