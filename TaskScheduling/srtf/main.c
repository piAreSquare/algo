#include "decl.h"
#include"srtf.c"

int main(){
	int k =0;
int i;srand(time(NULL));
for(i=0;i<TASK;i++){
   
  task_no[i]  = rand()%100;
exe_time[i][0] = rand()%100;
exe_time[i][1] = i==0?0:(rand()%10+k);
k = exe_time[i][1];
  printf(" Task No: %d and execution time is %f and start time is %f\n",task_no[i],exe_time[i][0],exe_time[i][1]);

}
printf("************************SRTF******************* \n");
srtf();
getch();
}
