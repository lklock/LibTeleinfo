// **********************************************************************************
// ESP8266 WifInfo WEB Server global Include file
// **********************************************************************************
// Creative Commons Attrib Share-Alike License
// You are free to use/extend this library but please abide with the CC-BY-SA license:
// Attribution-NonCommercial-ShareAlike 4.0 International License
// http://creativecommons.org/licenses/by-nc-sa/4.0/
//
// For any explanation about teleinfo ou use , see my blog
// http://hallard.me/category/tinfo
//
// This program works with the Wifinfo board
// see schematic here https://github.com/hallard/teleinfo/tree/master/Wifinfo
//
// Written by Charles-Henri Hallard (http://hallard.me)
//
// History : V1.00 2015-06-14 - First release
//
// All text above must be included in any redistribution.
//
// **********************************************************************************
#ifndef WIFINFO_H
#define WIFINFO_H

// Include Arduino header
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <EEPROM.h>
#include <Ticker.h>
//#include <WebSocketsServer.h>
//#include <Hash.h>
#include <LibTeleinfo.h>
#include <FS.h>

extern "C" {
#include "user_interface.h"
}

#include "webserver.h"
#include "webclient.h"
#include "config.h"


#define DEBUG
#define DEBUG_SERIAL	Serial
//#define DEBUG_SERIAL1	

#define WIFINFO_VERSION "1.0.1"

// I prefix debug macro to be sure to use specific for THIS library
// debugging, this should not interfere with main sketch or other 
// libraries
#ifdef DEBUG
#define Debug(x)    DEBUG_SERIAL.print(x)
#define Debugln(x)  DEBUG_SERIAL.println(x)
#define DebugF(x)   DEBUG_SERIAL.print(F(x))
#define DebuglnF(x) DEBUG_SERIAL.println(F(x))
#define Debugf(...) DEBUG_SERIAL.printf(__VA_ARGS__)
#define Debugflush  DEBUG_SERIAL.flush
#else
#define Debug(x)    {}
#define Debugln(x)  {}
#define DebugF(x)   {}
#define DebuglnF(x) {}
#define Debugf(...) {}
#define Debugflush  {}
#endif

// sysinfo informations
typedef struct 
{
  String sys_uptime;
} _sysinfo;

// Exported variables/object instancied in main sketch
// ===================================================
extern ESP8266WebServer server;
extern WiFiUDP OTA;
extern TInfo tinfo;
extern unsigned long seconds;
extern _sysinfo sysinfo;
extern Ticker Tick_emoncms;
extern Ticker Tick_jeedom;


// Exported function located in main sketch
// ===================================================
void ResetConfig(void);
void Task_emoncms();
void Task_jeedom();

#endif

