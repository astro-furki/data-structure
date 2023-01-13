#include <stdio.h>

int main(){
	int size_x, size_y, i, j, x, y, blob_size, mem_x, mem_y;
	int count,state=0;
	scanf("%d %d", &size_x, &size_y);	//size of grid
	char grid[size_x+2][size_y+2];
	
	for(i=0; i<size_x+2; i++){			//loop fill with "0"
		for(j=0; j<size_y+2; j++){
			grid[i][j]='0';
			}
		}
		
	while(scanf("%d %d", &x, &y)!=-1){
		grid[x+1][y+1]='*';
		}
	i=1;
	j=1;
	while(i<size_x+1){
		while(j<size_y+1){
			if(grid[i][j]=='*'){
				if(
				grid[i-1][j]!='1' && grid[i+1][j]!='1' &&
				grid[i][j-1]!='1' && grid[i][j+1]!='1' &&
				grid[i-1][j-1]!='1' && grid[i+1][j+1]!='1' &&
				grid[i-1][j+1]!='1' && grid[i+1][j-1]!='1'){
					count++;
					}
				grid[i][j]='1';
				if(
				grid[i-1][j]=='*' || grid[i+1][j]=='*' ||
				grid[i][j-1]=='*' || grid[i][j+1]=='*' ||
				grid[i-1][j-1]=='*' || grid[i+1][j+1]=='*' ||
				grid[i-1][j+1]=='*' || grid[i+1][j-1]=='*'){
					mem_x=i;
					mem_y=j;
					if(grid[i+1][j]!='*'){i=i+1;}
					if(grid[i-1][j]!='*'){i=i-1;}
					if(grid[i][j-1]!='*'){j=j-1;}
					if(grid[i][j+1]!='*'){j=j+1;}
					if(grid[i-1][j-1]!='*'){i--;j--;}
					if(grid[i-1][j+1]!='*'){i--;j++;}
					if(grid[i+1][j-1]!='*'){i++;j--;}
					if(grid[i+1][j+1]!='*'){i++;j++;}
					state=1;
					}
				}
			if(state!=1){j++;}
			}
		j=1;
		if(state!=1){i++;}
		if(state==1){i=mem_x+1;j=mem_y;state=0;}
		}
	printf("%d",count);
		
	/*for(j=1; j<size_y+1; j++){						//algoritma şekilde altı atlıyor
		for(i=1; i<size_x+1; i++){
			if(grid[i][j]=='*'){
				if(
				grid[i-1][j]!='1' && grid[i+1][j]!='1' &&
				grid[i][j-1]!='1' && grid[i][j+1]!='1' &&
				grid[i-1][j-1]!='1' && grid[i+1][j+1]!='1' &&
				grid[i-1][j+1]!='1' && grid[i+1][j-1]!='1'){
					count++;
					}
				grid[i][j]='1';
				}
			}
		}
	printf("%d",count);*/
	
	
	/*for(i=0;i<size_x;i++){			//control loop
		for(j=0;j<size_y;j++){
			printf("%c ",grid[i][j]);
			}
		printf("\n");
		}*/
	
	return 0;
	}
