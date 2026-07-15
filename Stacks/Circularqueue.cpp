class MyCircularQueue {
    int*arr;
    int size, front, rear;
public:
    MyCircularQueue(int k) {
        front=-1;
        rear=-1;
       
        size=k;
        arr=new int[k];
    }
    
    bool enQueue(int value) {
        if((rear+1)%size==front)
        return false;
        if(rear==-1){
            front=rear=0;
        }
        else{
        rear=(rear+1)%size;}
        arr[rear]=value;
        return true;

    }
    
    bool deQueue() {
       if(front==-1) return false; //empty
       if(front==rear){
        front=-1;
        rear=-1;
       } //only one elmnt 
       else{
        front=(front+1)%size;
       }
       return true;
    }
    
    int Front() {
        if(front==-1) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(rear==-1) return -1; // queue is empty
        return arr[rear];
    }
    
    bool isEmpty() {
        return (front==-1);
    }
    
    bool isFull() {
        return ((rear+1)%size==front);
    }
};

