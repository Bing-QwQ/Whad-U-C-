#include<windows.h>
#include<string.h>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
using namespace std;

bool filecheck(const char* checkpath);
void filexor(char* finpath);
ifstream fin;
ofstream fout;

int main(int argc,char* argv[]) {
	cout<<">> "<<argc-1<<" cache file druged in <<"<<"\n";
	
	if(argc>1){
		for(int i=1;i<argc;i++){
			
			cout<<i<<" of "<<argc-1<<"\n";
			
			if(!filecheck(argv[i])){
				cout<<" -> Skip the generation\n--------------------------------------------------\n";
				continue;
			}
			
			string path1=".\\",path2=to_string(i),path3=".mp3";
			string temppath = path1+path2+path3;
			char* foutpath = &temppath[0];
			
			fin.open(argv[i],ios::in|ios::binary) ;
			fout.open(foutpath,ios::out|ios::binary);
			
			if(fin.good()){
				cout<<" <- "<<argv[i]<<"\n <- Loaded";
				filexor(argv[i]);
				cout<<"\n <- Processed";
				
				fin.close();
				fout.close();
				cout<<"\n -> Generate as -> \""<<(path2+path3)<<"\"\n--------------------------------------------------\n";
			
			}
		}
	}
	cout<<"==================================================\n>> Press any key to exit the program <<";
	getch();
	return 0;
}

bool filecheck(const char* checkpath){
	long long len=strlen(checkpath);
	char c='c',u='u',dot='.';
	if(*(checkpath+len-1)==c && *(checkpath+len-2)==u && *(checkpath+len-3)==dot){
		cout<<checkpath<<" -> is a cache file\n";
		return true;
	}
	else{
		cout<<checkpath<<" -> not cache file\n";
		return false;
	}
}

void filexor(char* finpath){
	char ch=fin.get();
	char ans,x=163;
	
	while(fin.good()){
		ans=ch^x;
		
		fout<<ans;
		
		ch=fin.get();
	}
}
/*










                           _ooOoo_
                          o8888888o
                          88" . "88
                          (| -_- |)
                          O\  =  /O
                       ____/`---'\____
                     .'  \\|     |//  `.
                    /  \\|||  :  |||//  \
                   /  _||||| -:- |||||-  \
                   |   | \\\  -  /// |   |
                   | \_|  ''\---/''  |   |
                   \  .-\__  `-`  ___/-. /
                 ___`. .'  /--.--\  `. . __
              ."" '<  `.___\_<|>_/___.'  >'"".
             | | :  `- \`.;`\ _ /`;.`/ - ` : | |
             \  \ `-.   \_ __\ /__ _/   .-` /  /
        ======`-.____`-.___\_____/___.-`____.-'======
                           `=---='
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                 佛祖保佑       永无BUG
*/