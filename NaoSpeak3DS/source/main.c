#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER 1024

int main(int argc, char **argv)
{
    int sock;
    struct sockaddr_in server;

	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);
    printf("Naoqi SpeakEasy for 3DS\n");
    sock = socket(AF_INET , SOCK_STREAM , IPPROTO_IP);
    if (sock < 0)
    {
        printf("Could not create socket");
    }
    puts("[^0^] Socket created!");

    server.sin_addr.s_addr = inet_addr("192.168.1.3");
    server.sin_family = AF_INET;
    server.sin_port = htons( 10001 );

    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected!\n");

	while (aptMainLoop())
	{
		hidScanInput();                         //Scanning input from user
		u32 kDown = hidKeysDown();              //Define keypress

		if (kDown & KEY_START) {
		    printf("Quitting");
		    break;
		}

		static SwkbdState swkbd;                //State of Software Keyboard
		static char message[1024];
		static SwkbdStatusData swkbdStatus;     //Status of Software Keyboard
		SwkbdButton button = SWKBD_BUTTON_NONE;
		bool didit = false;                     //Flag for keypress


		if (kDown & KEY_A)
		{
			didit = true;
			swkbdInit(&swkbd, SWKBD_TYPE_NORMAL, 3, -1);
			swkbdSetInitialText(&swkbd, message);
			swkbdSetHintText(&swkbd, "Enter Message");
			swkbdSetButton(&swkbd, SWKBD_BUTTON_LEFT, "Cancel", false);
			swkbdSetButton(&swkbd, SWKBD_BUTTON_MIDDLE, "?", true);
			swkbdSetButton(&swkbd, SWKBD_BUTTON_RIGHT, "Send", true);
			//swkbdSetFeatures(&swkbd, SWKBD_PREDICTIVE_INPUT);
			static bool reload = false;
			swkbdSetStatusData(&swkbd, &swkbdStatus, reload, true);
			reload = true;
			button = swkbdInputText(&swkbd, message, sizeof(message));
		}

		if (didit)
		{
			if (button != SWKBD_BUTTON_NONE)
			{
			    printf("%s\n", message);
                fgets(message,BUFFER,stdin);

                if( send(sock , message , strlen(message) , 0) < 0)
                {
                    puts("Send failed");
                    return 1;
                }

			} else
				printf("swkbd event: %d\n", swkbdGetResult(&swkbd));
		}

		gfxFlushBuffers();
		gfxSwapBuffers();

		gspWaitForVBlank();
	}
	close(sock);
	gfxExit();
	return 0;
}