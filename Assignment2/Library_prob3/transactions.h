#include<iostream>
#include"date.h"
#include<fstream>

using namespace std;

class Date;
//Class to store each transaction
class Transactions
{
	int id;
	int itemType;// 0-books 1-journal
	int issuer; // 0-Student 1-teacher
	int issuerId;
	int type; // 0-issue 1-return
	Date d;


	public:
		//Construcutor
		Transactions(int i,int it,int iss,int iid,int t)
		{
			id=i;
			itemType=it;
			issuer=iss;
			issuerId=iid;
			type=t;
			Date dt;
			d=dt;
		}

		//function to write transactions to a file
		void writeTrans()
		{
			ofstream file;
			file.open("translist.dat",ios::out|ios::app|ios::bin);
			file.write((char*)this,sizeof(*this));
			file.close();
		}

		//Function to display transaction
		void displayTrans()
		{
			cout<<"Id: "<<id<<endl<<"Item type: ";

			if(itemType==0)
				cout<<"Book"<<endl;
			else
				cout<<"Journal"<<endl;

			if(issuer==0)
				cout<<"Issued to: Student "<<issuerId<<endl;
			else
				cout<<"Issued to: Faculty "<<issuerId<<endl;
			cout<<"Date :"<<d<<endl;
		}
}