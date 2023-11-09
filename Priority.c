#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int id,at,pt,wt,tat,bt;
}process;
process p[10];


void main(){

    int i,j,time,temp[10],sp,n,count=0;
    
    int totalwt=0,totaltat=0;
    printf("Enter the number of processes:\n");
    scanf("%d",&n);
    printf("Enter priority,burst time,arrival time:\n");
    for(i=0;i<n;i++){
        scanf("%d%d%d",&p[i].pt,&p[i].bt,&p[i].at);
        p[i].id=i+1;
        temp[i]=p[i].bt;

    }
    p[9].pt=1000;
    for(time=0;count!=n;time++){
        sp=9;
        for(i=0;i<n;i++){
            if(p[sp].pt>p[i].pt&&p[i].at<=time&&p[i].bt>0){
                sp=i;
            }
        }
        p[sp].bt=p[sp].bt-1;
        if(p[sp].bt==0){
            count++;
            p[sp].tat=time+1-p[sp].at;
            p[sp].wt=p[sp].tat-temp[sp];
            totalwt+=p[sp].wt;
            totaltat+=p[sp].tat;
        }

    }
    printf("id\tpriority\tarrival time\tburst time\tturnaround time\t waiting time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].pt,p[i].at,temp[i],p[i].tat,p[i].wt);
    }

}