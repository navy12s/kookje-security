
Conversation opened. 2 messages. 1 message unread.

Skip to content
Using Gmail with screen readers
Search



Gmail
COMPOSE
Labels
Inbox (66)
Starred
Important
Sent Mail
Drafts
Journey
IUPUI
Sharath Babu 238
TechGig
More labels 
Hangouts

 
 
 
  More 
1 of 1,162  
//Implementation of OSI MODEL
#include<stdio.h>
#include<string.h>
int i,len;
char temp[256],str[256],sessmsg[256];

void application(char* str)
{
	char appmsg[256];
	strcpy(appmsg,"A"); //Append application layer header to message
	strcat(appmsg,str);
	sleep(1);
	printf("The message at application layer is: %s\n",appmsg);
	presentation(appmsg);
}
void presentation(char* appmsg)
{
	char presmsg[256];
	strcpy(presmsg,"P");  //Append presentation layer header to data
	strcat(presmsg,appmsg);
        sleep(1);
	printf("The message at presestation layer is: %s\n",presmsg);
	session(presmsg);
}
void session(char* presmsg)
{
	strcpy(sessmsg,"S");  //Append session layer header to data
	strcat(sessmsg,presmsg);
        sleep(1);
	printf("The message at session layer is: %s\n",sessmsg);
	transport(sessmsg);
}
void transport(char* sessmsg)  //data divided into packets
{
	char transmsg[256];
	int count=1;
	int i=0;
	while(sessmsg[i]!='\0')
	{
		strcpy(transmsg,"T");  //Append transport layer header to each packet
		transmsg[1]=sessmsg[i];
		i++;
		if(sessmsg[i]!='\0')
		{
			transmsg[2]=sessmsg[i];
			transmsg[3]='\0';
			i++;
		}
		else if(sessmsg[i]=='\0')
			transmsg[2]='\0';
        	sleep(1);		
		printf("\n\nPacket%d is: %s",count,transmsg);
		network(transmsg);
		count++;
		
	}
}
void network(char* transmsg) //Routing and IP appending to each packet
{
	char netmsg[256];
	strcpy(netmsg,"N");  //Append network layer header to each packet
	strcat(netmsg,transmsg);
        sleep(1);
	printf("\nPacket at network layer is: %s",netmsg);
	datalink(netmsg);
}
void datalink(char* netmsg) //framing of packets
{                       
        char datamsg[256];
        strcpy(datamsg,"D");	//Append datalink  layer header to each frame
        strcat(datamsg,netmsg);
        sleep(1);
        printf("\nPacket at datalink layer is: %s",datamsg);
        physical(datamsg);
}
void physical(char* datamsg)
{                       
        char phymsg[256];
        strcpy(phymsg,"E");	//Append physical  layer header to each frame
        strcat(phymsg,datamsg);
        sleep(1);
        printf("\nPacket at physical layer is: %s",phymsg);
	recp(phymsg);
}
/* now in receiver side we remove headers of sender and extract actual data at application layer */
void recp(char* phymsg) //receive frames from sender
{ 

	printf("\n\t\t~~~~~At Receiver side~~~~~\n");
        char rphy[256];
	len=strlen(phymsg);
	for(i=0;i<len;i++)
		rphy[i]=phymsg[i+1];
	rphy[i]='\0';
        sleep(1);
        printf("\nFrame at physical layer is: %s",rphy);
	recdata(rphy);
}
void recdata(char* rphy) //frames are uncovered and IP packets are received
{ 
        char rdata[256];
        len=strlen(rphy);
        for(i=0;i<len;i++)
                rdata[i]=rphy[i+1];
        rdata[i]='\0';
        sleep(1);
	printf("\nFrame at datalink layer is: %s",rdata);
        recnet(rdata);
}
void recnet(char* rdata) //Transport layer packets are obtained from IP packets
{
        char rnet[256];
        len=strlen(rdata);
        for(i=0;i<len;i++)
                rnet[i]=rdata[i+1];
        rnet[i]='\0';
        sleep(1);
        printf("\nFrame at network layer is: %s",rnet);
	rectrans(rnet);
}
void rectrans(char* rnet) //All packets are received and data is integrated
{
	char rtrance[256];
        len=strlen(rnet);
        for(i=0;i<len;i++)
	{
                rtrance[i]=rnet[i+1];
	}
	other(rtrance);
}
void other(char* rtrance)
{
	char temp[256];
	strcat(temp,rtrance);
	recses(temp);
}
void recses(char* temp) //Session information is checked
{
	char ress[256];
	len=strlen(temp);
	for(i=0;i<len;i++)
		ress[i]=temp[i+1];
	ress[i]='\0';
        sleep(1);
	printf("\nMessage at Session layer is: %s ",ress);
	recpre(ress);
}
void recpre(char* ress) //data format is confirmed
{
	char rpres[256];
        len=strlen(ress);
        for(i=0;i<len;i++)
                rpres[i]=ress[i+1];
        rpres[i]='\0';
        sleep(1);
        printf("\nMessage at Presentation layer is: %s ",rpres);
        recapp(rpres);
}
void recapp(char* rpres) //actual message is delivered
{	
	char rapp[256];
	len=strlen(rpres);
        for(i=0;i<len;i++)
                rapp[i]=rpres[i+1];
        rapp[i]='\0';
        sleep(1);
        printf("\nMessage at Application layer is: %s ",rapp);
}
void main()
{
	printf("Enter the message\n");
	scanf("%s",str);  //Enter actual message to be transmitted
	printf("\n\t\t ~~~~~At Sender Side~~~~~\n");
	application(str);
}