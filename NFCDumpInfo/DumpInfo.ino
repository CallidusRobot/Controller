/*
 * --------------------------------------------------------------------------------------------------------------------
 * Example sketch/program showing how to read data from a PICC to serial.
 * --------------------------------------------------------------------------------------------------------------------
 * This is a MFRC522 library example; for further details and other examples see: https://github.com/miguelbalboa/rfid
 * 
 * Example sketch/program showing how to read data from a PICC (that is: a RFID Tag or Card) using a MFRC522 based RFID
 * Reader on the Arduino SPI interface.
 * 
 * When the Arduino and the MFRC522 module are connected (see the pin layout below), load this sketch into Arduino IDE
 * then verify/compile and upload it. To see the output: use Tools, Serial Monitor of the IDE (hit Ctrl+Shft+M). When
 * you present a PICC (that is: a RFID Tag or Card) at reading distance of the MFRC522 Reader/PCD, the serial output
 * will show the ID/UID, type and any data blocks it can read. Note: you may see "Timeout in communication" messages
 * when removing the PICC from reading distance too early.
 * 
 * If your reader supports it, this sketch/program will read all the PICCs presented (that is: multiple tag reading).
 * So if you stack two or more PICCs on top of each other and present them to the reader, it will first output all
 * details of the first and then the next PICC. Note that this may take some time as all data blocks are dumped, so
 * keep the PICCs at reading distance until complete.
 * 
 * @license Released into the public domain.
 * 
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

#include <SPI.h>
#include <MFRC522.h>

enum {
  // RFID SPI clock
  PIN_RFID_CK = 10,
  // RFID SPI data out
  PIN_RFID_TX = 11,
  // RFID SPI data in, internal pulldown
  PIN_RFID_RX = 12,
  // RFID SPI chip select, active-low
  PIN_RFID_CD = 13
};

SPIClassRP2040* spiBus = &SPI1;
SPISettings spiSettings = SPISettings(4000000u /* 4MHz */, MSBFIRST, SPI_MODE0);
MFRC522_SPI spiRfid = MFRC522_SPI((byte) PIN_RFID_CD, UNUSED_PIN, spiBus, spiSettings);
MFRC522 rfid = MFRC522(&spiRfid);

void setup() {
  Serial.begin();		// Initialize serial communications with the PC
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  delay(3000);
  Serial.println(F("Serial started."));
  delay(2000);

  Serial.println(F("SPI start configure."));
  spiBus->setCS(PIN_RFID_CD);
  spiBus->setRX(PIN_RFID_RX);
  spiBus->setTX(PIN_RFID_TX);
  spiBus->setSCK(PIN_RFID_CK);
  Serial.println(F("SPI configured."));
  delay(2000);
  spiBus->begin();			// Init SPI bus
  Serial.println(F("SPI started."));
  delay(2000);

	rfid.PCD_Init();		// Init MFRC522
	rfid.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
	// Look for new cards
	if ( !rfid.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards
	if ( !rfid.PICC_ReadCardSerial()) {
		return;
	}

	// Dump debug info about the card; PICC_HaltA() is automatically called
	rfid.PICC_DumpToSerial(&(rfid.uid));
}
