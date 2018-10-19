double exe=0;
int curr=0;
int priority(double time){
	
	
	int j;
double 	sh = 999999999999;
	
	int spid = -1;
	int chk =0,l;
		int i;
	if(time>exe_time[TASK-1][1]){
		
		for(i=0;i<TASK;i++){
		if(exe_time[i][0]<=0) continue;
	  else if(exe_time[i][0]<sh){
			sh = exe_time[i][0];
			spid = i;
		}
	}
		
		
	}
else  {
	for(j=0;j<TASK;j++){
		
		if(exe_time[j][1]==time){
			chk = 1;
		   l=j;
		}
	}

	if(!chk){
		l = curr;
	}
	
	for(i=0;i<=l;i++){
		if(exe_time[i][0]<=0) continue;
	  else if(exe_time[i][0]<sh){
			sh = exe_time[i][0];
			spid = i;
		}
	}
}
	return spid;
}

srtf(){
	double   tat[TASK];
	int i,j;
	for(i=0;i<TASK;i++){
		tat[i] = 0;
	}
	 
	 
	while(priority(exe)!=-1){
	
int pid  = priority(exe); 
if(pid == -1){
	exe++;
	continue;
}
  curr = pid;

for(j=0;j<1;j++){
	

	if(exe_time[pid][0]<=0){
		printf("execution of %d at %d\n",task_no[pid],exe);
		exe = exe+1;
		exe_time[pid][0] -=1; 
		break;
	}
	else{
		
		exe = exe+1;
		exe_time[pid][0] -=1;
		
	
		
	}
	
}

tat[pid] = exe;


}


printf("\n-------------------------------------------------------------------------------\n");
for(i=0;i<TASK;i++){
	
	printf("turn around time of %d is %f\n",task_no[i],tat[i]);
}

double sum =0;
for(i=0;i<TASK;i++){
	sum+=tat[i];
}

printf("******avg turnaround time is %f ",sum/TASK);

}
