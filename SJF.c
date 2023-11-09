#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int id,bt,tat,wt;
}process;
process p[10],temp;
int main(){
    int i,j,n,total_wt=0,total_tat=0;
    float avg_wt,avg_tat;
    printf("Enter the number of processes:\n");
    scanf("%d",&n);
    printf("Enter the process id,bt\n");
    for(i=0;i<n;i++){
        scanf("%d%d",&p[i].id,&p[i].bt);
        
    }
    p[0].wt=0;
    p[0].tat=p[0].bt;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[i].bt>p[j].bt){
                 temp=p[i];
                 p[i]=p[j];
                 p[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        p[i].wt=p[i-1].wt+p[i-1].bt;
        p[i].tat=p[i].wt+p[i].bt;
        total_wt+=p[i].wt;
        total_tat+=p[i].tat;
    }
    avg_wt=total_wt/n;
    avg_tat=total_tat/n;
    printf("AVERAGE WAITING TIME=%.2f\n",&avg_wt);
    printf("AVERAGE TURNAROUND TIME=%.2f\n",&total_tat);
    printf("process id\t Burst time\t waiting time\t turnaroundtime\n");
    for(i=0;i<n;i++){
    printf("%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].bt,p[i].wt,p[i].tat);
    }
       

}