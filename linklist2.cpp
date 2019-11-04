#include <bits/stdc++.h>
using namespace std;

struct coordinate{
	int x;
	struct coordinate* next;
};

void AddFirst(int a,struct coordinate** headptr){
	if(*headptr == NULL){
		*headptr = new coordinate();
		(*headptr)->x = a;
		(*headptr)->next = NULL;
	}
	else{
		coordinate* temp = new coordinate();
		temp->x =a;
		temp->next = *headptr;
		*headptr = temp;
	}

}

void DelFirst(struct coordinate** headptr){
	if(*headptr == NULL){
		cout<<"-1"<<"\n";
	}
	else{
		coordinate* temp = *headptr;
    	*headptr = temp->next;
    	free(temp);
	}
} 

void Del(int a,int b,struct coordinate** headptr){
	coordinate* temp = *headptr;
	coordinate* temp_ = NULL; 
	int flag =0;
	while(temp!=NULL){
		if(temp->x==a&&temp_!=NULL){
			temp_->next = temp->next;
			free(temp);
			flag =1;
		}
		else if(temp_ == NULL&&temp->x==a){
			DelFirst(headptr);
			flag =1;
		}
		else{
			temp_ = temp;
			temp = temp->next;
	}
	}
		if(flag ==0){
			cout<<"-1"<<"\n";
		}
}
void search(int a ,struct coordinate** headptr){
	coordinate* temp = *headptr;
	int flag = 0;
	while(temp!= NULL){
		if(temp->x==a){
			flag =1;
			break; 
		}
		else{
			temp = temp->next;
		}
	}
	if(flag==1){
		cout<<"True"<<"\n";
	}
	else{
		cout<<"False"<<"\n";
	}
}

int main(){
	coordinate* head = NULL;
	int condition;
	int T;
	cin>>T;
	while(T--){
		cin>>condition;
		if(condition==1){
			int a;
			cin>>a;
			AddFirst(a,&head);
		}
		else if(condition ==2){
			DelFirst(&head);
		}
		else if(condition == 3){
			int a;
			cin>>a;
			Del(a,&head);
		}
		else if(condition==4){
			int a;
			cin>>a;
			search(a,&head);
		}
	}
	return 0;
}
