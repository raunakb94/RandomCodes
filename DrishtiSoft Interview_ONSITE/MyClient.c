#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
/*
 * go to the Main function directly
 *
 *
 */

int portno = 6677;

#define MESSAGE_TEXT_MAX_LENGTH 512
#define MESSAGE_STRUCT_MAX_LENGTH 612

int sockfd = -1;
static int chances = 0;
struct my_message {
	/* length of the text in the message */
	int length;

	/* category to identify the message */
	int category;

	/* text to send in a message */
	char text[MESSAGE_TEXT_MAX_LENGTH];
} my_message;

struct coordinate{
    int i,j;
    }c;

struct chessboard{
    int arr[8][8];
    struct coordinate k[2];
    int count;
    }*board;

void	error(const char *msg);
void	init();

/* Write the message to other clients */
void	writeMessage(struct my_message msg);

/* Read the incoming message from server. msg is populated with the read message.
 * It waits for an incoming message only
 */
int	readMessageWithTimeout(struct my_message *msg, int timeout_ms);
int	readMessageSurely(struct my_message *msg);

//My defined Functions
int rule[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{-1,2},{1,2},{1,-2},{-1,-2}};
struct coordinate predictNextMove()
{
    printf("Predicting");
    int numKnights = board->count;
    int ch_knight = rand()%2;
    int r,dx,dy,x,y;
    if(ch_knight == 0)
    {
        if(board->arr[board->k[0].i][board->k[0].j]==1)
        {
             r = rand()%8;
             dx = board->k[0].i + rule[r][0];
             dy = board->k[0].j + rule[r][1];
             x = board->k[0].i;
             y = board->k[0].j;
             board->k[0].i=dx;
             board->k[0].j=dy;
        }
        else
            {
            r = rand()%8;
             dx = board->k[1].i + rule[r][0];
             dy = board->k[1].j + rule[r][1];
             x = board->k[1].i;
             y = board->k[1].j;
              board->k[1].i=dx;
             board->k[1].j=dy;
            }
    }
    else
    {
        if(board->arr[board->k[1].i][board->k[1].j]==1)
        {
            r = rand()%8;
             dx = board->k[1].i + rule[r][0];
             dy = board->k[1].j + rule[r][1];
             board->arr[board->k[1].i][board->k[1].j]=0;
             x = board->k[1].i;
             y = board->k[1].j;
              board->k[1].i=dx;
             board->k[1].j=dy;
            }
        else{
             r = rand()%8;
             dx = board->k[0].i + rule[r][0];
             dy = board->k[0].j + rule[r][1];
             x = board->k[0].i;
             y = board->k[0].j;
              board->k[0].i=dx;
             board->k[0].j=dy;
        }

    }

    if(board->arr[dx][dy]==1 || board->arr[dx][dy]==3)
    {
        return predictNextMove();
    }
    c.i =dx;
    c.j =dy;
    board->arr[x][y]=3;
    board->arr[dx][dy]=1;
    return c;

}
void updateMove(struct coordinate temp,int i,int sender)
{
    if(i==2 && sender ==0)
    {board->arr[temp.i][temp.j]=i;
    printf("Updated Others Coordinated");
    }
    else
    if(board->arr[temp.i][temp.j]==2 &&sender == 0 )
    {
        board->arr[temp.i][temp.j]==1;
        //Send a response to other pLAER
        struct my_message conqueredMsg;
        conqueredMsg.category = -4;
        int j;
        writeMessage(conqueredMsg);
        for( j=0;j<2;j++)
        {
            if(j==0)
            {
                char str[512];
                sprintf(str,"%d",temp.i);
                strcpy(conqueredMsg.text,str);
            }
            else
            {
                char str[512];
                sprintf(str,"%d",temp.j);
                strcpy(conqueredMsg.text,str);
            }
            printf("\nConquered");
            writeMessage(conqueredMsg);
        }
    }
    else
    {board->arr[temp.i][temp.j]=i;
    printf("UPdated Own Coordinate");
    }
    return;
}
void printOwnMatrix()
{
    int i,j;
    for( i=0;i<8;i++)
    {
        for( j=0;j<8;j++)
        {
            printf("%d",board->arr[i][j]);
        }
        printf("\n");
    }
}

