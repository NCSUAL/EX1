#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

//���� ������ ���� 
#define Buffer 128
int main(int argc, char *argv[]){
	//���� 2�� ���� Ȯ��
	if(argc!=2){
		fprintf(stderr,"inja need 2\n");
		exit(1);
	} 
	
	//���� ���� 
	//PF_INET (protocol family internet) -> ipv4 �������� ����Ѵٴ� ��
	//SOCK_STREAM -> ������ ��Ʈ���������� ����Ѵٴ� ��
	//0 -> �⺻ TCP�� �����Ѵٴ� �� 
	int Sock = socket(PF_INET,SOCK_STREAM,0);
	
	printf("server_port_open: %s\n",argv[1]);

	//���� ��ȿ�� �˻�
	if(Sock == -1){
	printf("error_socket\n");
	}
	//���� ���� ����
	else{
	printf("socket create\n");
	}

	//��Ʈ��ũ ���� �Է� - ����
	struct sockaddr_in addr_server;
	
	//�ʱ�ȭ
	memset(&addr_server,0,sizeof(addr_server));

	//string -> integer
	int port = atoi(argv[1]);
	
	//���� �Է�
	addr_server.sin_family = AF_INET;
	addr_server.sin_addr.s_addr =htonl(INADDR_ANY);
	addr_server.sin_port = htons(port);

	//���ε�, ��ȿ�� �˻� -> ������ �� ��Ʈ��ũ ������ ����Ѵٰ� ��ġ�� �˸�
	//sockaddr�� ����ȯ ���������
	if(bind(Sock, (struct sockaddr*) &addr_server,sizeof(addr_server)) == -1){
	printf("bind error\n");
	}
	else{
	printf("bind complete\n");
	}

	//���� -> Ŭ���̾�Ʈ ��û�� ����
	if(listen(Sock,43)==-1){
	printf("listen function error\n");
	}
	else{
	printf("wait...\n"); 
	}

	//Ŭ���̾�Ʈ ��û ����

	//Ŭ���̾�Ʈ ipv4�ּ�
	struct sockaddr_in client_server;
	//sockaddr_in ���������� -> socklen_t�� �ּұ��̸� ��Ÿ���� �� Ưȭ��
	socklen_t client_server_size = sizeof(client_server);

	//Ŭ���̾�Ʈ ���� & ��û ���
	//sockaddr�� ����ȯ ���������
	int client_socket = accept(Sock,(struct sockaddr*) &client_server , &client_server_size);

	//Ŭ���̾�Ʈ ���� ��ȿ�� �˻�
	if(client_socket == -1){
	printf("accept_error\n");
	}
	else{
	printf("connect complete\n");
	}
}
