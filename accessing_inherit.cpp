#include<iostream>
//second commit 
using namespace std;
//from branchA
//second from branchA
int callA=0;
int callB=0;
int callC=0;
class A
{
protected:
   
   void func(int  & a)
   {
      a=a*2;
      callA++;
   }
};

class B
{
protected:
   void func(int & a)
   {
      a=a*3;
      callB++;
   }
};

class C
{
protected:
   void func(int & a)
   {
      a=a*5;
      callC++;
   }
};


class D: public A,B,C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val=1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
		 //int temp = new_val;
		 while (new_val%5 == 0){
		 C::func(val);
		 new_val /=5;		
		 }	
		 while (new_val%3 == 0){
		 B::func(val);
		 new_val /=3;		
		 }
		 while (new_val%2 == 0 &&  new_val!=0){
		 A::func(val);
		 new_val /=2;		
		 }
		 	
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};

void D::check(int new_val)
{
       update_val(new_val);
       cout<<"Value = "<<val<<endl<<"A's func called "<<callA<<" times "<<endl<<"B's func called "<<callB<<" times "<<endl<<"C's func called "<<callC<<" times"<<endl;
}


int main()
{
   D d;
   int new_val;
   cin>>new_val;
   d.check(new_val);

}
