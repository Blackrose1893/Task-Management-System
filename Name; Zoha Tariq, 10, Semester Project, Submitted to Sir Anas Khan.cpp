                    //Task Management system
 
#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

//...Class: Subject 
class Subject{
	protected:
		string subjectName;
	public:
		void InputSub(){
			cout << "Enter Subject Name: ";
			cin >> subjectName;
			}
		void DisplaySub(){
			cout << " Subject: " << subjectName << endl;
			}
	};
//Class:  Task which we have to done
class Task: public Subject{
	private:
		int TaskID;
		string TaskType;
		string TopicName;
		string Deadline;
		string Status;
		int date;
		int month;
	public:
		void InputTask(){
			cout << "Enter Task ID : ";
			cin >> TaskID;
			cout << "Enter TaskType : ";
			cin >> TaskType;
			InputSub();
			cout << "Enter Topic Name : ";
			cin.ignore();
			getline(cin,TopicName);
			cout << "Enter Task Deadline : ";
			cin.ignore();
		    getline(cin,Deadline);
			Status= "Pending";
		}
	void DisplayTask(){
		cout << "Task Id : " << TaskID << endl;
		cout << "Task Type : " << TaskType << endl;
		DisplaySub();
		cout << "Enter Topic Name : "<< TopicName << endl;
		cout << "Task Deadline : " << Deadline << endl;
		
		cout << "Task Id : " << TaskID << endl;
		cout << "Status : " << Status << endl;
	}
	//Getter functions used to access private members in main
	int getID(){
		return TaskID;
	}
	string getStatus(){
		return Status;
	}
	void Markcompleted(){
		Status="Completed!";
	}
};
// ...Main Body of Program... //
int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Task t[100];
	int count= 0;
	int choice;
	do{
		SetConsoleTextAttribute(hConsole, 10);
       cout << "\n===== STUDY PLANNER SYSTEM =====\n";
        cout << "1. Add Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. View Pending Tasks\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Delete Task\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
		switch(choice){
		//Enter task
			case 1:{
				SetConsoleTextAttribute(hConsole, 11);
				t[count].InputTask();
				count++;
				cout << "Task entered Successfully!" << endl;
				break;
			}
				// Display all Task
			case 2:{
				SetConsoleTextAttribute(hConsole, 12);
				if(count==0){
					cout << "No Task Available!" << endl;
				}
				else{
				for(int i=0; i<count; i++){
					t[i].DisplayTask();
				}
				}
				break;
			}
				//Pending task
		    case 3:{
		    	SetConsoleTextAttribute(hConsole, 13);
				if(count==0){
					cout << "No Task Available!";
				}
				else{
					for(int i=0;i<count;i++)
					if(t[i].getStatus()=="Pending"){
						t[i].DisplayTask();
					}
				}
				break;
			}
				//Mark Completed
			case 4:{
				SetConsoleTextAttribute(hConsole, 8);
				int id;
				
				if(count==0){
					cout << "Task Not found : " << endl;
				}
				else if(count!=id){
					cout<<"ID not Found!"<<endl;
				}
				else{
					cout << "Enter Task ID to Mark Completed : " << endl;
				    cin >> id;
				    for(int i=0;i<count; i++){
					if(t[i].getID()==id){
						t[i].Markcompleted();
						cout << "Task Marked as completed!";
						}	
					}	
				}
				break;
			}	
			case 5:{
				SetConsoleTextAttribute(hConsole, 9);
				int id;
				cout << "Enter id to delete task : " << endl;
				cin >> id;
				if(count==0){
					cout << "No Task Found to del." << endl;
				}
				else if(count!=id){
					cout<<"Id Not found"<<endl;
				}
				else{
					for(int i=0; i<count; i++){
					if(t[i].getID()==id){
						t[i]=t[count-1];
						count--;
						cout << "Task Deleted!" << endl;
					}
				}
			}
				break;
				}
			case 6:
				SetConsoleTextAttribute(hConsole, 7);
				cout << "Exit...";
				break;
			default:
				cout << "Invalid Choice! " << endl;
			}
	}
    while(choice!=6);
	return 0;
}
