#include "OS.h"

//登录用户名
void login(){
	system("cls");
	textcolor(11);
	cout << "********************************************************************************" << endl;
	cout << "***********                 欢迎使用文件管理系统                    ************" << endl;
	cout << "********************************************************************************" << endl;
	while (1){
		textcolor(13);
		cout << "\n请登录文件系统(输入exit退出文件系统)： ";
		cin >> user;
		if (user == "exit"){
			textcolor(9);
			cout << "\n退出成功，谢谢使用！\n";
			exit(0);
		}
		int res = checkUser(user);
		if (!res){
			textcolor(12);
			cout << "\n不存在的用户，请重新输入！\n";
			continue;
		}
		textcolor(10);
		cout << "\n登陆成功，回车进入文件系统" << endl;
		getchar();
		getchar();
		break;
	}

}

//判断此时用户
int checkUser(string user){
	if (user == "user1")
		return 1;
	else if (user == "user2")
		return 2;
	else if (user == "user3")
		return 3;
	else if (user == "user4")
		return 4;
	else if (user == "user5")
		return 5;
	else if (user == "user6")
		return 6;
	else if (user == "user7")
		return 7;
	else if (user == "user8")
		return 8;
	else
		return 0;
}


//检查当前用户对文件的读写权限
int checkFileAuth(string filename){
	int pos = -1;
	for (int i = 0; i < fileSystem.sfd[cur_SFD].sfdVec.size(); i++){
		if (filename == fileSystem.sfd[cur_SFD].sfdVec[i].name){
			pos = i;
			break;
		}
	}
	if (pos == -1)
		return -2;
	int cur_inode = fileSystem.sfd[cur_SFD].sfdVec[pos].id;
	if (fileSystem.iNode[cur_inode].type == 1)        //1表示当前i结点是目录
		return -3;
	int use = checkUser(user) - 1;
	return fileSystem.iNode[cur_inode].auth[use];
}



//检查当前用户对目录的读写权限
int checkDirAuth(string filename){
	int pos = -1;
	for (int i = 0; i < fileSystem.sfd[cur_SFD].sfdVec.size(); i++){   //检查当前目录下是否存在
		if (filename == fileSystem.sfd[cur_SFD].sfdVec[i].name){
			pos = i;
			break;
		}
	}
	if (pos != -1)
		return -2;

	int cur_inode = getInodeNum();       //获得当前目录的i结点号
	int use = checkUser(user);
	if (use == fileSystem.iNode[cur_inode].id)   //检查是否有权限
		return 1;
	return 0;
}

//登出
void logout(){
	exitSystem();
	user = "";
}