int initBoards(int own,int other,struct chessboard *board)
{
    if(own<other)
    {
        board->arr[3][3]=1;//Own
        board->arr[4][4]=1;
        board->k[0].i = 3;
        board->k[1].i = 4;
        board->k[0].j = 3;
        board->k[1].j = 4;
        board->arr[3][4]=2;//Opponent
        board->arr[4][3]=2;
    }
    else
    {
        board->arr[3][4]=1;//Own
        board->arr[4][3]=1;
        board->k[0].i = 3;
        board->k[1].i = 4;
        board->k[0].j = 4;
        board->k[1].j = 3;
        board->arr[3][3]=2;//Opponent
        board->arr[4][4]=2;
    }
    board->count = 2;
    printOwnMatrix();
}


void readResponse(struct my_message msg)
{
    int ch = msg.category;
    if(ch == -3)
    {
        int a[2],i;
        for(i=0;i<2;i++)
        {
            struct my_message readMsg;
            int read_result = readMessageSurely(&readMsg);
            a[i]=atoi(readMsg.text);
        }
        struct coordinate tmp;
        tmp.i = a[0];
        tmp.j = a[1];
        updateMove(tmp,2,0);
    }
    if(ch == -4)
    {
        int a[2],i;
        for( i=0;i<2;i++)
        {
            struct my_message readMsg;
            int read_result = readMessageSurely(&readMsg);
            struct coordinate conquered;
            conquered.i=atoi(readMsg.text);
            readMessageSurely(&readMsg);
            conquered.j = atoi(readMsg.text);
            updateMove(conquered,2,1);
        }
        board->count = board->count - 1;
    }
    if(ch==-5)
    {
        printf("\nYou Have WonBuddy\n");
    }
}


void startPlaying(int i)
{
    struct my_message sendMsg;
    printf("i->> %d",i);
    if(i == 1)
    {
        chances++;
        struct my_message startMsg;
        startMsg.category = -3;
        char tempstr[512];
        sprintf(tempstr,"%d",-3);
        strcpy(startMsg.text,tempstr);

        //Predict First move
        struct coordinate destCoord = predictNextMove();
        printf("i->>%d   j->>%d",destCoord.i,destCoord.j);
        updateMove(destCoord,1,0);
        writeMessage(startMsg);
        int i;
        for( i=0;i<2;i++)
        {
            startMsg.category = -3;
            char tempstr[512];
            if(i==0)
            sprintf(tempstr,"%d",destCoord.i);
            else
            sprintf(tempstr,"%d",destCoord.j);
            strcpy(startMsg.text,tempstr);
            writeMessage(startMsg);
        }
        sleep(6);
    }

    while(board->count>0)
    {
    printOwnMatrix();
    printf("Waiting For Response\n %d",chances);
    struct my_message readMsg;
    int read_result = readMessageSurely(&readMsg);
    if(read_result)
    {
        printf("Sorry Some Problem");
    }
    else
    {
        readResponse(readMsg);
        struct coordinate destCoord = predictNextMove();
        struct my_message sendMessage;
        printf("i->>%d   j->>%d",destCoord.i,destCoord.j);
        updateMove(destCoord,1,0);
        struct my_message updateMessage;
        updateMessage.category = -3;
        writeMessage(updateMessage);
        int i;
        for(i=0;i<2;i++)
        {
            sendMessage.category = -3;
            char tempstr[512];
            if(i==0)
            sprintf(tempstr,"%d",destCoord.i);
            else
            sprintf(tempstr,"%d",destCoord.j);
            strcpy(sendMessage.text,tempstr);
            writeMessage(sendMessage);
        }
        chances++;
    }

    }

    struct my_message winningMessage;
    winningMessage.category = -5;
    writeMessage(winningMessage);
}

void gameStart(int own,int other)
{
    //struct chessboard *board;
    board = (struct chessboard *)malloc(sizeof(struct chessboard));
    printf("starting game with own Id %d and opp id %d\n",own,other);
    memset(board->arr,0,sizeof(board->arr));
    initBoards(own,other,board);
    printf("\nNow Boards are initialised Lets Dtart The Game\n");
    if(own<other)
    {
        startPlaying(1);

    }
    else
    {
        startPlaying(2);
    }
}

