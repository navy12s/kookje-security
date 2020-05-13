#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "osimodel.h"

int i,len;
char temp[256];
char str[256];
char sessmsg[256];

void application(char* str)
{
	char appmsg[256] = { 0 };
	strcpy_s(appmsg, sizeof(appmsg), "A"); // Application layer header
	strcat_s(appmsg, sizeof(appmsg), str);
	Sleep(1000);	// 1초
	printf("The message at application layer is: %s\n",appmsg);
	presentation(appmsg);
}

void presentation(char* appmsg)
{
	char presmsg[256];
	strcpy_s(presmsg, sizeof(presmsg), "P");  // Presentation layer header
	strcat_s(presmsg, sizeof(presmsg), appmsg);
	Sleep(1000);	// 1초
	printf("The message at presentation layer is: %s\n",presmsg);
	session(presmsg);
}

void session(char* presmsg)
{
	strcpy_s(sessmsg, sizeof(sessmsg), "S");  // Session layer header
	strcat_s(sessmsg, sizeof(sessmsg), presmsg);
	Sleep(1000);	// 1초
	printf("The message at session layer is: %s\n",sessmsg);
	transport(sessmsg);
}

void transport(char* sessmsg)  //data divided into packets
{
	char transmsg[256] = { 0 };
	strcpy_s(transmsg, sizeof(transmsg), "T");  // Network layer header
	strcat_s(transmsg, sizeof(transmsg), sessmsg);
	Sleep(1000);	// 1초
	printf("Packet at trnasport layer is: %s\n", transmsg);
	network(transmsg);
}

void network(char* transmsg)
{
	char netmsg[256] = { 0 };
	strcpy_s(netmsg, sizeof(netmsg), "N");  // Network layer header
	strcat_s(netmsg, sizeof(netmsg), transmsg);
	Sleep(1000);	// 1초
	printf("Packet at network layer is: %s\n",netmsg);
	datalink(netmsg);
}

void datalink(char* netmsg) //framing of packets
{                       
    char datamsg[256] = { 0 };
	strcpy_s(datamsg, sizeof(datamsg), "D");	// Datalink layer header
	strcat_s(datamsg, sizeof(datamsg), netmsg);
	Sleep(1000);	// 1초
    printf("Packet at datalink layer is: %s\n",datamsg);
    physical(datamsg);
}

void physical(char* datamsg)
{                       
    char phymsg[256] = { 0 };
	strcpy_s(phymsg, sizeof(phymsg), "E");	// Physical layer header
	strcat_s(phymsg, sizeof(phymsg), datamsg);
	Sleep(1000);	// 1초
    printf("Packet at physical layer is: %s\n",phymsg);
	recp(phymsg);
}

/* Physical Layer header 제거 */
void recp(char* phymsg)
{ 
	printf("\n\n\t~~~~~At Receiver side~~~~~\n");
	char rphy[256] = { 0 };
	len=strlen(phymsg);
	for(i=0;i<len;i++)
		rphy[i]=phymsg[i+1];
	rphy[i]='\0';
	Sleep(1000);	// 1초
	printf("Frame at physical layer is: %s\n",rphy);
	recdata(rphy);
}

/* Data Link Layer header 제거 */
void recdata(char* rphy)
{ 
    char rdata[256] = { 0 };
    len=strlen(rphy);
    for(i=0;i<len;i++)
            rdata[i]=rphy[i+1];
    rdata[i]='\0';
	Sleep(1000);	// 1초
	printf("Frame at datalink layer is: %s\n",rdata);
	recnet(rdata);
}

/* Network Layer header 제거 */
void recnet(char* rdata)
{
	char rnet[256] = { 0 };
    len=strlen(rdata);
    for(i=0;i<len;i++)
            rnet[i]=rdata[i+1];
	Sleep(1000);	// 1초
    printf("Frame at network layer is: %s\n",rnet);
	rectrans(rnet);
}

/* Transport Layer header 제거 */
void rectrans(char* rnet)
{
	char rtrance[256] = { 0 };
	len=strlen(rnet);
	for(i=0;i<len;i++) {
		rtrance[i]=rnet[i+1];
	}
	recses(rtrance);
}

/* Session Layer header 제거 */
void recses(char* temp)
{
	char ress[256] = { 0 };
	len=strlen(temp);
	for(i=0;i<len;i++)
		ress[i]=temp[i+1];
	Sleep(1000);	// 1초
	printf("Message at Session layer is: %s \n",ress);
	recpre(ress);
}

/* Presentation Layer header 제거 */
void recpre(char* ress) //data format is confirmed
{
	char rpres[256] = { 0 };
    len=strlen(ress);
    for(i=0;i<len;i++)
		rpres[i]=ress[i+1];
	Sleep(1000);	// 1초
    printf("Message at Presentation layer is: %s \n",rpres);
    recapp(rpres);
}

/* Application Layer header 제거 */
void recapp(char* rpres) //actual message is delivered
{	
	char rapp[256] = { 0 };
	len=strlen(rpres);
    for(i=0;i<len;i++)
		rapp[i]=rpres[i+1];
	Sleep(1000);	// 1초
    printf("Message at Application layer is: %s \n",rapp);
}
void main()
{
	printf("Enter the message\n");
	scanf_s("%s",str, sizeof(str));  //Enter actual message to be transmitted
	printf("\n\n\t ~~~~~At Sender Side~~~~~\n");
	application(str);
}