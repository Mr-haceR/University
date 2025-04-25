#include <iostream>
using namespace std;

main()
{
	int current_population, number_of_births_per_month, final_population;
	cout << "Enter current population: ";
	cin >> current_population;
	cout << "Enter number of births per month: ";
	cin >> number_of_births_per_month;
	final_population = current_population + (30 * 12 * number_of_births_per_month);
	
}
