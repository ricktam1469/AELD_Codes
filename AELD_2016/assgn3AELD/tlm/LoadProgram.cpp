#include "LoadProgram.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "ALU.h"
#include <vector>
using namespace std;

LoadProgram::LoadProgram()
{
    ifstream File1("ASCI.txt");
    //Operation opp;
string str;
        int i = 0;
if(File1.is_open())
{
            while(getline(File1,str))

    {
        string arr[10];
        stringstream split(str);
        while (split.good()){
            split >> arr[i];
            ++i;

        }

        //cout<< i;
        if(i==1)
            {

                operand1=arr[0];
                operand2="NULL";
                operand3="NULL";

            }
         if(i==2)
            {

                operand1=arr[0];
                operand2=arr[1];
                operand3="NULL";
            }
        if(i==3)
             {
                operand1=arr[0];
                operand2=arr[1];
                operand3=arr[2];
             }

        if(operand1=="ADD")
        operation.push_back (ADD);
        if(operand1=="SUB")
        operation.push_back (SUB);
        if(operand1=="DIV")
        operation.push_back (DIV);
        if(operand1=="MUL")
        operation.push_back (MUL);
        if(operand1=="CMP")
        operation.push_back (CMP);
        if(operand1=="LOAD")
        operation.push_back(LOAD);
        if(operand1=="COUTALL")
        operation.push_back(COUTALL);
        if(operand1=="COUT")
        operation.push_back(COUT);
        if(operand1=="JMP")
        operation.push_back(JMP);


        op2.push_back(operand2);
        op3.push_back(operand3);
        if((operand1!="COUTALL")&&(operand1!="COUT")&&(operand1!="JMP"))
         cout<<operand1<<"  "<<"  "<<operand2<<"  "<< operand3 <<endl;
        else if(operand1=="COUTALL")
            cout<<operand1 <<endl;
         else if(operand1=="COUT"||operand1=="JMP")
            cout<<operand1<<" "<<operand2<<endl;
i=0;

}
}
else
    cout<< "FILE IS NOT OPENED";

}
