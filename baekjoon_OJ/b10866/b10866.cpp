#include <string.h>
#include <stdio.h>
#include <deque>
using namespace std;

deque<int> dq;
int n=0,num=0;
char str[20]={0};

int main(){
	scanf("%d",&n);
	fgetc(stdin);
	for(int i=0;i<n;++i){
		scanf("%s",str);
		fgetc(stdin);
		if(!strcmp(str,"push_front")){
			scanf("%d",&num);
			fgetc(stdin);
			dq.push_front(num);
		}
		else if(!strcmp(str,"push_back")){
			scanf("%d",&num);
			fgetc(stdin);
			dq.push_back(num);
		}
		else if(!strcmp(str,"pop_front")){
			if(dq.empty())
				printf("-1\n");
			else{
				printf("%d\n",dq.front());
				dq.pop_front();
			}
		}
		else if(!strcmp(str,"pop_back")){
			if(dq.empty())
				printf("-1\n");
			else{
				printf("%d\n",dq.back());
				dq.pop_back();
			}
		}
		else if(!strcmp(str,"size")){
			printf("%d\n",dq.size());
		}
		else if(!strcmp(str,"empty")){
			printf("%d\n",dq.empty());
		}
		else if(!strcmp(str,"front")){
			if(dq.empty())
				printf("-1\n");
			else
				printf("%d\n",dq.front());
		}
		else if(!strcmp(str,"back")){
			if(dq.empty())
				printf("-1\n");
			else
				printf("%d\n",dq.back());
		}
	}
	return 0;
}