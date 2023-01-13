struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};

void insertFB(struct nodeFB **start, int id, int age){
	struct nodeFB *new_node, *ptr;
	new_node=(struct nodeFB*)malloc(sizeof(struct nodeFB));
	new_node -> id = id;
	new_node -> age = age;
	new_node -> next = NULL;
	if(*start==NULL){
		*start=new_node;
		}
	else{
		ptr=*start;
		while(ptr->next!=NULL){
			ptr=ptr->next;
			}
		ptr->next=new_node;
		}
	int count=0;
	int i, j, a, b;
	ptr=*start;
	while(ptr->next!=NULL){
		count++;
		ptr=ptr->next;
		}
		
	ptr=*start;
	for(i=0;i<count;i++){					//sort
		ptr=*start;
		for(j=0;j<count-i;j++){
			if((ptr->id)>((ptr->next)->id)){
				a=ptr->id; b=ptr->age;
				ptr->id=ptr->next->id; ptr->age=ptr->next->age;
				ptr->next->id=a; ptr->next->age=b;
				}
			ptr=(ptr->next);
			}
		}
	}
	
void insertGS(struct nodeGS **start, int id){
	struct nodeGS *new_node, *ptr;
	new_node=(struct nodeGS*)malloc(sizeof(struct nodeGS));
	new_node -> id = id;
	new_node -> next = NULL;
	if(*start==NULL){
		*start=new_node;
		}
	else{
		ptr=*start;
		while(ptr->next!=NULL){
			ptr=ptr->next;
			}
		ptr->next=new_node;
		}
	int count=0;
	int i, j, a;
	ptr=*start;
	while(ptr->next!=NULL){
		count++;
		ptr=ptr->next;
		}
		
	ptr=*start;
	for(i=0;i<count;i++){					//sort
		ptr=*start;
		for(j=0;j<count-i;j++){
			if((ptr->id)<((ptr->next)->id)){
				a=ptr->id;
				ptr->id=ptr->next->id;
				ptr->next->id=a;
				}
			ptr=(ptr->next);
			}
		}
	}

void printFB(struct nodeFB *start){
	
	struct nodeFB *ptr;
	ptr=start;
	while(ptr!=NULL){
		printf("%d %d\n", ptr->id, ptr->age);
		ptr = ptr->next;
		}
	puts("");
	}

void printGS(struct nodeGS *start){
	struct nodeGS *ptr;
	ptr=start;
	while(ptr!=NULL){
		printf("%d\n", ptr->id);
		ptr = ptr->next;
		}
	}

void createFinalList(struct newNodeFB **start, struct nodeFB *startfb, struct nodeGS *startgs){
	struct newNodeFB *new_nodefb;
	struct newNodeGS *new_nodegs;
	new_nodegs=(struct newNodeGS*)malloc(sizeof(struct newNodeGS));
	new_nodegs->id=-1;
	while(startgs!=NULL){
		new_nodefb=(struct newNodeFB*)malloc(sizeof(struct newNodeFB));
		if(*start==NULL){
			*start=new_nodefb;
			}
		new_nodefb->id=startfb->id;
		new_nodefb->age=startfb->age;
		if(new_nodegs->id!=-1){
			new_nodegs->next=new_nodefb;
			}
		new_nodegs=(struct newNodeGS*)malloc(sizeof(struct newNodeGS));
		new_nodefb->next=new_nodegs;
		new_nodegs->id=startgs->id;
		new_nodegs->next=NULL;
		startfb=startfb->next;
		startgs=startgs->next;
		}
	}

void printAll(struct newNodeFB *start){
	struct newNodeFB *ptr;
	ptr=start;
	while(ptr!=NULL){
		printf("\n%d %d\n%d", ptr->id, ptr->age,ptr->next->id);
		ptr = ptr->next->next;
		}
	puts("");
	}

// You must write all the function definitions to be used in this lab into this file. 
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.



