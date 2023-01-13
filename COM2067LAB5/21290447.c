#include <stdio.h>
#include <stdlib.h>

int level=0;
int total=0;
int holder=-1;
int prev=-1;
int reach=0;

struct node{
	int num, mark;
	struct node *righ_child;
	struct node *left_child;
	};
	
struct node *start = NULL;
	
void insert(struct node **start, int a, int b){
	if(*start==NULL){
		struct node *new_node;
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->num=a;
		new_node->mark=b;
		new_node->righ_child=NULL;
		new_node->left_child=NULL;
		*start=new_node;
		}
	else if(b>(*start)->mark)
		insert(&((*start)->righ_child), a, b);
	else
		insert(&((*start)->left_child), a, b);
	}

void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left_child);
		printf("%d %d\n", root->num, root->mark);
		inorder(root->righ_child);
		}
	}

/*int find_max(struct node *root){
	level++;
	if(root!=NULL){
		if(level>max)
			max=level;
		find_max(root->left_child);
		find_max(root->righ_child);
		}
	level--;
	return max;
	}
	
void listmaker(struct node *root, int a){
	level++;
	if(root!=NULL){
		if(level==a-1){
			holder=root->mark;
			}
		listmaker(root->left_child,a);
		if(level==a){
			if(prev!=-1){
				printf(" ");
				}
			printf("%d %d", root->num, root->mark);
			}
		if(holder!=-1&&level==a){
			printf(" (%d ", holder);
			prev=holder;
			if(holder>root->mark){printf("L)");}else{printf("R)");}
			}
		listmaker(root->righ_child,a);
		}
	level--;
	}*/
	
void calc(struct node *root){
	if(root!=NULL){
		total++;
		calc(root->left_child);
		calc(root->righ_child);
		}
	}
	
void inarr(struct node *root, int a, int b, int arr[][b]){
	level++;
	if(root!=NULL){
		arr[reach][0]=root->num;
		arr[reach][1]=root->mark;
		arr[reach][2]=level;
		reach++;
		inarr(root->left_child,a,b,arr);
		inarr(root->righ_child,a,b,arr);
		}
		level--;
	}
	
int main(){
	int a,b,i;
	scanf("%d",&a);
	while(a!=-1){
		scanf("%d",&b);
		insert(&start,a,b);
		scanf("%d",&a);
		}
	//max=find_max(start);
	inorder(start);
	calc(start);
	puts("");
	//printf("%d",total);
	
	int arr[total][3];
	inarr(start, total, 3, arr);
	for(i=0;i<total;i++){
		printf("%d %d %d\n",arr[i][0],arr[i][1],arr[i][2]);
		}
	
	
	
	
	/*for(i=1;i<max+1;i++){
		prev=-1;
		listmaker(start,i);
		puts("");
		}*/
	}
