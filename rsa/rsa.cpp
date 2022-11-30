#include <iostream>
#include <string>
#include "BigInt.hpp"
#include <vector>

typedef BigInt INT;

using namespace std;

INT StrtoInt(string text) {
	INT result; 
	result = 0;

	for (int i = 0; i < text.size(); i++) {
		result = result * pow(2, sizeof(text[i]) * 8) + text[i];
	}

	return result;
}

string InttoStr(INT mess) {
    string result;
    result = "";

    return result;
}

INT Gsd(INT a, INT b) {
	return b == 0 ? a : Gsd(b, a % b);
}

INT SimpleE(INT eiler) {
    INT res = 0; 
    //int k = rand() % (10 - 2) + 2;
    int k = 2;
    int c = 0;
    for (int i = 2; i < eiler; i++) {
        if ((Gsd(eiler, i) == 1) && (c == k))
        {
            res = i;
            return res;
            break;
        }
        else  if (Gsd(i, eiler) == 1)
            c++;
    }

    return res;
}

INT GetD(INT e, INT eiler) {
    INT d = 1;
    while ((d * e) % eiler != 1) d++;

    return d;
}

BigInt getEasy(BigInt of) {
    vector<BigInt> easys = vector<BigInt>();

    for (BigInt i = 2; i < of; i++) {
        if (Gsd(of, i) == 1) {
            easys.push_back(i);
        }
    }

    int index = rand() % easys.size();
    return easys[index];
}

INT pow(INT x, INT n, INT y) {
    INT result = x % n;
    for (INT i = 1; i < y; i++) {
        result = (result * x) % n;
    }

    return result;
}

void RSA(INT p, INT q, INT mess) {
	INT n = p * q;
	INT eiler = (p - 1) * (q - 1);
    //INT e = SimpleE(eiler);
    INT e = getEasy(eiler);
    INT d = GetD(e, eiler);

    INT CryptMsg = pow(mess, n, e);
    INT Decrypt = pow(CryptMsg, n, d);

    cout << "Crypt is : " << CryptMsg;
    cout << endl << "Decrypt is: " << Decrypt;

    
}
int main()
{
    srand(4);
	INT mess =  StrtoInt("G");
    cout << mess << endl;
    RSA(BigInt("103"),BigInt("101"), mess);
    //RSA(BigInt("5"), BigInt("7"), 5);

}




