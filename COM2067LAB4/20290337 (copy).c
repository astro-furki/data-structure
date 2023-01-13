#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int id, start, end;
	struct queue *next;
};

struct stack
{
	int id;
	struct stack *next;
};

void insertqueue(struct queue **start_q, int id, int start, int end){
	struct queue *new_node, *ptr;
	new_node=(struct queue*)malloc(sizeof(struct queue));
	new_node -> id = id;
	new_node -> start = start;
	new_node -> end = end;
	new_node -> next = NULL;
	if(*start_q==NULL){
		*start_q=new_node;
		}
	else{
		ptr=*start_q;
		while(ptr->next!=NULL){
			ptr=ptr->next;
			}
		ptr->next=new_node;
		}
	}
	
void createstack(struct stack **start_s){
	int i;
	struct stack *new_node, *ptr;
	new_node=(struct stack*)malloc(sizeof(struct stack));
	new_node -> next = NULL;
	*start_s=new_node;
	ptr=*start_s;
	for(i=0;i<5;i++){
		new_node=(struct stack*)malloc(sizeof(struct stack));
		new_node -> next = NULL;
		ptr->next=new_node;
		ptr=ptr->next;
		}
	}

struct queue *start_q = NULL;
struct stack *start_s = NULL;

int main()
{
	int i, j, employee, time, min;
	int desk[6][2]={0,0,0,0,0,0,0,0,0,0,0,0};
	struct queue *ptrq, *newnq;
	struct stack *ptrs, *newns;
	createstack(&start_s);			//create stack
	for(i=1;i<7;i++){				//puts employees in the stack
		ptrs=start_s;
		for(j=0;j<6-i;j++){
			ptrs=ptrs->next;
			}
		ptrs->id=i;
		}
		
	int total[]={0,0,0,0,0,0,0};
	int a, b, c;
	scanf("%d", &a);
	while(a!=-1){					//insert queue		
		scanf("%d", &b);
		scanf("%d", &c);
		insertqueue(&start_q, a, b, c);
		scanf("%d", &a);
		}
	ptrq=start_q;
	ptrs=start_s;
	while(start_q!=NULL){
		if(start_s!=NULL){
			for(i=1;i<start_q->start+1;i++){
				for(j=0;j<6;j++){
					if(desk[j][1]==i){
						newns=(struct stack*)malloc(sizeof(struct stack));
						newns->id=j+1;
						newns->next=start_s;
						start_s=newns;
						desk[j][1]=0;
						}
					}
				}
			printf("%d %d %d %d 0\n",start_q->id,start_s->id,start_q->start,start_q->start+start_q->end);
			employee=start_s->id;
			start_s=start_s->next;
			desk[employee-1][0]=start_q->start;
			desk[employee-1][1]=start_q->start+start_q->end;
			total[employee]+=start_q->end;
			start_q=start_q->next;
			}
		else{
			time=0;
			min=100;
			for(i=0;i<6;i++){
				if(desk[i][1]<min){
					min=desk[i][1];
					}
				}
			time=min-start_q->start;
			start_q->start+=time;
			for(i=1;i<start_q->start+1;i++){
				for(j=0;j<6;j++){
					if(desk[j][1]==i){
						newns=(struct stack*)malloc(sizeof(struct stack));
						newns->id=j+1;
						newns->next=start_s;
						start_s=newns;
						desk[j][1]=0;
						}
					}
				}
			printf("%d %d %d %d %d\n",start_q->id,start_s->id,start_q->start,start_q->start+start_q->end,time);
			employee=start_s->id;
			start_s=start_s->next;
			desk[employee-1][0]=start_q->start;
			desk[employee-1][1]=start_q->start+start_q->end;
			total[employee]+=start_q->end;
			start_q=start_q->next;
			}
		}
	for(i=6;i>0;i--){
		printf("\n%d %d",i,total[i]);
		}
	puts("");
}
