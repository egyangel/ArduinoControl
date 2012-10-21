/*
 * A simple sketch that uses WiServer to serve a web page
 */


#include <WiServer.h>

#define WIRELESS_MODE_INFRA	1
#define WIRELESS_MODE_ADHOC	2

// Wireless configuration parameters ----------------------------------------
unsigned char local_ip[] = {
  192,168,1,34};	// IP address of WiShield
unsigned char gateway_ip[] = {
  192,168,1,1};	// router or gateway IP address
unsigned char subnet_mask[] = {
  255,255,255,0};	// subnet mask for the local network
const prog_char ssid[] PROGMEM = {"***YOUR_SSID***"};		// max 32 bytes

unsigned char security_type = 2;	// 0 - open; 1 - WEP; 2 - WPA; 3 - WPA2

// WPA/WPA2 passphrase
const prog_char security_passphrase[] PROGMEM = {"***YOUR_PASSWORD***"};	// max 64 characters

// WEP 128-bit keys
// sample HEX keys
prog_uchar wep_keys[] PROGMEM = { 
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d,	// Key 0
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

int luce=0;
int led=0;


// This is our page serving function that generates web pages
boolean sendMyPage(char* URL) {

  if (strcmp(URL, "/luce") == 0) {
    led=1;
  }


  if (strcmp(URL, "/led") == 0) {
    if(led==0){
      led=1; //ACCENDE

    }
    else led=0; //SPEGNE
  }


  // COSTRUZIONE PAGINA HTML

  WiServer.println("<body bgcolor=\"#5aa8f3\">");


  WiServer.println("</a> </div>");
  WiServer.println("<a href=\"/led\">");
  WiServer.println("<div style= \"position:absolute;top:125px;left:180px\">");
  WiServer.println("<img src=\"");
  WiServer.print("http://www.labattigiasori.it/");
  WiServer.print("arduino/reload.png\">");
  WiServer.println("<img src=\"");
  WiServer.print("http://www.labattigiasori.it/");
  WiServer.print("arduino/reload.png\">");
  WiServer.println("</a> </div>");

  if (luce==1){
    digitalWrite (5, HIGH);
    delay(100);
    digitalWrite (5 ,LOW);
    led=0;
    //accende e spegne subito per attivare il relè passo passo (per controllare la 220v)
  }

  //CASO DEL LED

  if (led==1){
    digitalWrite (6, HIGH);
  }

  if (led==0){
    digitalWrite (6 ,LOW);
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
  pinMode(6, OUTPUT);


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


