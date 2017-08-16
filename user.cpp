#include "OS.h"

//��¼�û���
void login(){
	system("cls");
	textcolor(11);
	cout << "********************************************************************************" << endl;
	cout << "***********                 ��ӭʹ���ļ�����ϵͳ                    ************" << endl;
	cout << "********************************************************************************" << endl;
	while (1){
		textcolor(13);
		cout << "\n���¼�ļ�ϵͳ(����exit�˳��ļ�ϵͳ)�� ";
		cin >> user;
		if (user == "exit"){
			textcolor(9);
			cout << "\n�˳��ɹ���ллʹ�ã�\n";
			exit(0);
		}
		int res = checkUser(user);
		if (!res){
			textcolor(12);
			cout << "\n�����ڵ��û������������룡\n";
			continue;
		}
		textcolor(10);
		cout << "\n��½�ɹ����س������ļ�ϵͳ" << endl;
		getchar();
		getchar();
		break;
	}

}

//�жϴ�ʱ�û�
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


//��鵱ǰ�û����ļ��Ķ�дȨ��
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
	if (fileSystem.iNode[cur_inode].type == 1)        //1��ʾ��ǰi�����Ŀ¼
		return -3;
	int use = checkUser(user) - 1;
	return fileSystem.iNode[cur_inode].auth[use];
}



//��鵱ǰ�û���Ŀ¼�Ķ�дȨ��
int checkDirAuth(string filename){
	int pos = -1;
	for (int i = 0; i < fileSystem.sfd[cur_SFD].sfdVec.size(); i++){   //��鵱ǰĿ¼���Ƿ����
		if (filename == fileSystem.sfd[cur_SFD].sfdVec[i].name){
			pos = i;
			break;
		}
	}
	if (pos != -1)
		return -2;

	int cur_inode = getInodeNum();       //��õ�ǰĿ¼��i����
	int use = checkUser(user);
	if (use == fileSystem.iNode[cur_inode].id)   //����Ƿ���Ȩ��
		return 1;
	return 0;
}

//�ǳ�
void logout(){
	exitSystem();
	user = "";
}
