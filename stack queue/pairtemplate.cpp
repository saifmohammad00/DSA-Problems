#include<iostream>
using namespace std;
template <typename T,typename V>
class paired {
  T x;
	V y;
public:
    void setX(T x){
      this->x=x;
    }
    T getX(){
    return x;
    }
    void setY(V y){
    this->y=y;
    }
    V getY(){
    return y;
    }
};
int main(){
	  paired<paired<int,char>,char> p;
    paired<int,char> q;
    p.setY(100);
    q.setX(500);
    q.setY(99);
    p.setX(q);
    cout<<p.getX().getX()<<" "<<p.getX().getY()<<" "<<p.getY()<<endl;
}