#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

void enter_packages(double* weights, int size){
	for(int i = 0; i < size; i++){
		cout << "Enter weight for package " << i + 1 << ": ";
		cin >> weights[i];

		while(cin.fail() || weights[i] < 0){
			cout << "Please enter a valid weight: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> weights[i];

		}
	}
}

void display_packages(const double* weights, int size){
	cout << "\nPACKAGES REPORT\n"
	     << "---------------\n";

	for (int i = 0; i < size; i++){
		cout << "Package " << i + 1 << ": " << weights[i] << " lbs\n";
	}
}

double calculate_total(const double* weights, int size){
	double total = 0.0;
	for (int i = 0; i < size; i++){
		total += weights[i];
	}
	return total;
}

double find_heaviest(const double* weights, int size){
	int highestIndex = 0;

	for(int i = 1; i < size; i++){
		if (weights[i] > weights[highestIndex]){
			highestIndex = i;
		}
	}
	return highestIndex;
}

int main(){
	cout << "PACKAGE WEIGHT TRACKER\n"
	     << "----------------------\n";

	int numPackages;

	cout << "How many packages?: ";
	cin >> numPackages;

	while(cin.fail() || numPackages <= 0){
        	cout << "Please enter a valid number greater than 0: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> numPackages;
        }

        double* weights = new double[numPackages]{};

        enter_packages(weights, numPackages);
        display_packages(weights, numPackages);
        double total = calculate_total(weights, numPackages);
        double avg = static_cast<double>(total) / numPackages;
        double heaviest = find_heaviest(weights, numPackages);

        cout << "\nPACKAGE SUMMARY\n"
             << "---------------\n";

	cout << "Total Weight: " << total << " lbs\n";
	cout << fixed << setprecision(2) << "Average Weight: " << avg << " lbs\n";
	cout << "Heaviest Package: Package " << weights[(int)heaviest] << " lbs\n";

	delete[] weights;
	weights = nullptr;

	return 0;
}












