//  08/02/2023 Pair Programming with Gavin McCulley
#include <iostream>
#include <vector>

using namespace std;

 // "Broken Calculator" https://open.kattis.com/problems/brokencalculator 
int main()
{
   int length; //num of operations to perform
   long firstNum, secondNum; // placeholders for each operand
   char op; // operator
   long result;  // placeholder for each result
   vector<long> prevOps;

    prevOps.push_back(1);

    cin >> length;


    for (int i = 0; i < length; i++)
    {

        cin >> firstNum >> op >> secondNum;

        switch(op)
        {
            case '+':
                result = firstNum + secondNum;
                result = result - prevOps.back();
                prevOps.push_back(result);
                cout << result << endl;
                break;
            case '-':
                result = firstNum - secondNum;
                result = result * prevOps.back();
                prevOps.push_back(result);
                cout << result << endl;
                break;
            case '*':
                result = firstNum * secondNum;
                result = result * result;
                prevOps.push_back(result);
                cout << result << endl;
                break;
            case '/':
                if (firstNum % 2 == 0) result = firstNum / 2;
                else result = (firstNum+1) / 2;
                prevOps.push_back(result);
                cout << result << endl;
                break;
        }
    }

}

