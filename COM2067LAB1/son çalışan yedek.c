#include <stdio.h>

int main(){
	int xsize,ysize,x,y,a,i,j,changer,b,c;
	int count,asterisktotal,state=0;
	
	scanf("%d %d", &xsize, &ysize);			//create grid
	char grid[xsize+2][ysize+2];
	
	for(i=0; i<xsize+2; i++){				//fill grid with '0'
		for(j=0; j<ysize+2; j++){
			grid[i][j]='0';
			}
		}
	
	while(scanf("%d %d", &x, &y)!=-1){		//taking asterisks
		if(x!=-1 && y!=-1){
		grid[x+1][y+1]='*';
		asterisktotal++;}
		}
		
	int asterc[asterisktotal];
	for(i=0;i<asterisktotal;i++){asterc[i]=0;}
		
	j=0;
	for(a=0;a<asterisktotal;a++){			//counting blobs
		j=0;
		while(!(i==xsize && j==ysize)){
			i=1;
			j++;
			while(i<xsize+1){
				for(b=0;b<xsize+2;b++){
					for(c=0;c<ysize+2;c++){
						printf("%c",grid[b][c]);
						}
					puts("");
					}
				puts("");
				if(grid[i][j]=='*'){
					if(
					grid[i-1][j]!='1' && grid[i+1][j]!='1' &&
					grid[i][j-1]!='1' && grid[i][j+1]!='1' &&
					grid[i-1][j-1]!='1' && grid[i+1][j+1]!='1' &&
					grid[i-1][j+1]!='1' && grid[i+1][j-1]!='1'){
						count++;
						}
					asterc[count]++;		//asterisk count per blob
					grid[i][j]='1';
					if(
					grid[i-1][j]=='*' || grid[i+1][j]=='*' ||
					grid[i][j-1]=='*' || grid[i][j+1]=='*' ||
					grid[i-1][j-1]=='*' || grid[i+1][j+1]=='*' ||
					grid[i-1][j+1]=='*' || grid[i+1][j-1]=='*'){
						if(grid[i-1][j]=='*'){i=i-1;continue;}
						if(grid[i-1][j-1]=='*'){i--;j--;continue;}
						if(grid[i][j-1]=='*'){j=j-1;continue;}
						if(grid[i+1][j-1]=='*'){i++;j--;continue;}
						if(grid[i+1][j]=='*'){i=i+1;continue;}
						if(grid[i-1][j+1]=='*'){i--;j++;continue;}
						if(grid[i][j+1]=='*'){j=j+1;continue;}
						if(grid[i+1][j+1]=='*'){i++;j++;continue;}
						} else{state=1;break;}
					}
				
				i++;
				}
			if(state==1){state=0;break;}
			if(j>ysize){break;}
			}
		if(i==xsize && j==ysize){
			break;}
		}
	
	/*for(i=0;i<asterisktotal;i++){
		if(asterc[i]!=0){printf(" %d",asterc[i]);}
		}*/
	
	a=asterisktotal-1;
	for(i=0;i<a;i++){
		for(j=i;j<a-i;j++){
			if(asterc[j]>asterc[j+1]){
				changer=asterc[j];
				asterc[j]=asterc[j+1];
				asterc[j+1]=changer;
				}
			}
		}
	
	printf("%d",count);						//print result
	for(i=0;i<asterisktotal;i++){
		if(asterc[i]!=0){printf(" %d",asterc[i]);}
		}
	puts("");
	}
