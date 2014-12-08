//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
////************************************************************************************************************
//int factorial(int n)
//{
//  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
//}
// to samo tylko schematem Hornera
////************************************************************************************************************
//double ln_iter(double x, double n)
//{
//	double loopResult = 0;
//	double tempResult = 0;
//	for(int i = 1; i <= n; i++)
//	{
//		tempResult = pow(x, i) / i;
//		
//		if(i%2 == 0) tempResult *= (-1);
//
//		loopResult += tempResult;
//		tempResult = 0;
//	}
//
//	return loopResult;
//
//}
////************************************************************************************************************
//double ln_rec(double x, double n)
//{
//	static int recursive_step;
//	recursive_step++;
//
//	static double loopResult = 0;
//	double tempResult = 0;
//
//	tempResult = pow(x, recursive_step) / recursive_step;
//
//	if(recursive_step % 2 == 0) tempResult *= (-1);
//
//	loopResult += tempResult;
//
//	tempResult = 0;
//
//	if(n)
//	{
//		loopResult = ln_rec(x, n-1);
//	}
//
//	return loopResult;
//
//}
////************************************************************************************************************
//void create_file(double x, double n)
//{
//	ifstream myfile ("zmienne.txt");
//	if (!myfile.is_open())
//	{
//		ofstream myfile;
//		myfile.open ("zmienne.txt");
//		myfile << x << " " << n;
//		myfile.close();
//	}
//
//}
////************************************************************************************************************
//double read_x()
//{
//	double a;
//
//	ifstream myfile ("zmienne.txt");
//	if (myfile.is_open())
//	{
//		myfile >> a;
//		myfile.close();
//	}
//	else cout << "Unable to open file";
//
//	return a;
//
//}
////************************************************************************************************************
//double read_n()
//{
//	double b;
//
//	ifstream myfile ("zmienne.txt");
//	if (myfile.is_open())
//	{
//		for(int i = 0; i < 2; i++) myfile >> b;
//		myfile.close();
//	}
//	else cout << "Unable to open file";
//
//	return b;
//
//}
////************************************************************************************************************
//double horner_iter(double x, int n)
//{
//	double w=0;
//	for(int i=n; i>0; i--){
//		w=((1/static_cast<double>(i))-w)*x;
//	}
//	return w;
//}
////************************************************************************************************************
//double horner_rec(double x, double n)
//{
//	static int recursive_step;
//	recursive_step++;
//	double result = 0;
//	if(n){
//		result=((1/static_cast<double>(recursive_step))-horner_rec(x, n-1))*x;
//	}
//	return result;
//}