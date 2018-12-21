#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;
char search_manu(){
	char inp;
	cout<<"\t\t\t----------Search Selection ----------"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Key \t Function"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"I \t Search by ID"<<endl;
	cout<<"N \t Search by Name"<<endl;
	cout<<"A \t Search by Author"<<endl;
	cout<<"P \t Search by Publisher"<<endl;
	cout<<"R \t Search by released year"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Enter Key ::"<<endl;
	cin>>inp;
	return inp;
}
char show_ur_en(){
	char inp;
	cout<<"\t\t\t----------Select Languange----------"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Key \t Function"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"U \t Urdu"<<endl;
	cout<<"E \t English"<<endl;
	cout<<"B \t Both"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Enter Key ::"<<endl;
	cin>>inp;
	return inp;
}
char book_lgs(){
	char inp;
	cout<<"\t\t\t----------Languange Selection ----------"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Key \t Function"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"U \t Urdu"<<endl;
	cout<<"E \t English"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Enter Key ::"<<endl;
	cin>>inp;
	return inp;
}
char manu(){
	char inp;
	cout<<"\t\t\t----------Welcome to library----------"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Key \t Function"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"A \t Admin side"<<endl;
	cout<<"U \t User side"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Enter Key ::";
	cin>>inp;
	return inp;
}
char admin_manu(){
	char inp;
	cout<<"\t\t\t----------Welcome_ADMIN----------"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Key \t Function"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"E \t Enter new book"<<endl;
	cout<<"S \t Show all Book's"<<endl;
	cout<<"x \t Search Book's"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Enter Key ::";
	cin>>inp;
	return inp;
}
char user_manu(){
	char inp;
	cout<<"\t\t\t----------Welcome_USER----------"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Key \t Function"<<endl;
	cout<<"-----------------"<<endl;
		cout<<"S \t Show all Book's"<<endl;
	cout<<"x \t Search Book's"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Enter Key ::";
	cin>>inp;
	return inp;
}
char user_id_pass(){
	char inp;
	cout<<"\t\t\t----------Welcome_USER----------"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Key \t Function"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"L \t Login"<<endl;
	cout<<"S \t Sign Up"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Enter Key ::";
	cin>>inp;
	return inp;
}
class book{
	protected:
		int Bo_id;
		string Bo_name;
		string Au_name;
		string Pu_name;
		string ty_name;
		int ye_book;
	public:
		virtual void setBo_id(){
			cout<<"Enter BOOK_ID ::";
			cin>>Bo_id;	
		}
		int getBo_id(){
			return Bo_id;
		}
		virtual void setBo_name(){
			cin.ignore();
			cout<<"Enter BOOK_NAME ::";
			getline(cin,Bo_name);
			int temp;
			for(int x=0;Bo_name[x];x++){
				if(Bo_name[x]>=65&&Bo_name[x]<=90){
					temp=Bo_name[x];
					temp+=32;
					Bo_name[x]=temp;
					}
			}
				}
		string getBo_name(){
			return Bo_name;
		}
		virtual void setAu_name(){
			cout<<"Enter AUTHOR_NAME ::";
			getline(cin,Au_name);
			int temp;
			for(int x=0;Au_name[x];x++){
				if(Au_name[x]>=65&&Au_name[x]<=90){
					temp=Au_name[x];
					temp+=32;
					Au_name[x]=temp;
					}
			}
		}
		string getAu_name(){
			return Au_name;
		}
		virtual void setPu_name(){
			cout<<"Enter PUBLISHER_NAME ::";
			getline(cin,Pu_name);
			int temp;
			for(int x=0;Pu_name[x];x++){
				if(Pu_name[x]>=65&&Pu_name[x]<=90){
					temp=Pu_name[x];
					temp+=32;
					Pu_name[x]=temp;
					}
			}
		}
		string getPu_name(){
			return Pu_name;
		}
		virtual void setty_name(){
			cout<<"Enter BOOK_TYPE ::";
			getline(cin,ty_name);
			int temp;
			for(int x=0;ty_name[x];x++){
				if(ty_name[x]>=65&&ty_name[x]<=90){
					temp=ty_name[x];
					temp+=32;
					ty_name[x]=temp;
					}
			}
		}
		string getty_name(){
			return ty_name;
		}
		virtual void setye_book(){
			cout<<"Enter RELEASE_YEAR ::";
			cin>>ye_book;
			if(ye_book>999&&ye_book<10000){
			}else{
				cout<<"invalid year "<<endl;
				cout<<"....press any key to enter again....";
				getch();
				setye_book();
			}
		}
		int getye_book(){
			return ye_book;
		}
		void sho(){
			cout<<"BOOK_ID :: "<<Bo_id<<endl;
			cout<<"BOOK_NAME :: "<<Bo_name<<endl;
			cout<<"AUTHOR_NAME :: "<<Au_name<<endl;
			cout<<"PUBLISHER_NAME ::"<<Pu_name<<endl;
			cout<<"BOOK_TYPE ::"<<ty_name<<endl;
			cout<<"RELEASED_YEAR ::"<<ye_book<<endl;
		}
};
class urdu : public book{
	private:
	public:
		urdu* pre;
		urdu* next;
		ofstream u_write;
		void setBo_id(){
			book::setBo_id();
		}
		void setBo_name(){
			book::setBo_name();
		}
		void setAu_name(){
			book::setAu_name();
			u_write.open("urdu.csv",ios::app);
			u_write<<","<<Au_name;
			u_write.close();
		}
		void setPu_name(){
			book::setPu_name();
			u_write.open("urdu.csv",ios::app);
			u_write<<","<<Pu_name;
			u_write.close();
		}
		void setty_name(){
			book::setty_name();
			u_write.open("urdu.csv",ios::app);
			u_write<<","<<ty_name;
			u_write.close();
		}
		void setye_book(){
			book::setye_book();
			u_write.open("urdu.csv",ios::app);
			u_write<<","<<ye_book;
			u_write<<endl;
			u_write.close();
		}
		void showBOOK(){
			sho();
		}
};
class english : public book{
	private:
	public:
		english* pre;
		english* next;
		ofstream e_write;
		void setBo_id(){
			book::setBo_id();
		}
		void setBo_name(){
			book::setBo_name();
		}
		void setAu_name(){
			book::setAu_name();
			e_write.open("english.csv",ios::app);
			e_write<<","<<Au_name;
			e_write.close();
		}
		void setPu_name(){
			book::setPu_name();
			e_write.open("english.csv",ios::app);
			e_write<<","<<Pu_name;
			e_write.close();
		}
		void setty_name(){
			book::setty_name();
			e_write.open("english.csv",ios::app);
			e_write<<","<<ty_name;
			e_write.close();
		}
		void setye_book(){
			book::setye_book();
			e_write.open("english.csv",ios::app);
			e_write<<","<<ye_book;
			e_write<<endl;
			e_write.close();
		}
		void showBOOK(){
			sho();
		}
};
int Dublicate_id(english *e_head,urdu *u_head,int se){
	int noti=1;
	english *root_e=e_head;
	urdu *root_u=u_head;
	while(root_e!=NULL||root_u!=NULL){
		while(root_e){
		if(root_e->getBo_id()==se){
			root_e->showBOOK();
			noti=0;
			break;
			}
		root_e=root_e->next;
		}
		while(root_u){
		if(root_u->getBo_id()==se){
			root_u->showBOOK();
			noti=0;
			break;
			}
		root_u=root_u->next;
		}
		if(noti==0){
			break;
		}
	}
	if(noti){
			return 1;
		}else{
			return 0;
		}
}
void search_id_u(urdu *head){
	int se;
	int noti=1;
	cout<<"Enter ID ::";
	cin>>se;
	urdu *root=head;
	while(root){
		if(root->getBo_id()==se){
			root->showBOOK();
			noti=0;
			break;
		}else{
			noti=1;
		}
		root=root->next;
		}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_id_e(english *head){
	int se;
	int noti=1;
	cout<<"Enter ID ::";
	cin>>se;
	english *root=head;
	while(root){
		if(root->getBo_id()==se){
			root->showBOOK();
			noti=0;
			break;
		}else{
			noti=1;
		}
		root=root->next;
		}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_id_b(english *e_head,urdu *u_head){
	int se;
	int noti=1;
	cout<<"Enter ID ::";
	cin>>se;
	english *root_e=e_head;
	urdu *root_u=u_head;
	while(root_e!=NULL||root_u!=NULL){
		while(root_e){
		if(root_e->getBo_id()==se){
			root_e->showBOOK();
			noti=0;
			break;
			}
		root_e=root_e->next;
		}
		while(root_u){
		if(root_u->getBo_id()==se){
			root_u->showBOOK();
			noti=0;
			break;
			}
		root_u=root_u->next;
		}
		if(noti==0){
			break;
		}
	}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
int doublicate_name(english *e_head,urdu *u_head,string se){
	int noti=1;
	english *root_e=e_head;
	urdu *root_u=u_head;
	while(root_e!=NULL||root_u!=NULL){
		while(root_e){
		if(root_e->getBo_name()==se){
			root_e->showBOOK();
			noti=0;
			break;
			}
		root_e=root_e->next;
		}
		while(root_u){
		if(root_u->getBo_name()==se){
			root_u->showBOOK();
			noti=0;
			break;
			}
		root_u=root_u->next;
		}
		if(noti==0){
			break;
		}
	}
	if(noti){
			return 1;
		}else{
			return 0;
		}
}
void search_name_u(urdu *head){
	string nam;
	int noti=1;
	cin.ignore();
	cout<<"Enter Book_Name ::";
	getline(cin,nam);
	int temp;
	if(nam[0]>=65&&nam[0]<=90){
		for(int x=0;nam[x];x++){
			if(nam[x]>=65&&nam[x]<=90){
				temp=nam[x];
				temp+=32;
				nam[x]=temp;
			}
		}
	}
	urdu *root=head;
	while(root){
		if(root->getBo_name()==nam){
			root->showBOOK();
			noti=0;
			break;
		}else{
			noti=1;
		}
		root=root->next;
		}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_name_e(english *head){
	string nam;
	int noti=1;
	cin.ignore();
	cout<<"Enter Book_Name ::";
	getline(cin,nam);
	int temp;
	if(nam[0]>=65&&nam[0]<=90){
		for(int x=0;nam[x];x++){
			if(nam[x]>=65&&nam[x]<=90){
				temp=nam[x];
				temp+=32;
				nam[x]=temp;
			}
		}
	}
	english *root=head;
	while(root){
		if(root->getBo_name()==nam){
			root->showBOOK();
			noti=0;
			break;
		}else{
			noti=1;
		}
		root=root->next;
		}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_name_b(english *e_head,urdu *u_head){
	string se;
	int noti=1;
	cout<<"Enter Book_Name ::";
	getline(cin,se);
	english *root_e=e_head;
	urdu *root_u=u_head;
	while(root_e!=NULL||root_u!=NULL){
		while(root_e){
		if(root_e->getBo_name()==se){
			root_e->showBOOK();
			noti=0;
			break;
			}
		root_e=root_e->next;
		}
		while(root_u){
		if(root_u->getBo_name()==se){
			root_u->showBOOK();
			noti=0;
			break;
			}
		root_u=root_u->next;
		}
		if(noti==0){
			break;
		}
	}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_author_u(urdu *head){
	string nam;
	int noti=1;
	cin.ignore();
	cout<<"Enter Author_Name ::";
	getline(cin,nam);
	int temp;
	if(nam[0]>=65&&nam[0]<=90){
		for(int x=0;nam[x];x++){
			if(nam[x]>=65&&nam[x]<=90){
				temp=nam[x];
				temp+=32;
				nam[x]=temp;
			}
		}
	}
	urdu *root=head;
	while(root){
		if(root->getAu_name()==nam){
			root->showBOOK();
			noti=0;
			break;
		}else{
			noti=1;
		}
		root=root->next;
		}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_author_e(english *head){
	int noti=1;
	string nam;
	cin.ignore();
	cout<<"Enter Author_Name ::";
	getline(cin,nam);
	int temp;
	if(nam[0]>=65&&nam[0]<=90){
		for(int x=0;nam[x];x++){
			if(nam[x]>=65&&nam[x]<=90){
				temp=nam[x];
				temp+=32;
				nam[x]=temp;
			}
		}
	}
	english *root=head;
	while(root){
		if(root->getAu_name()==nam){
			root->showBOOK();
			noti=0;
			break;
		}else{
			noti=1;
		}
		root=root->next;
		}
		if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_auther_b(english *e_head,urdu *u_head){
	string se;
	int noti=1;
	cout<<"Enter Author_Name ::";
	getline(cin,se);
	english *root_e=e_head;
	urdu *root_u=u_head;
	while(root_e!=NULL||root_u!=NULL){
		while(root_e){
		if(root_e->getAu_name()==se){
			root_e->showBOOK();
			noti=0;
			break;
			}
		root_e=root_e->next;
		}
		while(root_u){
		if(root_u->getAu_name()==se){
			root_u->showBOOK();
			noti=0;
			break;
			}
		root_u=root_u->next;
		}
		if(noti==0){
			break;
		}
	}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_publisher_u(urdu *head){
	int noti=1;
	string nam;
	cin.ignore();
	cout<<"Enter Publisher_Name ::";
	getline(cin,nam);
	int temp;
	if(nam[0]>=65&&nam[0]<=90){
		for(int x=0;nam[x];x++){
			if(nam[x]>=65&&nam[x]<=90){
				temp=nam[x];
				temp+=32;
				nam[x]=temp;
			}
		}
	}
	urdu *root=head;
	while(root){
		if(root->getPu_name()==nam){
			root->showBOOK();
			noti=0;
		}else{
			noti=1;
		}
		root=root->next;
		}
		if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_publisher_e(english *head){
	int noti=1;
	string nam;
	cin.ignore();
	cout<<"Enter Publisher_Name ::";
	getline(cin,nam);
	int temp;
	if(nam[0]>=65&&nam[0]<=90){
		for(int x=0;nam[x];x++){
			if(nam[x]>=65&&nam[x]<=90){
				temp=nam[x];
				temp+=32;
				nam[x]=temp;
			}
		}
	}
	english *root=head;
	while(root){
		if(root->getPu_name()==nam){
			root->showBOOK();
			noti=0;
		}else{
			noti=1;
		}
		root=root->next;
		}
		if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_publisher_b(english *e_head,urdu *u_head){
	string se;
	int noti=1;
	cout<<"Enter Publisher_Name ::";
	getline(cin,se);
	english *root_e=e_head;
	urdu *root_u=u_head;
	while(root_e!=NULL||root_u!=NULL){
		while(root_e){
		if(root_e->getPu_name()==se){
			root_e->showBOOK();
			noti=0;
			}
		root_e=root_e->next;
		}
		while(root_u){
		if(root_u->getPu_name()==se){
			root_u->showBOOK();
			noti=0;
			}
		root_u=root_u->next;
		}
		if(noti==0){
			break;
		}
	}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_year_u(urdu *head){
	int se;
	int noti=1;
	cout<<"Enter Year ::";
	cin>>se;
	if(se>999&&se<10000){
	}else{
		cout<<"Invalid Year."<<endl;
		getch();
		search_year_u(head);
	}
	urdu *root=head;
	while(root){
		if(root->getye_book()==se){
			root->showBOOK();
			noti=0;
		}else{
			noti=1;
		}
		root=root->next;
		}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_year_e(english *head){
	int se;
	int noti=1;
	cout<<"Enter Year ::";
	cin>>se;
	if(se>999&&se<10000){
	}else{
		cout<<"Invalid Year."<<endl;
		getch();
		search_year_e(head);
	}
	english *root=head;
	while(root){
		if(root->getye_book()==se){
			root->showBOOK();
			noti=0;
		}else{
			noti=1;
		}
		root=root->next;
		}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
void search_year_b(english *e_head,urdu *u_head){
	int se;
	int noti=1;
	cout<<"Enter Year ::";
	cin>>se;
	english *root_e=e_head;
	urdu *root_u=u_head;
	while(root_e!=NULL||root_u!=NULL){
		while(root_e){
		if(root_e->getye_book()==se){
			root_e->showBOOK();
			noti=0;
			break;
			}
		root_e=root_e->next;
		}
		while(root_u){
		if(root_u->getye_book()==se){
			root_u->showBOOK();
			noti=0;
			break;
			}
		root_u=root_u->next;
		}
		if(noti==0){
			break;
		}
	}
	if(noti){
			cout<<"\t\tSorry! Not Found...."<<endl;
		}
}
int main(){
	int condi=0;
	//urdu books
	urdu *urdu_head=NULL;
	urdu *urdu_tail=NULL;
	//english books
	english *english_head=NULL;
	english *english_tail=NULL;
do{
	switch(manu()){
		case'a':
		case'A':
			{
				system("cls");
			switch(admin_manu()){
				case'X':
				case'x':
					{
						system("cls");
					switch(show_ur_en()){
						case'u':
						case'U':
							{
								system("cls");
							switch(search_manu()){
								case'I':
								case'i':
									{
										search_id_u(urdu_head);
								break;		
									}
								case'N':
								case'n':
									{
										search_name_u(urdu_head);
								break;	
									}
								case'A':
								case'a':
									{
										search_author_u(urdu_head);
								break;	
									}
								case'p':
								case'P':
									{
										search_publisher_u(urdu_head);
								break;	
									}
								case'R':
								case'r':
									{
										search_year_u(urdu_head);
								break;		
									}
							default:
								cout<<"Invalid Choice...";
							}
						break;
							}
						case'E':
						case'e':
							{
								system("cls");
							switch(search_manu()){
								case'I':
								case'i':
									{
										search_id_e(english_head);
								break;		
									}
								case'N':
								case'n':
									{
										search_name_e(english_head);
								break;	
									}
								case'A':
								case'a':
									{
										search_author_e(english_head);
								break;	
									}
								case'p':
								case'P':
									{
										search_publisher_e(english_head);
								break;	
									}
								case'R':
								case'r':
									{
										search_year_e(english_head);
								break;		
									}
							default:
								cout<<"Invalid Choice...";
							}
						break;
							}
						case'B':
						case'b':
							{
							switch(search_manu()){
								case'I':
								case'i':
									{
										search_id_b(english_head,urdu_head);
								break;		
									}
								case'N':
								case'n':
									{
										search_name_b(english_head,urdu_head);
								break;	
									}
								case'A':
								case'a':
									{
										search_auther_b(english_head,urdu_head);
								break;	
									}
								case'p':
								case'P':
									{
										search_publisher_b(english_head,urdu_head);
								break;	
									}
								case'R':
								case'r':
									{
										search_year_b(english_head,urdu_head);
								break;		
									}
							default:
								cout<<"Invalid Choice...";
							}						
						break;
							}
						default:
							cout<<"Invalid Choice...";
						}
				break;
					}
				case'E':
				case'e':
					{
						system("cls");
					switch(book_lgs()){
						case'U':
						case'u':
							{
							ofstream u_write;
							cin.ignore();
							if(urdu_head==NULL){
								urdu *urdu_n=new urdu;
								urdu_n->setBo_id();
								urdu_n->setBo_name();
								u_write.open("urdu.csv",ios::app);
								u_write<<urdu_n->getBo_id();
								u_write.close();
								u_write.open("urdu.csv",ios::app);
								u_write<<","<<urdu_n->getBo_name();
								u_write.close();
								urdu_n->setAu_name();
								urdu_n->setPu_name();
								urdu_n->setty_name();
								urdu_n->setye_book();								
								urdu_n->next=NULL;
								urdu_n->pre=NULL;
								urdu_head=urdu_n;
								urdu_tail=urdu_n;
								cin.ignore();
							}else{
						ID_2:
								urdu *urdu_n=new urdu;
								urdu_n->setBo_id();
								int s=urdu_n->getBo_id();
								if(Dublicate_id(english_head,urdu_head,s)==0){
										cout<<"THIS ID ALREADY EXIST";
										system("pause");
										system("cls");
										goto ID_2;
								}
								urdu_n->setBo_name();
								string ss= urdu_n->getBo_name();
								if(doublicate_name(english_head,urdu_head,ss)==0){
										cout<<"THIS ID ALREADY EXIST";
										system("pause");
										system("cls");
										goto ID_2;
								}
								u_write.open("urdu.csv",ios::app);
								u_write<<urdu_n->getBo_id();
								u_write.close();
								u_write.open("urdu.csv",ios::app);
								u_write<<","<<urdu_n->getBo_name();
								u_write.close();
								urdu_n->setAu_name();
								urdu_n->setPu_name();
								urdu_n->setty_name();
								urdu_n->setye_book();
								urdu_n->next=NULL;
								urdu_n->pre=urdu_tail;
								urdu_tail->next=urdu_n;
								urdu_tail=urdu_n;	
								}
						break;
							}
						case'E':
						case'e':
							{
							ofstream e_write;
							cin.ignore();
							if(english_head==NULL){
								english *english_n=new english;
								english_n->setBo_id();
								english_n->setBo_name();
								e_write.open("english.csv",ios::app);
								e_write<<english_n->getBo_id();
								e_write.close();
								e_write.open("english.csv",ios::app);
								e_write<<","<<english_n->getBo_name();
								e_write.close();
								english_n->setAu_name();
								english_n->setPu_name();
								english_n->setty_name();
								english_n->setye_book();
								english_n->pre=NULL;
								english_n->next=NULL;
								english_head=english_n;
								english_tail=english_n;
								
							}else{
						ID_3:
								english *english_n=new english;
								english_n->setBo_id();
								int s=english_n->getBo_id();
								if(Dublicate_id(english_head,urdu_head,s)==0){
										cout<<"THIS ID ALREADY EXIST";
										system("pause");
										system("cls");
										goto ID_3;
								}
								english_n->setBo_name();
								string ss= english_n->getBo_name();
								if(doublicate_name(english_head,urdu_head,ss)==0){
										cout<<"THIS ID ALREADY EXIST";
										system("pause");
										system("cls");
										goto ID_3;
								}
								e_write.open("english.csv",ios::app);
								e_write<<english_n->getBo_id();
								e_write.close();
								e_write.open("english.csv",ios::app);
								e_write<<","<<english_n->getBo_name();
								e_write.close();
								english_n->setAu_name();
								english_n->setPu_name();
								english_n->setty_name();
								english_n->setye_book();
								english_n->next=NULL;
								english_n->pre=english_tail;
								english_tail->next=english_n;
								english_tail=english_n;	
								}
						break;
							}
						default:
							cout<<"Invalid Choice...";
						}
				break;
					}
				case'S':
				case's':
					{
						system("cls");
					char ck=show_ur_en();
					if(ck=='E'||ck=='e'){
							cout<<"\t\t\t----------ENGLISH BOOK'S----------"<<endl;
							english *root=english_head;
							while(root){
								root->showBOOK();
								cout<<"==============="<<endl;
								root=root->next;
								}
					}else if(ck=='U'||ck=='u'){
							cout<<"\t\t\t----------URDU BOOK'S----------"<<endl;
							urdu *root=urdu_head;
							while(root){
								root->showBOOK();
								cout<<"==============="<<endl;
								root=root->next;
								}
					}else if(ck=='b'||ck=='B'){
							cout<<"\t\t\t----------ALL BOOK'S----------"<<endl;
							english *roott=english_head;
							while(roott){
								roott->showBOOK();
								cout<<"==============="<<endl;
								roott=roott->next;
								}
							urdu *root=urdu_head;
							while(root){
								root->showBOOK();
								cout<<"==============="<<endl;
								root=root->next;
								}
							}else{
								cout<<"Invalid Choice...";
							}
				break;
					}
				default:
					cout<<"Invalid Choice...";
				}
		break;
			}
		case'U':
		case'u':
			{
			switch(user_manu()){
				
				}
		break;
			}
		default:
			cout<<"invalid choice..."<<endl;
	}
getch();
system("cls");
cout<<"PRESS 0 TO EXIST."<<endl;
cout<<"PRESS 1 TO CONTINUE."<<endl;
cin>>condi;
}while(condi);
 }
