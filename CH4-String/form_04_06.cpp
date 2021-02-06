/**
 * Number Sequence
 * KMP算法
 * 
 * Input：
 * number of cases
 * a_len b_len
 * a_number_sequence
 * b_number_sequence
 * 
 * Output：
 * position
 * (if not match, output -1)
 **/ 
#include <iostream>
#include <vector>

using namespace std;

void GetNextTable(vector<int>& Next, vector<int> pattern){
    //创建next表的过程其实也是KMP
    int j=0;
    Next[j] = -1;
    int i = Next[j];
    while (j < pattern.size())
    {
        if (i == -1 || pattern[j] == pattern[i])
        {
            i++;
            j++;
            Next[j] = i; //最大匹配前后缀子串长度
        }else
            i = Next[i]; //当不匹配的时候，i要倒退        
    }
    return;
}

int KMP(vector<int> text, vector<int> pattern, vector<int> Next){
    /**
     * KMP算法：
     * 当pattern与text不匹配的时候，根据匹配失败的位置的pattern[i]的next值移动
     **/ 
    int i=0,j=0;
    while (i < text.size() && j< pattern.size())
    {
        if (j == -1 || text[i] == pattern[j])
        {
            i++;
            j++;
        }else
            j = Next[j];        
    }
    if (j == pattern.size())
        cout << i-j+1 << endl;
    else
        cout << "-1" << endl;    
    return 0;
}

int main(){
    int caseNumber=0;
    cin >> caseNumber;
    while (caseNumber--)
    {
        int text_len=0,pattern_len=0;
        cin >> text_len >> pattern_len;

        vector<int> text(text_len);
        vector<int> pattern(pattern_len);
        vector<int> Next(pattern_len);
        for (int i = 0; i < text_len; ++i)
            cin >> text[i];
        for (int i = 0; i < pattern_len; ++i)
            cin >> pattern[i];
        GetNextTable(Next, pattern);
        KMP(text, pattern, Next);
    }
    return 0;
}