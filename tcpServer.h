#ifndef __tcpServer_H__
#define __tcpServer_H__

#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <time.h>
#include <sys/time.h>
#include "json/json.h"
using namespace std;

//�������ݰ��ṹ��
typedef struct __DATA_PACKAGE
{
	int pack_len;
}DATA_PACKAGE;

//tcp�׽��ֽṹ��
typedef struct __FD_DATA
{
	int fd;					//�׽���
	bool validate;			//�ж��׽����Ƿ���֤ͨ��
	time_t test_time;		//��¼����ʱ��
}FD_DATA;

class tcpServer
{
public:
	tcpServer();
	~tcpServer();

	//����socketͨѶ
	void tcpsocket();

	//������Ϣ���ͻ���
	void senddatatoclient(string sendData, int sendsock_i);

	//�ӿͻ��˽�����Ϣ
	bool recvdatatoclient(int r_fd, bool test);

protected:
private:
	//socketͨѶ�׽���
	int serv_sock;
	int clnt_sock;
	sockaddr_in serv_adr;
	sockaddr_in clnt_adr;

	//�����׽��ּ���
	fd_set reads, cpy_reads;

		
	//�趨�׽�������
	vector<FD_DATA> v_fd_data;
	FD_DATA fd_data;

	//������Ϣ
	string sdata;

	//��������
	char *recvBuf;

	//���հ��峤����Ϣ
	int package_len;
};

#endif