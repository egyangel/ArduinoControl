/*
 * A simple sketch that uses WiServer to serve a web page
 */


#include <WiServer.h>

#define WIRELESS_MODE_INFRA	1
#define WIRELESS_MODE_ADHOC	2

// Wireless configuration parameters ----------------------------------------
unsigned char local_ip[] = {192,168,1,34};	// IP address of WiShield
unsigned char gateway_ip[] = {192,168,1,1};	// router or gateway IP address
unsigned char subnet_mask[] = {255,255,255,0};	// subnet mask for the local network
const prog_char ssid[] PROGMEM = {"**your wifi ssid**"};		// max 32 bytes

unsigned char security_type = 2;	// 0 - open; 1 - WEP; 2 - WPA; 3 - WPA2

// WPA/WPA2 passphrase
const prog_char security_passphrase[] PROGMEM = {"***your pass******"};	// max 64 characters

// WEP 128-bit keys
// sample HEX keys
prog_uchar wep_keys[] PROGMEM = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d,	// Key 0
				  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Key 1
				  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Key 2
				  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	// Key 3
				};

// setup the wireless mode
// infrastructure - connect to AP
// adhoc - connect to another WiFi device
unsigned char wireless_mode = WIRELESS_MODE_INFRA;

unsigned char ssid_len;
unsigned char security_passphrase_len;
// End of wireless configuration parameters ----------------------------------------

//boolean ledon=false;
//boolean ledron=false;
int led=0;


// This is our page serving function that generates web pages
boolean sendMyPage(char* URL) {

        if (strcmp(URL, "/led") == 0) {
                          led=1;
        }
        
     /*   if(strcmp(URL, "/ledfalse") == 0){
                      ledon=false;
        
        }
        
                if (strcmp(URL, "/ledr") == 0) {
                          ledron=true;
        }
        
                if(strcmp(URL, "/ledrfalse") == 0){
                      ledron=false;
                }*/

        // COSTRUZIONE PAGINA HTML

      /*  WiServer.print("<html><meta http-equiv='Content-Type' content='text/html;");
	WiServer.println("<div style='width:640px; height:960px;'>");
	WiServer.println("<body background= http://www.labattigiasori.it/arduino/bg.png>");*/
        WiServer.println("<body bgcolor=\"#5aa8f3\">");

	/*if (ledon == 0){
                        WiServer.println("<a href=\"/led\">");
			WiServer.println("<div style= \"position:absolute;top:0px;left:0px\">"); 
                        WiServer.println("<img src=\"");
                        WiServer.print("http://www.labattigiasori.it/arduino/off.png\">");
                        WiServer.println("</a>");}
                       
                      else
                        {
                          WiServer.println("<a href=\"/ledfalse\">");
			 // WiServer.println("<div style= \"position:absolute;top:0px;left:0px\">");
                          WiServer.println("<img src=\"");
                          WiServer.print("http://www.labattigiasori.it/arduino/on.png\">");
                          WiServer.println("</a></body>");
                        };
     
     
     	if (ledron == 0){
                        WiServer.println("<a href=\"/ledr\">");
			//WiServer.println("<div style= \"position:absolute;top:0px;left:0px\">");  
                        WiServer.println("<img src=\"");
                        WiServer.print("http://www.labattigiasori.it/arduino/off.png\">");
                        WiServer.println("</a>");}
                       
                    else
                        {
                          WiServer.println("<a href=\"/ledrfalse\">");
			  //WiServer.println("<div style= \"position:absolute;top:0px;left:0px\">");
                          WiServer.println("<img src=\"");
                          WiServer.print("http://www.labattigiasori.it/arduino/on.png\">");
                          WiServer.println("</a></body>");
                        };*/
     
                        WiServer.println("</a> </div>");
			WiServer.println("<a href=\"/led\">");
			WiServer.println("<div style= \"position:absolute;top:125px;left:180px\">");
                        WiServer.println("<img src=\"");
                        WiServer.print("http://www.labattigiasori.it/");
                        WiServer.print("arduino/reload.png\">");
                        WiServer.println("</a> </div>");

                //  digitalWrite ( 6, ledron);
                  //digitalWrite ( 5, ledon);
if (led==1){
digitalWrite (5, HIGH);
delay(100);
digitalWrite (5 ,LOW);
led=0;
}

        return true;

}

int initTime =0;

void setup() {
  // Initialize WiServer and have it use the sendMyPage function to serve pages
      WiServer.init(sendMyPage); 
  // Enable Serial output and ask WiServer to generate log messages (optional)
//  Serial.begin(57600);
//  WiServer.enableVerboseMode(true);
  pinMode(5, OUTPUT);


}

void loop(){
  if (millis() >= initTime) {
         WiServer.init(sendMyPage); 
    // Send next tweet 5 minutes from now
    initTime += 1000 * 60 * 5;
  }
  // Run WiServer
  WiServer.server_task();
 
   delay(10);

}

