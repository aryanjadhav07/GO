

class Buffer{

int item ;
boolean isEmpty = true;

synchronized void produce(int value){
    while(!isEmpty){
        try{
            wait();
        }
        catch(InterruptedException e){
            e.printStackTrace();
        }
    }
    item = value;
    System.out.println("Produced : " + item);
    isEmpty = false;
    notify();
}

synchronized void consume(){
    while(isEmpty){
        try{
            wait();
        }
        catch(InterruptedException e){
            e.printStackTrace();
        }

    }
        System.out.println("Consumed : " + item);
        isEmpty = true;
        notify();
    
}

}

class Producer extends Thread{
    Buffer b;

    Producer(Buffer b){
        this.b = b;
    }

    public void run(){
        for(int i = 0; i <= 5 ; i++){
            b.produce(i);
        }
    }
}

class Consumer extends Thread{
    Buffer b;
    
    Consumer(Buffer b){
        this.b = b;
    }

    public void run(){
        for(int i = 0; i <= 5 ; i++){
            b.consume();
        }
    }
}

public class Assignment10{
    public static void main(String[] args) {
        Buffer b = new Buffer();
        Producer p = new Producer(b);
        Consumer c = new Consumer(b);

        p.start();
        c.start();
    }
}
