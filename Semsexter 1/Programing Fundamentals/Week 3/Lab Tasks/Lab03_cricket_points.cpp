#include <iostream>
using namespace std;

main()
{
	int wins, draws, losses, points;
	cout << "Enter number of wins: ";
	cin >> wins;	
	cout << "Enter number of draws: ";
	cin >> draws;
	cout << "Enter number of losses: ";
	cin >> losses;
	points = (wins * 3) + (draws * 1) + (losses * 0);
	cout << "The team got " << points << "points";
}
