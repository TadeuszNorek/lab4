#include <iostream>
#include <string>

using namespace std;

int findK(int n)
{
	int result, k=1;
	bool _isCorrect=false;
	while (k > 0)
	{ 
		result=n*k;
		_isCorrect=true;
		while (result > 0)
		{
			if (result % 10 > 1) _isCorrect=false;
			result /= 10;
		}
		if (_isCorrect) break; 
		k++;
	}
	return k;
};

string towords(int n)
{
string ones[10]={"","jeden ","dwa ","trzy ","cztery ","piec ","szesc ","siedem ","osiem ","dziewiec "};
string teens[11]={"","dziesiec ","jedenascie ","dwanascie ","trzynascie ","czternascie ","pietnascie ","szesnascie ","siedemnascie ",
                   "osiemnascie ","dziewietnascie "};
string tens[10]={"","dziesiec ","dwadziescia ","trzydziesci ","czterdziesci ","piecdziesiat ","szescdziesiat ","siedemndziesiat ",
                      "osiemdziesiat ","dziewiecdziesiat "};
string hunderts[10]={"","sto ","dwiescie ","trzysta ","czterysta ","piecset ","szescset ","siedemset ","osiemset ","dziewiecset "};
string thousands[4]={"","tysiac ","tysiace ","tysiecy "};

	if(n == 0)
	return "zero";

	if(n == 1000000)
	return "milion";

int digits[6];
string bywords = "";
int num=n;

for(int i = 0; i < 6; i++)
{
	digits[i] = n%10;
	n /=10;
};

bywords+=hunderts[digits[5]]; //setki tys

if (digits[4]==1) bywords+=teens[digits[3]+1];  //dziesiatki tys
	else 
	{
		bywords+=tens[digits[4]];
		bywords+=ones[digits[3]];
	}
if (num>999) 		//tysiace
{
	if(digits[4]==0 && digits[5]==0 && digits[3]==1) bywords+=thousands[1];
	else if(digits[4]=!1 && (digits[3]==2 || digits[3]==3 || digits[3]==4)) bywords+=thousands[2];
		 else bywords+=thousands[3];

};

bywords+=hunderts[digits[2]];  //setki

if (digits[1]==1) bywords+=teens[digits[1]];  //dziesiatki 
	else
	{
		bywords+=tens[digits[1]];
		bywords+=ones[digits[0]];		
	};
return bywords;
};




 int main(int argc, char *argv[])
 {	
 	int n = atoi(argv[1]);
 	int k = findK(n);
 	cout << "Wprowadzona liczba: " << n << " - " <<towords(n) << endl;
 	cout << "Liczba k: " << k << " - " << towords(k) << endl;
 	cout << "Iloczyn k * n : " << k * n << " - " << towords(k*n) << endl;

}
