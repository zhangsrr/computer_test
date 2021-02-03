/*
* Grading
* 三位专家先评分，如果三个人都不一致，则由审判长给出成绩
* 专家E1 E2 E3
* 审判长J
* if abs(E1-E2) <= T then G = (E1+E2)/2
* else if (E1-E2) > T && (abs(E3-E1)<=T && abs(E3-E2)>T) ||  (abs(E3-E2)<=T && abs(E3-E1)>T)
*		then G = abs(E3-E1) > abs(E3-E2)? (E3+E2)/2 : (E3+E1)/2;
* else if (E1-E2) > T && abs(E3-E1)<=T && abs(E3-E2)<=T
*		then G = (E1+E2+E3)/2
* else
*		then G = J
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float P = 0, T = 0, G1 = 0, G2 = 0, G3 = 0, GJ = 0;
	float G = 0;
	while (cin >> P >> T >> G1 >> G2 >> G3 >> GJ)
	{
		if (abs(G1-G2) <= T)
			G = (G1 + G2) / 2;
		else
		{
			if ((abs(G3 - G1) <= T && abs(G3 - G2) > T) || (abs(G3 - G1) > T && abs(G3 - G2) <= T))
				G = abs(G3 - G1) <= abs(G3 - G2) ? (G3 + G1) / 2 : (G3 + G2) / 2;
			else if (abs(G3 - G1) <= T && abs(G3 - G2) <= T)
				G = (G1 + G2 + G3) / 3;
			else
				G = GJ;
		}
		cout << setiosflags(ios::fixed) << setprecision(1) << G << endl;
	}
}
