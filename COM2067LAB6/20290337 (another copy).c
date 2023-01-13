#include <stdio.h>
#include <stdlib.h>

int level=0;
int prev=-1;
int holder=-1;
int pos=0;

struct node{
	int num;
	struct node *righ_child;
	struct node *left_child;
	};

struct node *start = NULL;

void insert(struct node **start, int a){
	if(*start==NULL){
		struct node *new_node;
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->num=a;
		new_node->righ_child=NULL;
		new_node->left_child=NULL;
		*start=new_node;
		}
	else if(a>(*start)->num)
		insert(&((*start)->righ_child), a);
	else
		insert(&((*start)->left_child), a);
	}

int height(struct node *start){
	if(start==NULL){
		return 0;
		}
	else{
		int left_height = height(start->left_child);
		int righ_height = height(start->righ_child);
		if(left_height>righ_height){
			return left_height+1;
			}
		else{
			return righ_height+1;
			}
		}
	}

int balance_factor(struct node *root){
	return height(root->left_child)-height(root->righ_child);
	}

struct node *lr_rotation(struct node *root){
	struct node *holder = root->left_child;
	root->left_child = holder->righ_child->righ_child;
	holder->righ_child->righ_child = root;
	root = holder->righ_child;
	holder->righ_child = root->left_child;
	root->left_child = holder;
	return root;
	}
	
struct node *rl_rotation(struct node *root){
	struct node *holder = root->righ_child;
	root->righ_child = holder->left_child->left_child;
	holder->left_child->left_child = root;
	root = holder->left_child;
	holder->left_child = root->righ_child;
	root->righ_child = holder;
	return root;
	}
	
struct node *ll_rotation(struct node *root){
	struct node *holder = root->left_child;
	root->left_child = holder->righ_child;
	holder->righ_child = root;
	root = holder;
	return root;
	}
	
struct node *rr_rotation(struct node *root){
	struct node *holder = root->righ_child;
	root->righ_child = holder->left_child;
	holder->left_child = root;
	root = holder;
	return root;
	}
	
void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left_child);
		printf("%d ||%d||\n", root->num, balance_factor(root));
		inorder(root->righ_child);
		}
	}

struct node *make_balance(struct node *root){
	if(root!=NULL){
		make_balance(root->left_child);
		make_balance(root->righ_child);
		if(balance_factor(root)==2 || balance_factor(root)==-2){
			if(pos==0){
				pos = 1;
				return root;
				}
			}
		}
	}
	
/*void make_avl(struct node *root){
	if(root!=NULL){
		struct node *ptr;
		make_avl(root->left_child);
		make_avl(root->righ_child);
		int i=balance_factor(root);
		if(i>1){
			if(balance_factor(root->left_child)==-1){
				root=lr_rotation(root);
				}
			else{
				root=ll_rotation(root);
				}
			}
		if(i<-1){
			if(balance_factor(root->righ_child)==1){
				root=rl_rotation(root);
				}
			else{
				root=rr_rotation(root);
				}
			}
		}
	}*/
	
void listmaker(struct node *root, int a){
	level++;
	if(root!=NULL){
		if(level==a-1){
			holder=root->num;
			}
		listmaker(root->left_child,a);
		if(level==a){
			if(prev!=-1){
				printf(" ");
				}
			printf("%d", root->num);
			}
		if(holder!=-1&&level==a){
			printf(" (%d ", holder);
			prev=holder;
			if(holder>root->num){printf("L)");}else{printf("R)");}
			}
		listmaker(root->righ_child,a);
		}
	level--;
	}
	
int main(){
	int a, i, state;
	state=0;
	struct node *ptr;
	scanf("%d",&a);
	while(a!=-1){
		insert(&start,a);
		pos=0;
		ptr = make_balance(start);
		if(ptr==start){
			state=1;
			}
		printf("\naaa\n");
		printf("%d\n",ptr->num);
		printf("\naaa\n");
		/*if(balance_factor(ptr)==2){
			printf("\naaa\n");
			if(balance_factor(ptr->left_child)==1){
				printf("\naaa\n");
				ptr=ll_rotation(ptr);
				printf("\naaa\n");
				}
			else{
				printf("\naaa\n");
				ptr=lr_rotation(ptr);
				printf("\naaa\n");
				}
			}
		if(balance_factor(ptr)==-2){
			printf("\naaa\n");
			if(balance_factor(ptr->righ_child)==-1){
				printf("\naaa\n");
				ptr=rr_rotation(ptr);
				printf("\naaa\n");
				}
			else{
				printf("\naaa\n");
				ptr=rl_rotation(ptr);
				printf("\naaa\n");
				}
			}*/
		/*if(state=1){
			start=ptr;
			state=0;
			}*/
		scanf("%d",&a);
		}
	
	inorder(start);
	puts("");
	int max = height(start);
	for(i=1;i<max+1;i++){
		prev=-1;
		listmaker(start,i);
		puts("");
		}
	puts("");
	}
