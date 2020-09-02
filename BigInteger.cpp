//============================================================================
// Name        : Bayat, Mohammad
// Author      : CS211 33B Homework1
//============================================================================

#include <iostream>
#include <string>

using namespace std;



int a_length=0;
int b_length=0;


// ***** Important:
// b should always be larger than a



string AddInteger(string a,string b);
int main()
{
	string input1="";
	string input2="";
	string final_result;
	do
	{
		cout << "Welcome, Please make sure your First Number is Smaller than the Second Number(or equal) " << endl;
		cout << "Conditions for the function: First Number <= Second Number" << endl;
		cout << "Enter a number for a: ";
		cin >> input1;
		cout << "Enter a number for b: ";
		cin >> input2;


		cout << input1 << "+" << input2 << "=" << AddInteger( input1,input2) << endl;
		cout << "press q if you are done, or press any other key two continue: ";
		cin >> input1;

	}while(input1!="q");


	return 0;
}


int sum=0;
int single1=0;        // hold individual digit after conversion from array1 --> First_array
int single2=0;		  // hold individual digit after conversion from array2 --> Second_array
string AddInteger(string a,string b)
{

	a_length=a.length();
	b_length=b.length();
	string str_result=" ";					// hold reversed numericalalpha from
	string final_result="";
	int temp=0;
	int carry=0;
	int sum=0;

	int First_array [a_length]={0};
	int Second_array[b_length]={0};

	char array1[a_length]={0};
	char array2[b_length]={0};

// Step 1
// conversion char [] array1 -- int [] First_array

	for(int i=a_length-1;i>=0;i--)
	{
		array1[i]=a[i];
		single1=a[i]-'0';
		First_array[i]=single1;

	}


// Step 2
// conversion char [] array2 -- int [] Second_array

	for(int i=b_length-1;i>=0;i--)
	{
		array2[i]=b[i];
		single2=b[i]-'0';
		Second_array[i]=single2;

	}

//Step	3
// Get individual digit from both int arrays add them up and convert it back the char
// the temp value hold the numerical value and gets converted into char and stored at str_result

	int j=b_length-1;					// index the loop for Second_array
	for(int i=a_length-1;i>=0;i--)
	{

		sum=First_array[i]+Second_array[j]+ carry;
		temp=sum % 10;
		str_result+=temp+'0';
		carry=sum / 10;
		j--;
	}
// Step 4
// Keep adding the rest of the larger number
	while(j>=0)
	{
		sum=Second_array[j]+ carry;
		temp=sum % 10;
		str_result+=temp+'0';
		carry=sum / 10;
		j--;
	}

// Step 5
// Reversing process
int r=str_result.length()-1;		// index to loop through string reversing ; str_result is reversed
	while(r>=0)
	{
		// final_result is the final
		final_result+=str_result[r];
		r--;
	}


	return final_result;
}
