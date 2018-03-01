#include<stdio.h>
int h,w;
char s[502][502];		// 迷路の各マス
int reached[502][502];		// 到達していない:0,到達:1
int si,sj,gi,gj;
int i,j;

void search(int x,int y){
	
	if(x<0||x>=h||y<0||y>=w||s[x][y]=='#') return;
	
	if(reached[x][y]) return;
	
	reached[x][y]=1;
	
	search(x+1,y);		// 右
	search(x-1,y);		// 左
	search(x,y+1);		// 上
	search(x,y-1);		// 下
	
}

int main(void){
	
	for(i=0;i<=502;i++){
		for(j=0;j<=502;j++){
			reached[i][j]=0;
		}
	}
	
	scanf("%d %d",&h,&w);
	for(i=0;i<=h-1;i++){		// 一行ごとに
		scanf("%s",&s[i]);		// 迷路の読み込み
		for(j=0;j<=w-1;j++){	// 一マスごとに
			if(s[i][j]=='s'){	// スタートのマス
				si=i;
				sj=j;
			}
			if(s[i][j]=='g'){	// ゴールのマス
				gi=i;
				gj=j;
			}
		}
	}
	
	search(si,sj);		// スタートのマスから探索を開始
	
	if(reached[gi][gj]){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}

