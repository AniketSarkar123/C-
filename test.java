import java.util.Scanner;

class A{
    public int x;
    public void f1(int i){
        System.out.println("In f1A()");
    }

    public int f1(int i){
        return i;
    }

    
}

class B extends A{
    public void f1(int i){
        System.out.println("In f1B()");
    }

    
}

class test
{
    public static void main(String args[]){
        int i=2;
        float f=2.0f;
        A a=new A();
        //B b=new B();
        //a=b;
        a.f1(f);
        System.out.println(a.f1(i));
        //b.f1(f);
        //b.f1(f);

        

  
      

       
        

        
    }
}