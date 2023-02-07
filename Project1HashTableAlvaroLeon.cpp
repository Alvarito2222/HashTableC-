// Program 1- Alvaro Leon Parra



#define tableSize 19																				// Size of the table
#define maxSize 20																					// Size of maxsize
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void printTable(string Table[tableSize])															// Function That prints the Hash Table through a loop
{
	for(int i =0;i<tableSize;i++)
	{
		cout<<"Element #"<<i<<": "<<Table[i]<<"\n";
	}
	
}

int linearProbing(string key,string Table[tableSize],string name, string lastname,int counter)		//Function uses linar Probring as the technique to insert a record, and returns a counter,
{																									// to know if the table is full.
	int hashPos= stoi(key) %tableSize;
	counter++;																						// Everytime this function is called, since there is an insertion , the counter adds 1.
	
	
	if(counter==maxSize)																			// If the counter is 20 , the Table will be full
	{
		cout<< "\n!!HASH TABLE IS FULL!!" << endl;
		counter--;																					// Counter -1 will let the program go back to the menu and not display anymore Hash Table is full.
		return counter;
	}
	cout<<"\nHash Value: "<<hashPos <<endl;
	
	if(Table[hashPos]=="null" || Table[hashPos]==name+" "+lastname+" "+key)							// If the Hash Key Obtain is equal to Null or the same name lastname and key as the old one, 
	{																								// it will insert inmediately the name last name in that position, and leave this function.
		Table[hashPos]=name+" "+lastname+" "+key;
		cout << "Position #"<<hashPos << " tested."<< endl;
		cout << "||" << name <<" "<< lastname <<" successfully inserted at #"<< hashPos<< "||\n";
				
	}
	else{																							// If the key obtain is not equal to any of the ones above, it will add 1 to the Hash Position , 
		for(int i=hashPos;i<=tableSize;i++)															// since we are using linear probing; until null or the same record is found.
		{
			if (i==tableSize)
			{
			  	i=0;
			}	
			cout << "Position #"<< i << " tested."<< endl;
			if(Table[i]=="null")
			{					
				cout << "||" << name <<" "<< lastname <<" successfully inserted at #"<< i<< "||\n";
				Table[i]=name+" "+lastname+" "+key;
				break;	
			}
			cout << "[Collision Ocurred]" << endl;													// Everytime the loop goes through , there will be a collision , until a space is found.
		}
						
	}
	return counter;
}

int quadraticProbing(string key,string Table[tableSize],string name, string lastname,int counter)  //Function uses Quadratic Probring as the technique to insert a record, and returns a counter,
{																									// that when it hits 20 , the table is full.
	int hashPos= stoi(key) %tableSize;
	int collision = 1;																				// value that increases when the loop goes, and starts at 0
    bool exists = true;
    int counter2=0;																					// Counter to count how many trials, since with this technique sometimes they key won't be found.
    			
	
	counter++;
	
	if(counter==maxSize){
		cout<< "\n!!HASH TABLE IS FULL!!" << endl;
		counter--;
		return counter;
	}
	cout<<"\nHash Value: "<<hashPos <<endl;
	while(exists != false)
   	{
   		if(counter2==maxSize)																		// When the second counter has a value of 20, then it won't find the key.
   		{
   			cout<< "No possible Possition for this Key\n";
   			counter--;
   			return counter;
		}
        else if(Table[hashPos]=="null" || Table[hashPos]==name+" "+lastname+" "+key)
       	{
			Table[hashPos]=name+" "+lastname+" "+key;
			cout << "Position #"<<hashPos << " tested."<< endl;
			cout << "||" << name <<" "<< lastname <<" successfully inserted at #"<< hashPos<< "||\n";
            exists = false;
        }
        else if(exists == true)
        {
        	counter2++;
        	cout << "Position #"<<hashPos << " tested.";
            hashPos = (hashPos+collision) % tableSize;
            collision = collision + 2;
            cout << "[Collision Ocurred]" << endl;
        }
    }
	return counter;
	
}


int doubleHashing(string key,string Table[tableSize],string name, string lastname,int counter)       //Function uses Double Hashing as the technique to insert a record, and returns a counter.
{
	int hashPos= stoi(key) %tableSize;
	int div = stoi(key) /tableSize;																	// Divides the key , on string form to obtain the integer that we will add to the hash value,
    bool exists = true;																				// whenever there is a collision.
	counter++;	
	
	if(div==0 || div==tableSize)																	// If the integer, is equal to 0 or 19, this will be = to 1.
    {
        div=1;
    }
	
	if(counter==maxSize){
		cout<< "\n!!HASH TABLE IS FULL!!" << endl;
		counter--;
		return counter;
	}
	cout<<"\nHash Value: "<<hashPos <<endl;
	
	while(exists != false)
   	{
   		
        if(Table[hashPos]=="null" || Table[hashPos]==name+" "+lastname+" "+key)
       	{
			Table[hashPos]=name+" "+lastname+" "+key;
			cout << "Position #"<<hashPos << " tested."<< endl;
			cout << "||" << name <<" "<< lastname <<" successfully inserted at #"<< hashPos<< "||\n";
            exists = false;
        }
        else if(exists == true)
        {
        	cout << "Position #"<<hashPos << " tested.";
            hashPos = (hashPos+div) % tableSize;
            cout << "[Collision Ocurred]" << endl;
        }
    }
	return counter;
	
}