int main(int argc, char *argv[]) {

	// initialize and connect
	init();
	printf("\n");

	/*
	 * Write your code in the lines below.
	 * The following code shows a sample where it generates a random message and sends it
	 * Then it reads an incoming message. It waits for that message for a limited time and continues
	 * If an incoming message is received, then it print its
	 *
	 *
	 *
	 */

	// generate a random name for myself. This is not mandatory
	char client_name[20];
	time_t t;
	srand((unsigned) time(&t));
	int ownId = rand()*1000;
	//sprintf(client_name, "name%d", nr);
    int ch = 1;
	printf("client_name: %d\n", ownId);

		struct my_message rand_message;
		rand_message.category = 1; // some category

		// generate some random message
		int r = rand()*1000;
		sprintf(rand_message.text,"%d",ownId);

		writeMessage(rand_message);

		// the message read from the server will be stored in this
		struct my_message read_message;

		// timeout to wait for an incoming message before ignoring and continuing
		int timeout_ms = 500;

		int read_result = readMessageSurely(&read_message);
		// or if you may use this API
		// int read_result = readMessageSurely(&read_message);

		if (read_result == 0) {
			printf("read from server: %s\n", read_message.text);
			writeMessage(rand_message);
			int oppId = atoi(read_message.text);
			gameStart(ownId,oppId);
		} else {
			printf("read returned: %d\n", read_result);

		}
       // scanf("%d",&ch);


	/*
	 * Write your code in the lines above
	 *
	 */


	printf("\nSee You Tata");
	// close the connection
	close(sockfd);
	return 0;
}

void error(const char *msg)
{
	perror(msg);
	exit(0);
}

void init() {

	int n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	server = gethostbyname("localhost");

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");
	if (server == NULL) {
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr,
			(char *)&serv_addr.sin_addr.s_addr,
			server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR connecting");
}

int parseMessage(char *buffer, struct my_message *msg) {

	int num_items_expected = 3;

	// TODO: read only till the possible buffer size or does sscanf already take care of that ?
	int parse_res = sscanf(buffer, "%d:%d:%s\n", &msg->length, &msg->category, msg->text);

	if (parse_res != 3 || parse_res == EOF) {
		// sscanf returns the number of items read successfully. It can also return EOF if input ended early
		return -1;
	} else {
		// TODO: validate the received length field and the actual length
		return 0;
	}
}

void writeMessage(struct my_message msg) {
	char buffer[1024];
	bzero(buffer, 1024);

	msg.length = strlen(msg.text);
	sprintf(buffer, "%d:%d:%s\n", msg.length, msg.category, msg.text);

	int n = write(sockfd, buffer, strlen(buffer));
	if (n < 0)
		error("ERROR writing to socket");

}

int readMessageWithTimeout(struct my_message *msg, int timeout_ms) {
	return _readMessage(msg, timeout_ms, 1);
}
int readMessageSurely(struct my_message *msg) {
	return _readMessage(msg, -1, 0);
}

int _readMessage(struct my_message *msg, int timeout_ms, int timeout_required) {

	char buffer[MESSAGE_STRUCT_MAX_LENGTH];
	bzero(buffer, MESSAGE_STRUCT_MAX_LENGTH);

	/*
	 * do a select() on the socket to see if it really has something to read
	 *
	 */
	if (timeout_required) {
		fd_set set;
		struct timeval timeout;
		/* Initialize the file descriptor set. */
		FD_ZERO (&set);
		FD_SET (sockfd, &set);

		/* Initialize the timeout data structure. */
		timeout.tv_sec = 0;
		timeout.tv_usec = timeout_ms * 1000;

		int select_res = select (FD_SETSIZE, &set, NULL, NULL, &timeout);
		if (select_res == 0) {
			// timeout occurred
			return -1;
		} else if (select_res == 1) {
			// input available. continue
		} else if (select_res == -1) {
			// some error
			// TODO: print the error also
			return -1;
		}
		// select was successful, continue
	}

	// TODO: handle partial read
	int n = read(sockfd, buffer, MESSAGE_STRUCT_MAX_LENGTH);
	if (n < 0) {
		error("ERROR reading from socket");
	} else {
		//printf("buffer: %s\n",buffer);
		int parse_res = parseMessage(buffer, msg);
		return 0;
	}


}

