#include <iostream>

using namespace std;

main() {
	string country;
	float ticket_price, price_after_discount;
	cout << "Enter the country's name: ";
	cin >> country;
	cout << "Enter ticket price in dollars: ";
	cin >> ticket_price;
	if (country == "Ireland") {
		price_after_discount = ticket_price - ticket_price * 0.1;
	}
	else {
		price_after_discount = ticket_price - ticket_price * 0.05;
	}
	cout << "Price after discount is " << price_after_discount;
}