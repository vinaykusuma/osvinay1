#include<stdio.h>
#include<unistd.h>
struct ThreeStudents{
	int s_id;
    int burst_time;
    int complete_time;
	int foodtaken_time;
};
void completiontime(ThreeStudents st[]){
    for (int i=0;i<3;i++){
            if(st[i].foodtaken_time!=0)
            {
			
                st[i].complete_time +=1;
            }
    }

}

bool remaining(ThreeStudents st[]){
    for (int i=0;i<3;i++){
        if(st[i].foodtaken_time!=0){
            return true;
        }
    }
    return false;
}

void sorting(ThreeStudents st[]){
    for(int i=1;i<3;i++){
        for(int j=0;j<3-i;j++){
            if(st[j].foodtaken_time < st[j+1].foodtaken_time){
                ThreeStudents temp1 = st[j];
                st[j]=st[j+1];
                st[j+1]=temp1;
            }
            else if(st[j].foodtaken_time == st[j+1].foodtaken_time){
                if(st[j].s_id > st[j+1].s_id){
                    ThreeStudents temp2 = st[j];
                    st[j]=st[j+1];
                    st[j+1]=temp2;
                }
            }
        }
    }

}

int main(){
	ThreeStudents st[3];

	
	for(int i=0;i<3;i++){
        printf("PLS ENTER ID NUMBERS FOR  3 STUDENTS i.e for %d \n",i+1);
        scanf("%d",&st[i].s_id);
          st[i].complete_time=0;
        printf("PLS ENTER THE TIME TO TAKE THE FOOD BY STUDENTS i.e for %d \n",i+1);
        scanf("%d",&st[i].foodtaken_time);
		st[i].burst_time = st[i].foodtaken_time;

	}
	sorting(st);

    printf("STUDENTS WILL ENTER QUEUE IN FOLLOWING WAY \n");
    while(remaining(st))
	{
        printf("%d \n ",st[0].s_id);
        completiontime(st);
        st[0].foodtaken_time--;
        sorting(st);
    }
    int sum = 0;
    int z;
    int sum1 = 0;
    printf("STUDENT ID | TURN AROUND TIME | WAITING TIME\n");
    for(int i=0;i<3;i++){
        printf("%d 2\t\t %d \t\t",st[i].s_id,st[i].complete_time);
        z=st[i].complete_time - st[i].burst_time;
        printf("%d \n",z);
        sum += st[i].complete_time;
        sum1 += z;
    }
    float a=sum/3.0;
    float b=sum1/3.0;
    printf("\n AVERAGE TURN AROUND TIME IS : %f",a);
    printf("\n AVERAGE WAITING TIME IS     : %f",b);

}