void searchLinear(string key,string Table[tableSize],string name, string lastname)						// Function that searches for a record, using linear probing
{
	
	int hashPos=stoi(key)%tableSize;
	bool exists = true;
	int counter2=0;
	while(exists != false)
	
	
	{
		if(counter2==maxSize)
   		{
   			cout<< "No Key Found!\n";
   			break;
		}
		else if(Table[hashPos].find(key,0) !=string::npos)												// Checks if inside the string on the array , there is a key that pairs the key obtain .
		{
			cout << key  << " has been found at Hash Position #"<<hashPos<<endl;
			exists = false;
		}
		else if(exists == true)
		{
			counter2++;
			cout << "Position #"<<hashPos << " tested.";
            hashPos = (hashPos+1) % tableSize;
            cout << "[Pair not found]" << endl;
		}
	}	
}

void searchQuadratic(string key,string Table[tableSize],string name, string lastname)					// Function that searches for a record, using quadratic probing
{
	
	int hashPos=stoi(key)%tableSize;
	bool exists = true;
	int counter2=0;
	int collision = 1;
	while(exists != false)
	
	
	{
		if(counter2==maxSize)
   		{
   			cout<< "No Key Found!\n";
   			break;
		}
		else if(Table[hashPos].find(key,0) !=string::npos)
		{
			cout << key  << " has been found at Hash Position #"<<hashPos<<endl;
			exists = false;
		}
		else if(exists == true)
		{
			counter2++;
			cout << "Position #"<<hashPos << " tested.";
            hashPos = (hashPos+collision) % tableSize;
            collision = collision + 2;
            cout << "[Pair not found]" << endl;
		}
	}	
}

void searchDouble(string key,string Table[tableSize],string name, string lastname)						// Function that searches for a record, using double hashing
{
	
	int hashPos=stoi(key)%tableSize;
	int div = stoi(key) /tableSize;
	bool exists = true;
	int counter2=0;
	
	if(div==0 || div==tableSize)
    {
        div=1;
    }
    
	while(exists != false)
	{
		if(counter2==maxSize)
   		{
   			cout<< "No Key Found!\n";
   			break;
		}
		else if(Table[hashPos].find(key,0) !=string::npos)
		{
			cout << key  << " has been found at Hash Position #"<<hashPos<<endl;
			exists = false;
		}
		else if(exists == true)
		{
			counter2++;
			cout << "Position #"<<hashPos << " tested.";
           	hashPos = (hashPos+div) % tableSize;
            cout << "[Pair not found]" << endl;
		}
	}	
}


int removeItemLinear(string key,string Table[tableSize],string name, string lastname,int counter)      // Function that removes for a record, using linear probing, and return counter.
{
	counter--;																							// Everytime this function is called, the counter will be -1  since you are removing ,
	int hashPos=stoi(key)%tableSize;																	// something from the hashtable.
	bool exists = true;	
	int counter2=0;
	while(exists != false)
	{
		if(counter2==maxSize)																			// If there is no key, the counter will add 1 so the counter will remain equal.
   		{
   			cout<< "No Key Found!\n";
   			counter++;
   			return counter;
		}
		else if(Table[hashPos].find(key,0) !=string::npos)
		{
			Table[hashPos]="null";
			cout << key  << " has been removed at Hash Position #"<<hashPos<<endl;
			exists = false;
		}
		else if(exists == true)
		{
			counter2++;
			cout << "Position #"<<hashPos << " tested.";
            hashPos = (hashPos+1) % tableSize;
            cout << "[Pair not found]" << endl;
		}
	}
	return counter;	
}

int removeItemQuadratic(string key,string Table[tableSize],string name, string lastname,int counter)	// Function that removes for a record, using quadratic probing, and return counter.
{
	counter--;
	int hashPos=stoi(key)%tableSize;
	bool exists = true;
	int counter2=0;
	int collision = 1;
	while(exists != false)
	{
		if(counter2==maxSize)
   		{
   			cout<< "No Key Found!\n";
   			counter++;
   			return counter;
		}
		else if(Table[hashPos].find(key,0) !=string::npos)
		{
			Table[hashPos]="null";
			cout << key  << " has been removed at Hash Position #"<<hashPos<<endl;
			exists = false;
		}
		else if(exists == true)
		{
			counter2++;
			cout << "Position #"<<hashPos << " tested.";
            hashPos = (hashPos+collision) % tableSize;
            collision = collision + 2;
            cout << "[Pair not found]" << endl;
		}
	}
	return counter;	
}

