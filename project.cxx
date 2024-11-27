#include <iostream>

struct post{
	std::string text, OP, date;
};

struct client {
	std::string email, name, address,
	phone_no, nick, password,b_date;
	int age=0;
	bool a=false;
};








std::string rod = "======================================";
std::string top = "\033[H";
std::string esc = top+"\033[6B\033[11C";
post p1;
client usr;











std::string notif () {
	std::string se = rod+"\ncommand..:\n\
\
home    profile   settings   \033[47;30mnotifications\033[0m\
\n\
            NOTIFICATION\n\
       \n\
         no notification yet";
    system("clear");
	std::cout << se<<top<<"\033[11C\033[B";
	
	std::string a;
	std::cin >> a;
	return a;
	
		
}

std::string settings () {
	std::string se = rod+"\ncommand..:\n\
\
home    profile   \033[47;30msettings\033[0m   notifications\
\n\
            SETTINGS\n\
\n\
edit profile\n\
logout";
	system("clear");
	std::cout << se<<top<<"\033[11C\033[B";
	
	std::string a;
	std::cin >> a;
	return a;
	
		
}

std::string profile(){
	
	
	
	

	std::string a = "\ncommand..:\n\
\
home    \033[47;30mprofile\033[0m   settings   notifications\
	              PROFILE\n\
profile picture:\n\
@@@@@@@@@\n\
@@@...@@@\n\
@@.....@@\n\
@@@...@@@\n\
@@@..@@@@\n\
@.......@\n\
\n\
about me:\n\
	nick name: " + usr.nick +"\n\
	name: "+ usr.name +"\n\
	age: "+ std::to_string(usr.age) +"\n\
	birth day: "+usr.b_date;

	system("clear");
	std::cout <<rod<< a+top+"\033[11C\033[B";
	
	
	
	
	
	std::cin >> a;
	return a;


}

std::string home() {
	
	
	std::string main_m =
	"\ncommand..:\n\
\
\033[47;30mhome\033[0m    profile   settings   notifications\
 ____  _____ ____  ____   ___  _   _\n\
|  _ \\| ____|  _ \\/ ___| / _ \\| \\ | |\n\
| |_) |  _| | |_) \\___ \\| | | |  \\| |\n\
|  __/| |___|  _ < ___) | |_| | |\\  |\n\
|_|   |_____|_| \\_\\____/ \\___/|_| \\_|\n\
  	  ____   ___   ___  _  __\n\
	 | __ ) / _ \\ / _ \\| |/ /\n\
	 |  _ \\| | | | | | | ' /\n\
	 | |_) | |_| | |_| | . \\\n\
	 |____/ \\___/ \\___/|_|\\_\\\n\
\n\
@@@@@@@@@\n\
@@@...@@@\n\
@@.....@@     what's on your mind??\n\
@@@...@@@     type post to start\n\
@@@..@@@@\n\
@.......@\n\n\
\n\
\n\
\n\
1....................................\n\
               \033[1m"+p1.OP+"\033[0m\n\
            "+p1.date+"\n\
"+p1.text+"\n\
\n\
______________________________________\n\
like0          comment0         share0\n\
  0                0               0\n\
......................................"	;
	
	system("clear");
	std::cout <<rod<< main_m+"\033[99S"+top+"\033[11C\033[B";
	
	
	
	std::string a;
	std::cin >> a;
	return a;
	
}


bool login(){
	
	
	std::string login_page = rod+"\n         welcome to personbook\na wonderfull place to share idea with\n                 other\n\n\nuser name: \npassword : \n\n\nno account?? just enter \"back\" on both\nuser id and password enter \"back.\" to re-enter the user name\n\n ____  _____ ____  ____   ___  _   _\n|  _ \\| ____|  _ \\/ ___| / _ \\| \\ | |\n| |_) |  _| | |_) \\___ \\| | | |  \\| |\n|  __/| |___|  _ < ___) | |_| | |\\  |\n|_|   |_____|_| \\_\\____/ \\___/|_| \\_|\n  	  ____   ___   ___  _  __\n	 | __ ) / _ \\ / _ \\| |/ /\n	 |  _ \\| | | | | | | ' /\n         | |_) | |_| | |_| | . \\\n	 |____/ \\___/ \\___/|_|\\_\\";
	
	std::string a, b;
  login:
	std::cout << login_page+esc;
	std::cin >> a;
	
	std::cout<<"\033[11C";
	std::cin >> b;
	if (b == "back.") {
		system("clear");
		goto login;
	}
	if (a == b && b == "back" && not usr.a){
		std::string signin = rod+"\n\nplease fill out the information.\nenter \"back\" to return back\n\n\nname: \nphone no# or email: \nage: \nbirth date: mm/dd/yyyy\nnick name: \npassword: ";
		system("clear");
		std::cout<<signin<<top<<"\033[6B\033[6C";
		std::cin >> usr.name;std::cout<<"\033[20C";
		std::cin >> usr.email;std::cout<<"\33[5C";
		std::cin >> usr.age;std::cout<<"\033[12C";
		std::cin >> usr.b_date;std::cout<<"\033[11C";
		std::cin >> usr.nick;std::cout<<"\033[10C";
		std::cin >> usr.password;
		std::cout<<"press enter to continue";
		std::string ls;
		std::cin >> ls;
		b = usr.password;a = usr.email;
					
	};
	
	bool is_success = (usr.password == b && usr.email == a);
	if (not is_success) {
		std::cout<<top+"\033[9Bwrong user name or password"+top;
		system("clear");
		goto login;
		
	}
	return is_success;
}




int main() {

	p1.text = "hi am meu nice to use personbook";
	p1.OP = "meu";
	p1.date = "mar 1 2024";
	login();
	char answer = home()[0];

	mainmenu:
	if(answer=='h'){
		answer = home()[0];
	}else if (answer=='p'){
		answer = profile()[0];
	}else if(answer=='s'){	
		answer = settings()[0];
	}else if (answer =='n'){
		answer = notif()[0];
	}else {
		if (answer == 'l'){
			system("clear");
			login();
			answer = home()[0];
		}
		goto mainmenu;}
	goto mainmenu;
	
	
	
}