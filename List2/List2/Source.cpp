#include <iostream>
#include "List2.h"
using namespace std;
int main()
{
	List2<int> tL;
	tL.push_back(1);
	tL.push_back(2);
	tL.push_back(3);
	tL.push_back(4);
	/*tL.push_front(0);
	tL.push_front(-1);
	tL.push_back(5);
	tL.pop_front();
	tL.pop_back();*/
	tL.insert(99, 1);
	try
	{
		cout << tL.at(5) << endl;
	}
	catch (const std::string& ex)
	{
		cout << ex << endl;
	}
	
}