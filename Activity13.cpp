/// Nick Luca, Diljot Singh, Anexa Thammavangsa
/// Activity 13: Overloaded Function

#include <iostream>

using namespace std;

/// addingTotalCharges has two versions which is what the prof wanted overloaded functions

double addingTotalCharges(int numOfDays, double dailyHospitalRate, double hospitalMedCharge, double hospitalServices);
double addingTotalCharges(double hospitalServices, double hospitalMedCharge);
void showTotalCharges(double totalCharges);
void inpatientInput(int &numOfDays, double &dailyHospitalRate, double &hospitalMedCharge, double &hospitalServices);
void outpatientInput(double &hospitalServices, double &hospitalMedCharge);

int main()
{
	char patientAdmitted;
	int numOfDays;
	double dailyHospitalRate, hospitalMedCharge, hospitalServices;

	cout << "Were you admitted as an inpatient (I) or an outpatient (O)?: ";  /// Asks user if they were inpatient or outpatient
	cin >> patientAdmitted;  /// User input I or O

	while (patientAdmitted != 'I' && patientAdmitted != 'i' && patientAdmitted != 'O' && patientAdmitted != 'o')
	{
		cout << "Invalid input!\n";  /// If anything other than I or O is input it asks the user to enter again
		cout << "Please enter either I for inpatient or O for outpatient: ";
		cin >> patientAdmitted; /// Asks user to input again if I or O isn't entered
	}

	if (patientAdmitted == 'I' || patientAdmitted == 'i')  /// If user is inpatient
	{
		inpatientInput(numOfDays, dailyHospitalRate, hospitalMedCharge, hospitalServices);
		double totalCharges = addingTotalCharges(numOfDays, dailyHospitalRate, hospitalMedCharge, hospitalServices); /// Calculating the total of everything
		showTotalCharges(totalCharges); /// Total charge for inpatient
	}
	else if (patientAdmitted == 'O' || patientAdmitted == 'o')  /// If user is outpatient
	{
		outpatientInput(hospitalServices, hospitalMedCharge);
		double totalCharges = addingTotalCharges(hospitalServices, hospitalMedCharge); /// Sum
		showTotalCharges(totalCharges); /// Total charges for outpatient 
	}

	return 0;
}

double addingTotalCharges(int numOfDays, double dailyHospitalRate, double hospitalMedCharge, double hospitalServices)
{
	return (numOfDays * dailyHospitalRate) + hospitalMedCharge + hospitalServices; /// MATH!
}

double addingTotalCharges(double hospitalServices, double hospitalMedCharge)
{
	return hospitalServices + hospitalMedCharge; /// MORE MATH!
}

void showTotalCharges(double totalCharges)
{
	cout << "Total Charges: $" << totalCharges << endl; /// Shows total charges at the end 
}

void inpatientInput(int &numOfDays, double &dailyHospitalRate, double &hospitalMedCharge, double &hospitalServices)
{
	cout << "Enter the number of days spent in the hospital: ";
	cin >> numOfDays;

	cout << "Enter the daily rate?: ";
	cin >> dailyHospitalRate;

	cout << "Enter the hospital medication charges: ";
	cin >> hospitalMedCharge;

	cout << "Charges for hospital services (lab tests, etc.): ";
	cin >> hospitalServices;
}

void outpatientInput(double &hospitalServices, double &hospitalMedCharge)
{
	cout << "Charges for hospital services (lab tests, etc.): ";
	cin >> hospitalServices;

	cout << "Enter the hospital medication charges: ";
	cin >> hospitalMedCharge;
}
