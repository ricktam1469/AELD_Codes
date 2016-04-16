#include <iostream>
#include "ALU.hpp"

using namespace std;

int main()
{
	Registers Reg;
	ALU aluObject(Reg);
	int op0,op1,n;
	char ch;

	for(unsigned int arrIterate=0 ; arrIterate < (sizeof(Reg.storage_array)/sizeof(*Reg.storage_array)) ; arrIterate++) 
		Reg.storage_array[arrIterate]=0;	//Initially store 0 to all elements of Registers
		
	do{
		cout<<"Enter the value of op0 : ";
		cin>>op0;
		cout<<"Enter the value of op1 : ";
		cin>>op1;
		//Accessing first and second address of array(registers)
		Reg.storage_array[0]=op0;
		Reg.storage_array[1]=op1;
		aluObject.register_location=Reg.storage_array;
		//cout<<"1. ADD\n"<<"2. SUB\n"<<"3. MUL\n"<<"4. DIV\n"<<"5. CMP\n"<<"6. EXIT\n";
		while(1){
			cout<<"\nOperation Menu: ( "<<"1. ADD  "<<"2. SUB  "<<"3. MUL  "<<"4. DIV  "<<"5. CMP  "<<"6. EXIT )"<<endl;
			cout<<"Enter your choice(From 1 to 6 For Exit press 6) : ";
			cin>>n;
			switch(n){
				case 1: Reg.storage_array[0]=aluObject.execute(ADD);
					cout<<"Addition of op0 and op1 (op0+op1) : "<<Reg.storage_array[0]<<endl;
					break;
				case 2: Reg.storage_array[0]=aluObject.execute(SUB);
					cout<<"Subtraction of op0 and op1 (op0-op1) : "<<Reg.storage_array[0]<<endl;
					break;
				case 3: Reg.storage_array[0]=aluObject.execute(MUL);
					cout<<"Multiplication of op0 and op1 (op0*op1) : "<<Reg.storage_array[0]<<endl;
					break;
				case 4: try{
						if(op1==0)
							throw op1;
					Reg.storage_array[0]=aluObject.execute(DIV);
					cout<<"Division of op0 and op1 (op0/op1) : "<<Reg.storage_array[0]<<endl;
					}
					catch(int i){
						cout<<"Divide by Zero Exception!! Division(op0/op1) is not possible! Try other operation :"<<endl;
					}
					break;
				case 5: Reg.storage_array[0]=aluObject.execute(CMP);
					cout<<"Comparision of op0 and op1 (op0>op1:1, op0=op1:0, op1<op0:-1)\n";
					cout<<Reg.storage_array[0]<<endl;
					break;
				case 6: goto newOperand; 
				
				default: cout<<"Enter the valid choice."<<endl;
					 break;	
			}
		}
		newOperand: //label for goto command used in switch case 6
		cout<<"\nWant to enter new operand and continue the operations (y/n)? ";
		cin>>ch;

	} while(ch=='y' || ch=='Y');		

return 0;
}
