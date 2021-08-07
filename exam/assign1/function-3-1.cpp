# include <iostream>
using namespace std;
package chegg1;

public class Customer
{
    String name;
    int value;
    Customer(String n, int v)
    {
        this.name = n;
        this.value = v;
    }
}


package chegg1;
//Using circular queue under the hood
public class SalesAgent
{
    int queueFront;
    int queueRear;
    String name;
    int actualQueueLength;
    Customer[] queue;
    SalesAgent(String name)
    {
        queue = new Customer[10];
        this.name = name;
        queueFront = -1;
        queueRear = -1;
        actualQueueLength = 0;
    }

    void deal()
    {
        this.dequeue();
    }
    
    void enqueue(Customer c)
    {
        if(this.queueFront==-1 && this.queueRear==-1)
        {
            this.queueFront++;
            this.queueRear++;
            this.queue[queueRear] = c;
            System.out.println(c.name + " added. Value: " + c.value);
        }
        else
        {
            if((queueFront==0 && queueRear==queue.length-1)||(queueRear==queueFront-1)) {              //Queue is full
                        System.out.println("Error. Queue Full.");
                        return;
                }
                else {
                        queueRear = (queueRear+1)%queue.length;
                        queue[queueRear]  = c;
                        System.out.println(c.name + " added. Value: " + c.value);
                }
        }
        void dequeue() {
                if(queueFront == -1 && queueRear == -1) {
                        System.out.println("Error. Queue empty.");
                        return;
                }
                else if(queueFront==queueRear) {
                        System.out.println("Received cash: " + queue[queueFront].value);
                        System.out.println(queue[queueFront].name + " removed.");
                        queue[queueFront] = null;
                        queueFront = -1;
                        queueRear = -1;
                }
                else {
                        System.out.println("Received cash: " + queue[queueFront].value);
                        System.out.println(queue[queueFront].name + " removed.");
                        queue[queueFront] = null;
                        queueFront = (queueFront+1)%queue.length;                                                       //Remove from queue
                }
        }
}


package chegg1;

public class SuperMarket {
        SalesAgent sa;
        SuperMarket(String name){
                sa = new SalesAgent(name);
        }
        public static void main(String[] args) {
                SuperMarket sm = new SuperMarket("David");
                Customer c1 = new Customer("A", 100);
                sm.sa.enqueue(c1);
                Customer c2 = new Customer("B", 210);
                sm.sa.enqueue(c2);
                Customer c3 = new Customer("C", 1100);
                sm.sa.enqueue(c3);
                Customer c4 = new Customer("D", 10);
                sm.sa.enqueue(c4);
                Customer c5 = new Customer("E", 450);
                sm.sa.enqueue(c5);
                Customer c6 = new Customer("F", 120);
                sm.sa.enqueue(c6);
                Customer c7 = new Customer("G", 125);
                sm.sa.enqueue(c7);
                Customer c8 = new Customer("H", 1000);
                sm.sa.enqueue(c8);
                Customer c9 = new Customer("I", 140);
                sm.sa.enqueue(c9);
                Customer c10 = new Customer("J", 485);
                sm.sa.enqueue(c10);
                sm.sa.deal();
                sm.sa.deal();
                sm.sa.deal();
                sm.sa.deal();
                Customer c11 = new Customer("K", 37);
                sm.sa.enqueue(c11);
                sm.sa.deal();
                sm.sa.deal();
        }

}