#include <iostream>
using namespace std;

main(){
	int MB, Bit;
	cout<<"Enter Megabytes.."<<endl;
	cin>>MB;
	Bit=MB * 1024 * 1024 * 8;
	cout<<MB<<" Megabytes in Bits are "<<Bit;
}