int removeItemDouble(string key,string Table[tableSize],string name, string lastname,int counter)	// Function that removes for a record, using double hashing, and return counter.
{
	counter--;
	int hashPos=stoi(key)%tableSize;
	int div = stoi(key) /tableSize;
	bool exists = true;
	int counter2=0;
	
	if(div==0 || div==tableSize)
    {
        div=1;
    }
    
	while(exists != false)
	{
		if(counter2==maxSize)
   		{
   			cout<< "No Key Found!\n";
   			counter++;
   			return counter;
		}
		else if(Table[hashPos].find(key,0) !=string::npos)
		{
			Table[hashPos]="null";
			cout << key  << " has been removed at Hash Position #"<<hashPos<<endl;
			exists = false;
		}
		else if(exists == true)
		{
			counter2++;
			cout << "Position #"<<hashPos << " tested.";
            hashPos = (hashPos+div) % tableSize;
            cout << "[Pair not found]" << endl;
		}
	}
	return counter;	
}

main()
{
	
	ifstream ifile;
	string Table[tableSize];
	string key;
	string lastname;
 	string name;
 	string myFile;
 	int counter=0;
 	int option=0;
 	
 	cout<< "//WELCOME//\n";
 	cout<< "Enter a file name to start: ";
 	cin >> myFile;																				// stores the name of the file in the string .
 	
 	ifile.open(myFile);																			// check to see if the file is found , if so this one will continue , if its not found the program will exit.
	if (ifile.is_open())
	{
        cout << "File Opened Successfully." << endl;
	}
	else
    {
        cerr << "File not found!" << endl;
        exit(1);
    }
    ifile.close();
 	do 																							// If this file is found, the program will display 3 options which you can only use [1][2][3].
 	{
		system("CLS");
 		cout<< "||||Techniques||||\n";
 		cout<< "1.Linear Probing\n";
 		cout<< "2.Quadratic Probing\n";
 		cout<< "3.Double Hashing\n";
 		cout<< "How would you like to run this program[1][2][3]: ";
 		cin >> option ;																			// stores the technique into option which will be used later 
 		cin.clear();                   															 //clear bad input flag
        cin.ignore(1000, '\n');        															 //discard input
	}while(option!=3 && option !=2 && option!=1);												// if its not 3,2,1 the program will run again deliting everything else from the input flag
 	
	system("CLS");																				// program will clear screan to continue.
	 
	for(int i=0; i<tableSize; i++)																	// the table will inizialitaze with everything NULL
	{
		Table[i]="null";
	}
	ifile.open(myFile);
    if (ifile.is_open()) 
    	{
        	while ( ifile >> name >> lastname >>key)											// Opens the file and stores, the first column into names, second column into lastname and third column into key.
        	{
				if(option==1){																	// depends the option selected before it will use a different technique that will be used all program.
					counter=linearProbing(key,Table,name,lastname,counter);	
			 }
				if(option==2){
					counter=quadraticProbing(key,Table,name,lastname,counter);	
			 }
				if(option==3){
					counter=doubleHashing(key,Table,name,lastname,counter);
			 }
			}
        	ifile.close(); 
    	}	

	int OptMen=0;
	do
	{
		cout<<"\n---Menu Hash---\n";														// runs a loop that opens a menu to select between inserting,searching,deleting or exit the program.
		cout<<"1.Insert Record\n";
		cout<<"2.Search for a Record\n";
		cout<<"3.Delete Record\n";
		cout<<"4.EXIT\n";
		cout<<"Option:\n";
		cin>>OptMen;
		
		if(OptMen == 1)																		// depending the option selected, the program will execute different commands.
		{
			cout<<"Insert Key[0-999]: ";
			cin>> key;
			cout << "Insert a Name and a Lastname: ";
			cin >>name >> lastname;
			
			
				if(option==1){
					counter=linearProbing(key,Table,name,lastname,counter);
				}
				if(option==2){
					counter=quadraticProbing(key,Table,name,lastname,counter);	
				}
				if(option==3){
					counter=doubleHashing(key,Table,name,lastname,counter);
				}
		}
	
		else if(OptMen == 2)
		{
			cout<<"Insert Key[0-999]: ";
			cin>> key;
			
			if(option==1){
					searchLinear(key,Table,name,lastname);
				}
				if(option==2){
					searchQuadratic(key,Table,name,lastname);	
				}
				if(option==3){
					searchDouble(key,Table,name,lastname);
				}
			
	
			}
		else if(OptMen ==3 )
		{
			printTable(Table);
			cout << "Insert Key[0-999]: ";
			cin >> key;
			
				if(option==1){
					counter=removeItemLinear(key,Table,name,lastname,counter);
				}
				if(option==2){
					counter=removeItemQuadratic(key,Table,name,lastname,counter);	
				}
				if(option==3){
					counter=removeItemDouble(key,Table,name,lastname,counter);
				}
		}
		
		else if(OptMen !=1 && OptMen !=2 && OptMen !=3 && OptMen !=4)						// if something that is not [4][3][2][1] is inserted , program will say try again and clear input.
		{
		
			cin.clear();                   
            cin.ignore(1000, '\n');         
			cout<<"Try again [1][2][3][4]";
			cout<<"\n";
		}
		
	}while(OptMen!=4);																		// loop will end if option 4 is selected 
	
	system("CLS");																			// It will clear screen and say see you soon.
	
	cout << "!!SEE YOU SOON!!" << endl;
	
}