/*
* abc
* 设a、b、c均是0到9之间的数字，abc，bcc是两个三位数，且有abc+bcc=532
* 求满足条件的所有a，b，c的值
* 
* Output：
* a b c
*/
#include <iostream>
using namespace  std;

int main(){
    //abc+bcc = a*100+b*110+c*12
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (i*100+j*110+k*12 == 532)
                    cout << i << " " << j << " " << k << endl;
            }
            
        }
        
    }
    return 0;
    
    
}