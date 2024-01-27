#include<iostream>
#include<list>
#include<vector>
using namespace std;
#define TABLESIZE 40
class node{   // class containing book record
	public:
	int ISSN;
    string BookTitle;
    string authorname;
    int referenceNo;
    int issuableNo;
    node()     // default
    {
    	ISSN=0;
    	BookTitle="";
    	authorname="";
    	referenceNo=0;
    	issuableNo=0;
	}
    node(int ISSN,string BookTitle,string authorname,int referenceNo,int issuableNo) // parameterize
    {
    	this->ISSN=ISSN;
    	this->BookTitle=BookTitle;
    	this->authorname=authorname;
    	this->referenceNo=referenceNo;
    	this->issuableNo=issuableNo;
	}
	void setISSN(int i)
	{
		ISSN=i;
	}
	int getissn()
	{
		return ISSN;
	}
	void display()
	{
		cout<<ISSN<<"---";
		cout<<BookTitle<<" ";
		cout<<authorname<<" ";
		cout<<referenceNo<<" ";
		cout<<issuableNo<<endl;
		
	}
	void newrecord(int ISSN,string BookTitle,string authorname,int referenceNo,int issuableno )
	{
		this->ISSN=ISSN;
    	this->BookTitle=BookTitle;
    	this->authorname=authorname;
    	this->referenceNo=referenceNo;
    	this->issuableNo=issuableNo;
		
	}
	
	friend ostream & operator<<(ostream& out,node& n)
	{
		out<<n.ISSN<<"---";
		out<<n.BookTitle<<" ";
		out<<n.authorname<<" ";
		out<<n.referenceNo<<" ";
		out<<n.issuableNo<<endl;
		return out;
    }   

};
class hashmaps{
	friend class node;
	private:
		list<node> table;  // list of records
		vector<list<node> >v; // array of list of records
        public:
		hashmaps()
		{
			for(int i=0;i<=TABLESIZE;i++)
			{
				v.push_back(table);
			}	
		}
		
		void insertion(int issn,string booktitle,string author_name,int rb,int ib)
		{
			int i;
			i=(issn)%TABLESIZE;
			v[i].push_back(node(issn,booktitle,author_name,rb,ib));
		}
		void remove(int issn)
		{
			int j;
			j=issn%TABLESIZE;
			list<node>::iterator it;
			for(it=v[j].begin();it!=v[j].end();it++)
			{
				if((*it).getissn()==issn)
				{
					v[j].erase(it);
				}
			
			}
		
	    }
	    void update(int issn,string booktitle,string authorname,int rb,int ib)
	    {
	    	int k;
	    	k=issn%TABLESIZE;
	    	list<node>::iterator it;
	    	for(it=v[k].begin();it!=v[k].end();it++)
	    	{
	    		if((*it).getissn()==issn)
	    		{
	    			(*it).newrecord(issn,booktitle,authorname,rb,ib);
				}
			}
		}
		
		void print()
		{
			list<node>::iterator it;
			for(int i=0;i<TABLESIZE;i++)
			{
			
			for(it=v[i].begin();it!=v[i].end();it++)
			{
				(*it).display();
			}
		}
		}
			
};
int main()
{
	hashmaps a1;
	int ISSN;
		string title;
		string authorname;
		int referencenumber;
		int issuablenumber;
		int option;
		do{
			cout<<" WHAT OPEARTION DO YOU WANT TO PERFORM ?  "<<" SELECT OPTION NUMBER "<<endl;
			cout<<" 1.INSERTION  "<<endl;
			cout<<" 2.DELETION  "<<endl;
			cout<<" 3.PRINT      "<<endl;
			cout<<" 4.clearscreen"<<endl;
			cout<<" 5.updation   "<<endl;
			cout<<" 0.exit "<<endl;
			cin >>option;
			switch(option)
			{
				case 0:
					cout<<"----------- YOU EXIT FROM THE LIBRARY SEE YOU LATER GOODBYE-----------------  "<<endl;
					break;
			     case 1:
			     	cout<<" Enter the ISSN NUMBER = ";
			     	cin>>ISSN;
			     	cout<<" Enter the TITLE of the book = ";
			     	cin>> title;
			     	cout<<" Enter the Author Name = ";
			     	cin>> authorname;
			     	cout<<" Enter the Reference Book Number = ";
			     	cin>> referencenumber;
			     	cout<<" Enter the issuable Book Number = ";
			     	cin>>issuablenumber;
			     	a1.insertion(ISSN,title,authorname,referencenumber,issuablenumber);
			     	break;
			     	case 2:
			     		cout<<"Enter the ISSN number YOU want to delete = ";
			     		cin>>ISSN;
			     		a1.remove(ISSN);
			     		break;
			        case 3:
			        	a1.print();
			        	break;
			        case 4:
			        	system ("cls");
			        	break;
			        case 5:
			        	cout<<"ENTER THE ISSN NUMBER WHERE YOU WANT TO UPDATE THE FIELD : ";
		                cin>>ISSN;
			         	cout<<" Enter the TITLE of the book = ";
			     	    cin>> title;
			     	    cout<<" Enter the Author Name = ";
			     	    cin>> authorname;
			     	    cout<<" Enter the Reference Book Number = ";
			     	    cin>> referencenumber;
			     	    cout<<" Enter the issuable Book Number = ";
			     	    cin>>issuablenumber;
		                a1.update(ISSN,title,authorname,referencenumber,issuablenumber);
		                break;
			        default:
			        	cout<<" enter from the given option only ";    	
			     		
			}
			
		}
		while(option !=0);

	return 0;
}


