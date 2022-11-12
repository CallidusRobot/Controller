#ifndef LOG_H
#define LOG_H

#include <Arduino.h>

#define LOG_PORT Serial

enum LogLevel {
  LOG_LEVEL_CRITICAL,
  LOG_LEVEL_ERROR,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_INFO,
  LOG_LEVEL_DEBUG
};

class Log {
  public:
  static void setup();

  static void filter(enum LogLevel level);

  static void debug(const __FlashStringHelper* msg);

  template <class T>
  static void debug(const __FlashStringHelper* msg, T value);

  template <class T>
  static void debug(const __FlashStringHelper* message, T value, int format);

  static void info(const __FlashStringHelper* msg);

  template <class T>
  static void info(const __FlashStringHelper* msg, T value);

  template <class T>
  static void info(const __FlashStringHelper* message, T value, int format);

  static void warning(const __FlashStringHelper* msg);

  template <class T>
  static void warning(const __FlashStringHelper* msg, T value);

  template <class T>
  static void warning(const __FlashStringHelper* message, T value, int format);

  static void error(const __FlashStringHelper* msg);

  template <class T>
  static void error(const __FlashStringHelper* msg, T value);

  template <class T>
  static void error(const __FlashStringHelper* message, T value, int format);

  static void critical(const __FlashStringHelper* msg);

  template <class T>
  static void critical(const __FlashStringHelper* msg, T value);

  template <class T>
  static void critical(const __FlashStringHelper* message, T value, int format);
  
  private:
  static enum LogLevel level;
  Log() {}
  static void log(enum LogLevel level, const __FlashStringHelper* msg, bool value);
};

#endif