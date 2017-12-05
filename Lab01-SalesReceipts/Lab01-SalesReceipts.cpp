// Lab01-SalesReceipts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

struct sale_data
{
	char transCode = 'N';
	int quantity = 0;
	double itemPrice = 0.0;
	string last, first;
};

int main()
{
	vector<sale_data> sale;

	ifstream inputFile;

	inputFile.open("SalesReceipts.txt");

	if (!inputFile)
	{
		cout << "Error: unsuccessful at opening file...check file name and location." << endl;

		system("pause");
		return -1;
	}

	char transCode = 'N';
	int quantity = 0;
	double itemPrice = 0.0;
	string last, first;

	int iter = 0;

	// Prime read:
	inputFile >> last >> first >> transCode >> itemPrice >> quantity;

	while (!inputFile.eof())
	{
		sale_data tSale;

		tSale.last = last;
		tSale.first = first;
		tSale.transCode = transCode;
		tSale.itemPrice = itemPrice;
		tSale.quantity = quantity;

		sale.insert(sale.begin() + iter++, tSale);

		inputFile >> last >> first >> transCode >> itemPrice >> quantity;
	}

	// Display data:

	int salesTotal = sale.size();
	double receiptsTotal = 0.0;
	char dolSign = '$';

	for (int n = 0; n < salesTotal; n++)
	{
		string name = sale[n].last + ", " + sale[n].first;
		receiptsTotal += (sale[n].itemPrice * sale[n].quantity);
		cout << sale[n].transCode << setw(8) << sale[n].quantity << setw(3) << "@" << setw(3) << dolSign << setw(10) << fixed << setprecision(2) << sale[n].itemPrice << setw(3) << dolSign << setw(12) << fixed << setprecision (2) << sale[n].itemPrice * sale[n].quantity << setw(24) << name << endl;
		dolSign = ' ';
	}

	cout << endl << setw(28) << '$' << setw(12) << fixed << setprecision(2) << receiptsTotal << endl << endl;
	cout << setw(9) << salesTotal << "  " << "records processed" << endl << endl;

	system("pause");
    return 0;
}



