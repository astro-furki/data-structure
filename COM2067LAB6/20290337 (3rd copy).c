#include <stdio.h>
#include <stdlib.h>

int level=0;
int prev=-1;
int holder=-1;

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
		printf("%d\n", root->num);
		inorder(root->righ_child);
		}
	}
	
void make_avl(struct node *root){
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
	}
	
struct node *pbp(struct node *root){
	struct node *ptr;
	while(balance_factor(root)==2 || balance_factor(root)==-2){
		if(balance_factor(root->left_child)==2 || balance_factor(root->left_child)==-2){
			ptr=root;
			root=root->left_child;
			}
		else if(balance_factor(root->righ_child)==2 || balance_factor(root->righ_child)==-2){
			ptr=root;
			root=root->righ_child;
			}
		}
	return ptr;
	}
	
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
			if(holder>root->num){printf("L) (%d B)",balance_factor(root));}else{printf("R) (%d B)",balance_factor(root));}
			}
		listmaker(root->righ_child,a);
		}
	level--;
	}
	
int main(){
	int a, b, i;
	struct node *ptr;
	scanf("%d",&a);
	while(a!=-1){
		insert(&start,a);
		inorder(start);
	puts("");
	int max = height(start);
	for(i=1;i<max+1;i++){
		prev=-1;
		listmaker(start,i);
		puts("");
		}
	puts("");
		/*if(start->left_child!=NULL){
			make_avl(start->left_child);
			}
		if(start->righ_child!=NULL){
			make_avl(start->righ_child);
			}*/
		b = balance_factor(start);
		
		/*if(b==2 || b==-2){
			ptr=pbp(start);
			if(balance_factor(ptr->righ_child)==2){
				if(balance_factor(ptr->righ_child->left_child)==1){
					ptr->righ_child=ll_rotation(ptr->righ_child);
					}
				}
			}*/
		
		if(b>1){
			if(balance_factor(start->left_child)==-1){
				start=lr_rotation(start);
				}
			else{
				start=ll_rotation(start);
				}
			}
		if(b<-1){
			if(balance_factor(start->righ_child)==1){
				start=rl_rotation(start);
				}
			else{
				start=rr_rotation(start);
				}
			}
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
