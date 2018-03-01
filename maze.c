#include<stdio.h>
int h,w;
char s[502][502];		// ���H�̊e�}�X
int reached[502][502];		// ���B���Ă��Ȃ�:0,���B:1
int si,sj,gi,gj;
int i,j;

void search(int x,int y){
	
	if(x<0||x>=h||y<0||y>=w||s[x][y]=='#') return;
	
	if(reached[x][y]) return;
	
	reached[x][y]=1;
	
	search(x+1,y);		// �E
	search(x-1,y);		// ��
	search(x,y+1);		// ��
	search(x,y-1);		// ��
	
}

int main(void){
	
	for(i=0;i<=502;i++){
		for(j=0;j<=502;j++){
			reached[i][j]=0;
		}
	}
	
	scanf("%d %d",&h,&w);
	for(i=0;i<=h-1;i++){		// ��s���Ƃ�
		scanf("%s",&s[i]);		// ���H�̓ǂݍ���
		for(j=0;j<=w-1;j++){	// ��}�X���Ƃ�
			if(s[i][j]=='s'){	// �X�^�[�g�̃}�X
				si=i;
				sj=j;
			}
			if(s[i][j]=='g'){	// �S�[���̃}�X
				gi=i;
				gj=j;
			}
		}
	}
	
	search(si,sj);		// �X�^�[�g�̃}�X����T�����J�n
	
	if(reached[gi][gj]){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}

