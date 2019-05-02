#include<iostream>
using namespace std;

//CPU Scheduling Algorithms
class cpuschedule{
int n,Bu[20];
float Twt,Awt,A[10],Wt[10],w,Ttat,Atat,Tat[10];

public:
    void Getdata();
    void Fcfs();
    void Sjf();
    void Priority();
    void RoundRobin();
    void WRR();
};
void cpuschedule::Getdata(){
int i;
 cout<<"\tEnter the no of processes:";
 cin>>n;
   for(i=1;i<=n;i++){
            cout<<"\tEnter The BurstTime for Process p"<<i<<"= ";
   cin>>Bu[i];
   }
}

void cpuschedule::Fcfs(){
int i, B[10];
Twt=0.0;
Ttat=0.0;
    for(i=1;i<=n;i++){
        B[i]=Bu[i];
        cout<<"\n\tBurst Time for Process P"<<i<<"= ";
        cout<<B[i];
    }
    Wt[1]=0;
    for(i=2;i<=n;i++)
    {
        Wt[i]=B[i-1]+Wt[i-1];
    }
    for(i=1;i<=n;i++)
    {
        Tat[i]=B[i]+Wt[i];
    }
    //calculating Average Waiting Time and Average Turnaround Time
    for(i=1;i<=n;i++)
    {
        Twt=Twt+Wt[i];
        Ttat=Ttat+Tat[i];
    }
    Awt=Twt/n;
    Atat=Ttat/n;
    cout<<"\n\n\tTotal Waiting Time= "<<Twt;
    cout<<"\n\tAverage Waiting Time= "<<Awt;
    cout<<"\n\n\tTotal Turnaround Time= "<<Ttat;
    cout<<"\n\tAverage Turnaround Time= "<<Atat;
}
void cpuschedule::Sjf()
{
int i,k, temp, B[10];//here B stoers the sorted burst time of process
Twt=0.0;
Ttat=0.0;
      for(i=1;i<=n;i++){
        B[i]=Bu[i];
        cout<<"\n\tBurst Time for Process P"<<i<<"= ";
        cout<<B[i];
    }

        for(i=n; i>=1;i--)
            {
                for(k=2;k<n+1;k++)
                {
                    if(B[k-1]>B[k])
                    {
                        temp=B[k-1];
                        B[k-1]=B[k];
                        B[k]=temp;
                    }
                }
            }
Wt[1]=0;
for(int i=2;i<=n;i++){
    Wt[i]=B[i-1]+Wt[i-1];
}
 for(i=1;i<=n;i++)
    {
        Tat[i]=B[i]+Wt[i];
    }
    //calculating Average Waiting Time and Average Turnaround Time
    for(i=1;i<=n;i++)
    {
        Twt=Twt+Wt[i];
        Ttat=Ttat+Tat[i];
    }
    Awt=Twt/n;
    Atat=Ttat/n;
    cout<<"\n\n\tTotal Waiting Time= "<<Twt;
    cout<<"\n\tAverage Waiting Time= "<<Awt;
    cout<<"\n\n\tTotal Turnaround Time= "<<Ttat;
    cout<<"\n\tAverage Turnaround Time= "<<Atat;

}

void cpuschedule::Priority(){
int i,B[10],P[10],j;
w=0.0;
int max;
Twt=0.0;
Ttat=0.0;
max=1;
for(i=1;i<=n;i++)
        {
            B[i]=Bu[i];
            cout<<"\n\n\tBurst Time for process P"<<i<<"= ";
            cout<<B[i];
            cout<<"\n\tEnter the priority for the process P"<<i<<"= ";
            cin>>P[i];
            if(max<P[i])
                max=P[i];

        }
j=1;
while(j<=max)//calculating the waiting time for each process
{
    i=1;
    while(i<=n)
    {

        if(P[i]==j)//searching the highest priority(lowest value Process)
        {
            Wt[i]=w;
            w=w+B[i];//previous bburst time is waiting for next process
        }
        i++;
    }
        j++;
}
//calculating Average Waiting Time and Average Turnaround Time
for(i=1;i<=n;i++)
    {
        Tat[i]=B[i]+Wt[i];
    }
    for(i=1;i<=n;i++)
    {
        Twt=Twt+Wt[i];
        Ttat=Ttat+Tat[i];
    }
    Awt=Twt/n;
    Atat=Ttat/n;
    cout<<"\n\n\tTotal Waiting Time= "<<Twt;
    cout<<"\n\tAverage Waiting Time= "<<Awt;
    cout<<"\n\n\tTotal Turnaround Time= "<<Ttat;
    cout<<"\n\tAverage Turnaround Time= "<<Atat;

}

