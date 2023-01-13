#include <stdio.h>
#include <stdlib.h>

int level=0;
int prev=-1;
int holder=-1;

struct node{
	int num;
	char colour;
	struct node *parent;
	struct node *righ_child;
	struct node *left_child;
	};
	
struct node *start = NULL;
struct node *finder= NULL;

void insert(struct node **start, int a);
struct node *grand(struct node *n);
struct node *uncle(struct node *n);
void case1(struct node *n);
void case2(struct node *n);
void case3(struct node *n);
void case4(struct node *n);
void case5(struct node *n);
void rotate_left(struct node *n);
void rotate_right(struct node *n);
int height(struct node *start);
void inorder(struct node *root);
void listmaker(struct node *root, int a);
void parenter(struct node *root);

int main(){
	int a,i;
	scanf("%d",&a);
	while(a!=-1){
		insert(&start,a);
		scanf("%d",&a);
		}
	inorder(start);
	puts("");
	int max = height(start);
	printf("%d %c\n", start->num, start->colour);
	for(i=2;i<max+1;i++){
		prev=-1;
		listmaker(start,i);
		puts("");
		}
	}

void insert(struct node **start, int a){
	if(*start==NULL){
		struct node *new_node;
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->num=a;
		new_node->colour='R';
		new_node->parent=finder;
		new_node->righ_child=NULL;
		new_node->left_child=NULL;
		*start=new_node;
		case1(*start);
		}
	else if(a>(*start)->num){
		finder=*start;
		insert(&((*start)->righ_child), a);
		}
	else{
		finder=*start;
		insert(&((*start)->left_child), a);
		}
	}
	
struct node *grand(struct node *n){
	if((n!=NULL) && (n->parent!=NULL))
		return n->parent->parent;
	else
		return NULL;
	}
	
struct node *uncle(struct node *n){
	struct node *g;
	g=grand(n);
	if(g==NULL)
		return NULL;
	if(n->parent==g->left_child)
		return g->righ_child;
	else
		return g->left_child;
	}

void case1(struct node *n){
	if(n->parent==NULL)
		n->colour='B';
	else
		case2(n);
	}
	
void case2(struct node *n){
	if(n->parent->colour=='B')
		return;
	else
		case3(n);
	}

void case3(struct node *n){
	struct node *u, *g;
	u=uncle(n);
	g=grand(n);
	if((u!=NULL) && (u->colour=='R')){
		n->parent->colour='B';
		u->colour='B';
		g->colour='R';
		case1(g);
		}
	else{
		case4(n);
		}
	}
	
void rotate_right(struct node *n){
	struct node *x = n->left_child;
	n->left_child = x->righ_child;
	if(n->left_child)
		n->left_child->parent = n;
	x->parent = n->parent;
	if(!n->parent)
		start = x;
	else if(n==n->parent->left_child)
		n->parent->left_child = x;
	else
		n->parent->righ_child = x;
	x->righ_child = n;
	n->parent = x;
	}

void rotate_left(struct node *n){
	struct node *x = n->righ_child;
	n->righ_child = x->left_child;
	if(n->righ_child)
		n->righ_child->parent = n;
	x->parent = n->parent;
	if(!n->parent)
		start = x;
	else if(n==n->parent->righ_child)
		n->parent->righ_child = x;
	else
		n->parent->left_child = x;
	x->left_child = n;
	n->parent = x;
	}

void case4(struct node *n){
	struct node *g=grand(n);
	if((n==n->parent->righ_child) && (n->parent==g->left_child)){
		rotate_left(n->parent);
		n=n->left_child;
		}
	else if((n==n->parent->left_child) && (n->parent==g->righ_child)){
		rotate_right(n->parent);
		n=n->righ_child;
		}
	case5(n);
	}

void case5(struct node *n){
	struct node *g;
	g=grand(n);
	if((n==n->parent->left_child) && (n->parent==g->left_child))
		rotate_right(g);
	else if((n==n->parent->righ_child) && (n->parent==g->righ_child))
		rotate_left(g);
	n->parent->colour='B';
	g->colour='R';
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

void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left_child);
		printf("%d\n", root->num);
		inorder(root->righ_child);
		}
	}
	
void parenter(struct node *root){
	if(root!=NULL){
		root->righ_child->parent=root;
		root->left_child->parent=root;
		parenter(root->left_child);
		parenter(root->righ_child);
		}
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
			printf("%d %c ", root->num, root->colour);
			}
		if(holder!=-1&&level==a){
			prev=holder;
			if(root==root->parent->righ_child)
				printf("(%d R)",root->parent->num);
			else if(root==root->parent->left_child)
				printf("(%d L)",root->parent->num);
			}
		listmaker(root->righ_child,a);
		}
	level--;
	}
