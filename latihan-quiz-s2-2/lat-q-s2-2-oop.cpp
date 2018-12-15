#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

class Racer{
	private:
		string name;
		string country;
		string horse;
		int rank;
	public:
		Racer(){}
		~Racer(){}

		void setName(string name){this->name=name;}
		void setCountry(string country){this->country=country;}
		void setHorse(string horse){this->horse=horse;}
		void setRank(int rank){this->rank=rank;}

		string getName(){return this->name;}
		string getCountry(){return this->country;}
		string getHorse(){return this->horse;}
		int getRank(){return this->rank;}
};

void view(vector<Racer> vecRacer){
	if(vecRacer.empty()){
		cout<<"No data.";
	}

	for(int i=0;i<vecRacer.size();i++){
		cout<<i+1<<vecRacer[i].getName()<<" "<<vecRacer[i].getCountry()<<" "<<vecRacer[i].getHorse()<<" "
			<<vecRacer[i].getRank()<<endl;
	}
}

void reg(vector<Racer> &vecRacer){
	string nameTemp;
	string horseTemp;
	string countryTemp;
	int rankTemp;

	do{
		cout<<"Input name:";
		getline(cin, nameTemp); cin.clear(); cin.sync();
	}while(nameTemp.find(' ') == -1);

	do{
		cout<<"Input country:";
		getline(cin, countryTemp); cin.clear(); cin.sync();
	}while(countryTemp.find(' ') != -1);

	do{
		cout<<"Input horse:";
		getline(cin, horseTemp); cin.clear(); cin.sync();
	}while(horseTemp.length() < 5 || horseTemp.length() > 20);
	
	do{
		cout<<"Input rank:";
		cin>>rankTemp; cin.clear(); cin.sync();
	}while(rankTemp > 40 || rankTemp < 1 || cin.fail());

	Racer r;
	r.setName(nameTemp);
	r.setCountry(countryTemp);
	r.setHorse(horseTemp);
	r.setRank(rankTemp);

	vecRacer.push_back(r);

}

void del(vector<Racer> &vecRacer){
	int dele;

	cout<<"Input no.:";
	cin>>dele; cin.clear(); cin.sync();

	vecRacer.erase(vecRacer.begin() + dele - 1);
}

void upd(vector<Racer> &vecRacer){
	int upd;

	cout<<"Input no.:";
	cin>>upd; cin.clear(); cin.sync();

	string nameTemp;
	string horseTemp;
	string countryTemp;
	int rankTemp;

	do{
		cout<<"Input name:";
		getline(cin, nameTemp); cin.clear(); cin.sync();
	}while(nameTemp.find(' ') == -1);

	do{
		cout<<"Input country:";
		getline(cin, countryTemp); cin.clear(); cin.sync();
	}while(countryTemp.find(' ') != -1);

	do{
		cout<<"Input horse:";
		getline(cin, horseTemp); cin.clear(); cin.sync();
	}while(horseTemp.length() < 5 || horseTemp.length() > 20);
	
	do{
		cout<<"Input rank:";
		cin>>rankTemp; cin.clear(); cin.sync();
	}while(rankTemp > 40 || rankTemp < 1 || cin.fail());

	Racer r;
	r.setName(nameTemp);
	r.setCountry(countryTemp);
	r.setHorse(horseTemp);
	r.setRank(rankTemp);

	vecRacer[upd-1] = r;
}


int main(){
	vector<Racer> vecRacer;

	int ch;

	do{
		cout<<"Horse Racing"<<endl<<"=========="<<endl;
	
		do{
			cout<<"1. Reg new racer."<<endl
				<<"2. View Racer."<<endl
				<<"3. Delete racer."<<endl
				<<"4. Update racer."<<endl
				<<"5. Exit"<<endl
				<<"Choice: "<<endl;

			cin>>ch; cin.clear(); cin.sync();
		}while(ch<1 || ch>5);

		switch(ch){
			case 1:
				reg(vecRacer);
				cin.get();
				break;
			case 2:
				view(vecRacer);
				cin.get();
				break;
			case 3:
				del(vecRacer);
				cin.get();
				break;
			case 4:
				upd(vecRacer);
				cin.get();
				break;
		}


	}while(ch!=5);

	cin.get();
	return 0;
}

