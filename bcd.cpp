#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

string* bcd_converter(int decimal_number, size_t &length)
{
    string bcd[10] = {'0000', '0001', '0010', '0011', '0100', '0101', 
                        '0110', '0111', '1000', '1001'};
    int *answer = new int[3];
    int num = 0;
    
    string num_string = to_string(decimal_number);
    length = num_string.size();
    int i = static_cast<int>(length - 1);

    if(decimal_number < 1 || decimal_number > 999)
    {
        answer[i] = 0;
        return answer;
    }

    while (i >= 0)
    {
        num = stoi(num_string[i]);
        answer[i] = bcd[num];
        --i;
    }
    
    return answer;
}

int main()
{
    int num = 52;
    int i = 9;
    size_t length = 0; 

    int *answer = bcd_converter(num, length);

    while(answer[i])
    {
        printf("%d",answer[i]);
        --i;
    }

    return 0;
}