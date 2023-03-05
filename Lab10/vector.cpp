#include <assert.h>
#include <iostream>
#include <string> 
using namespace std;
template <typename T>
class vector
{ int dim;
  T* buf;
  public:
     vector();   
     vector(int , T*);
     vector(const vector&);
     vector & operator=(const vector &);
     ~vector();
	 T& operator[](int i);
     int getDim();
     
	 friend ostream & operator << (ostream & dev,  vector & v)
     {
	    dev << "Vector:" <<endl;
	    dev << "Nr Elem:" << v.dim << endl;
	    if (v.buf!=NULL)
	    for(int i = 0; i < v.dim; i++) {
		   dev << v.buf[i];//am nevoie de op<< pt T
		   if(i < v.dim-1)
		    	dev << ",   ";
		   else
		    	dev << "." << endl;
		}
        dev<<endl;
	    return dev;
     }

	//void addElem(int, T&  ); - adauga element T pe pozitia i - cu realocare
	//void removeElem(int  ); - sterge elementul de pe pozitia i cu realocare
	//void sortare(); ordoneaza crescator elementele din buf; in T avem nevoie de op< 
};

template <typename T>
vector<T>::vector( ){
	dim=0;
	buf=NULL;
}

template <typename T>
vector<T>::vector(int d, T*b){
       dim=d;
       if (b==NULL) buf = NULL;
	   else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
            buf[i]=b[i]; //op= in T
        }
     }
     
     
template <typename T>
vector<T>::vector(const vector<T>& v){
       dim=v.dim;
       if (v.buf==NULL) buf=NULL;
       else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
             buf[i]=v.buf[i]; //op= in T
        }
	 }
     
     
template <typename T>
vector<T>::~vector(){
        if (buf!=NULL) delete [] buf; //destr in T
}
               
template <typename T>
vector<T>&  vector<T>::operator=(const vector &v){
       dim=v.dim;
       if (buf!=NULL) delete [] buf; //destr in T
       if (v.buf==NULL) buf=NULL;
       else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
             buf[i]=v.buf[i]; //op= in T  
		}
        return *this;            
}

template <typename T>
T& vector<T>::operator[](int i){
      assert ((i>-1 && i<dim));
	  return buf[i];  //constr de copiere in T     
}   

template <typename T>
int vector<T>::getDim(){
   return dim;
}
 
class complex
{ double re,im;
public: complex(double r=0,double i=0):re(r),im(i){
        }
         
        friend ostream& operator<<(ostream &d,complex x){
	 
            d<<x.re<<" j"<<x.im;
            return d;
        }
        //ordonarea se va face in fctie de partea reala
};



int main(){
	 complex *b=new complex[2];
	 b[0]=complex(1,2);
     b[1]=complex(2,2);
	 vector<complex> v(2,b);
     cout<<v;
     
	 cout<<v[0];
     
	 v[1]=complex(5,5);
     cout<<v;
     
     vector<complex> v1(v);
     cout<<v1;
     
     v=v1;
     cout<<v;
          
     return 0;
}