void cpuschedule::RoundRobin(){
    int i,B[10],B_rem[10],Q,t;
    Twt=0.0;
    Ttat=0.0;
    for(i=1;i<=n;i++)
    {
        B[i]=Bu[i];
        cout<<"\n\tBurst Time for process P"<<i<<"= ";
        cout<<B[i];
    }
    cout<<"\n\tInput Quantum: ";
    cin>>Q;

    for(i=1;i<=n;i++)
        B_rem[i]=B[i];
        t=0;
        while(1)
        {
            bool done=true;
            //traverse all processes one by one repeatedly
            for(int i=1;i<=n;i++)
            {
                if(B_rem[i]>0)
                {
                    //there is a pending process
                    done=false;
                    if(B_rem[i]>Q)
                    {
                        //how much time a process has been processed
                        t=t+Q;
                        //Decrease the burst time
                        //current process by quantum
                        B_rem[i]=B_rem[i]-Q;
                    }else
                    {
                        //if the burst time is smaller or equal to quantum
                        //last cycle
                        t=t+B_rem[i];
                        Wt[i]=t-B[i];//waiting time
                        B_rem[i]=0;
                    }
                }
            }
            //if all process are done
            if(done==true)
                break;
        }

    //calculating Average Waiting Time and Average Turnaround Time
for(i=1;i<=n;i++)
    {
        Tat[i]=B[i]+Wt[i];
    }
    for(i=1;i<=n;i++)
    {
        Twt=Twt+Wt[i];
        Ttat=Ttat+Tat[i];
    }
    Awt=Twt/n;
    Atat=Ttat/n;
    cout<<"\n\n\tTotal Waiting Time= "<<Twt;
    cout<<"\n\tAverage Waiting Time= "<<Awt;
    cout<<"\n\n\tTotal Turnaround Time= "<<Ttat;
    cout<<"\n\tAverage Turnaround Time= "<<Atat;

}
void cpuschedule::WRR(){
int i,B[10],B_rem[10],Q,t,k,W[10];
Twt=0.0;
Ttat=0.0;
    for(i=1;i<=n;i++)
    {
     B[i]=Bu[i];
     cout<<"\n\tBurst Time for process P"<<i<<"=";
     cout<<B[i];
     cout<<"\n\tWeight for process P"<<i<<"=";
     cin>>W[i];
    }
    cout<<"\n\tInput Quantum: ";
     cin>>Q;
for(i=1; i<=n; i++)
    B_rem[i]=B[i];
    t=0;
    while(1)
    {
        bool done =true;
        for(int i=1; i<=n;i++)
        {
            k=W[i];
            for(int j=1;j<=k;j++)
            {
                if(B_rem[i]>0)
                {
                    done=false;
                    if(B_rem[i]>Q)
                    {
                        t=t+Q;
                        B_rem[i]=B_rem[i]-Q;
                    }else
                        {
                        t=t+B_rem[i];
                        Wt[i]=t-B[i];
                        B_rem[i]=0;
                        }
                }
            }
        }
        if(done==true)
        break;
    }
    //calculating Average Waiting Time and Average Turnaround Time
for(i=1;i<=n;i++)
    {
        Tat[i]=B[i]+Wt[i];
    }
    for(i=1;i<=n;i++)
    {
        Twt=Twt+Wt[i];
        Ttat=Ttat+Tat[i];
    }
    Awt=Twt/n;
    Atat=Ttat/n;
    cout<<"\n\n\tTotal Waiting Time= "<<Twt;
    cout<<"\n\tAverage Waiting Time= "<<Awt;
    cout<<"\n\n\tTotal Turnaround Time= "<<Ttat;
    cout<<"\n\tAverage Turnaround Time= "<<Atat;

}
int main(){
int j;
cpuschedule cpu;
cout<<"\n\n\tCPU Scheduling Algorithms Simulation"<<endl;
cout<<"\n\tSelect the Algorithm:\n\t1:First Come First Serve Algorithm\n\t2:Shortest Job First Algorithm\n\t3:Priority Scheduling Algorithm\n\t4:Round Robin Algorithm\n\t5:Weighted Round Robin Algorithm\n\t6:Terminate Simulation";
cout<<"\n\n\tPlease! Enter Algorithm ID: ";
cin>>j;


switch(j) {
      case 1 :
         cout << "\n\tFirst Come First Serve Algorithm: " << endl;
         cpu.Getdata();
         cpu.Fcfs();
         main();
         break;
      case 2 :
         cout << "\n\tShortest Job First Algorithm: " << endl;
        cpu.Getdata();
        cpu.Sjf();
         main();
         break;
      case 3 :
         cout << "\n\tPriority Schedulinng Algorithm: " << endl;
         cpu.Getdata();
         cpu.Priority();
         main();
         break;
      case 4 :
         cout << "\n\tRound Robin Algorithm" << endl;
           cpu.Getdata();
         cpu.RoundRobin();
         main();
         break;
       case 5 :
         cout << "\n\tWeighted Round Robin Algorithm" << endl;
         cpu.Getdata();
         cpu.WRR();
         main();
         break;
       case 6 :
         cout << "\n\tTerminating Simulation....." << endl;
        exit(0);
         break;
      default :
         cout << "\n\tInvalid Algorithm ID" << endl;
         main();
   }

return 0;
}
