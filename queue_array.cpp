//circular queue implementation

#include<iostream>
using namespace std;
    class Queue{
    int *queue,f,r,n,res;
    public:
    Queue(int n){
        this->n=n;
        queue=new int[n];
        f=-1;
        r=-1;
    }
    ~Queue(){
        delete queue;
    }
    bool enqueue(int d){
        if(f==(r+1)%n) return false;
        else if(f==-1&&r==-1){
            f++;
            r++;
        }
        else r=(r+1)%n;
        queue[r]=d;
        return true;
    }
    int dequeue(){
        res=queue[f];
        if(r==f){
            f=-1;
            r=-1;
        }
        else{
            f=(f+1)%n;
        }

        return res;
    }
    bool isEmpty(){
        if(f==-1) return true;
        return false;
    }
    void print(){
        if(!isEmpty()){
            int i=f;
            do{
                cout<<queue[i]<<" ";
                i=++i%n;
            }while(i!=(r+1)%n);
        }
        else cout<<"queue is empty"<<endl;
    }
};


int main(){
    Queue q(6);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    return 0;
}