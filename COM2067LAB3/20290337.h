struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};

void insert(struct nodeClass **head, int id, double midt){
	struct nodeClass *new_node, *ptr;
	int i, j, a, b, x;
	if(*head==NULL){
		new_node=(struct nodeClass*)malloc(sizeof(struct nodeClass));
		new_node->classID=1;
		new_node->studentPtr=NULL;
		*head=new_node;
		ptr=*head;
		for(i=2;i<5;i++){
			new_node=(struct nodeClass*)malloc(sizeof(struct nodeClass));
			ptr->next=new_node;
			ptr=ptr->next;
			new_node->classID=i;
			new_node->studentPtr=NULL;
			ptr->next=NULL;
			}
		}
		
	ptr=*head;
	if(id>=66000 && id<77000){
		while(ptr->classID!=1){
			ptr=ptr->next;
			}
		}
	if(id>=77000 && id<88000){
		while(ptr->classID!=2){
			ptr=ptr->next;
			}
		}
	if(id>=88000 && id<99000){
		while(ptr->classID!=3){
			ptr=ptr->next;
			}
		}
	if(id>=99000 && id<100000){
		while(ptr->classID!=4){
			ptr=ptr->next;
			}
		}
		
	struct nodeStudent *new_student, *ptrs;
	if(ptr->studentPtr==NULL){
		new_student=(struct nodeStudent*)malloc(sizeof(struct nodeStudent));
		new_student->studentID=id;
		new_student->midterm=midt;
		new_student->next=NULL;
		ptr->studentPtr=new_student;
		}
	else{
		ptrs=ptr->studentPtr;
		while(ptrs->next!=NULL){
			ptrs=ptrs->next;
			}
		new_student=(struct nodeStudent*)malloc(sizeof(struct nodeStudent));
		new_student->studentID=id;
		new_student->midterm=midt;
		new_student->next=NULL;
		ptrs->next=new_student;
		}
	}

int sum1,sum2,sum3,sum4,count1,count2,count3,count4;

void computeClassAverage(struct nodeClass *head){
	int count, holderId, holderMidt;
	int sum=0;
	struct nodeClass *ptr;
	struct nodeStudent *ptrs;
	ptr=head;
	while(ptr!=NULL){										//sort
		ptrs=ptr->studentPtr;
		count=0;
		while(ptrs->next!=NULL){count++;ptrs=ptrs->next;}
		if(ptr->classID==1){
			count1=count+1;
			}
		if(ptr->classID==2){
			count2=count+1;
			}
		if(ptr->classID==3){
			count3=count+1;
			}
		if(ptr->classID==4){
			count4=count+1;
			}
		ptrs=ptr->studentPtr;
		for(int i=0;i<count;i++){
			for(int j=0;j<count-i;j++){
				if(ptrs->midterm<ptrs->next->midterm){
					holderMidt=ptrs->midterm;
					holderId=ptrs->studentID;
					ptrs->midterm=ptrs->next->midterm;
					ptrs->studentID=ptrs->next->studentID;
					ptrs->next->midterm=holderMidt;
					ptrs->next->studentID=holderId;
					}
				if(ptrs->midterm==ptrs->next->midterm){
					if(ptrs->studentID>ptrs->next->studentID){
						holderId=ptrs->studentID;
						ptrs->studentID=ptrs->next->studentID;
						ptrs->next->studentID=holderId;
						}
					}
				ptrs=ptrs->next;
				}
			ptrs=ptr->studentPtr;
			}
		ptr=ptr->next;
		}
		
	ptr=head;
	while(ptr!=NULL){
		ptrs=ptr->studentPtr;
		sum=0;
		while(ptrs!=NULL){
			sum+=ptrs->midterm;
			ptrs=ptrs->next;
			}
		if(ptr->classID==1){
			sum1=sum;
			}
		if(ptr->classID==2){
			sum2=sum;
			}
		if(ptr->classID==3){
			sum3=sum;
			}
		if(ptr->classID==4){
			sum4=sum;
			}
		ptr=ptr->next;
		}
	}
	
void printAll(struct nodeClass *head){
	struct nodeClass *ptr;
	struct nodeStudent *ptrs;
	ptr=head;
	do{
		ptrs=ptr->studentPtr;
		printf("%d", ptr->classID);
		if(ptr->classID==1){
			printf(" %.2f\n", (float)sum1/(float)count1);
			}
		if(ptr->classID==2){
			printf(" %.2f\n", (float)sum2/(float)count2);
			}
		if(ptr->classID==3){
			printf(" %.2f\n", (float)sum3/(float)count3);
			}
		if(ptr->classID==4){
			printf(" %.2f\n", (float)sum4/(float)count4);
			}
		while(ptrs->next!=NULL){
			printf("%d %d\n", ptrs->studentID, ptrs->midterm);
			ptrs=ptrs->next;
			}
		printf("%d %d\n", ptrs->studentID, ptrs->midterm);
		ptr=ptr->next;
		}while(ptr!=NULL);
	}

// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.



