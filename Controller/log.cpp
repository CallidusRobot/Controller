#include "log.h"

enum LogLevel Log::level = LOG_LEVEL_INFO;

// TODO: mutex

void Log::setup() {
  LOG_PORT.begin();
}

void Log::filter(enum LogLevel level) {
  Log::level = level;
}

void Log::log(enum LogLevel level, const __FlashStringHelper* message, bool value) {
  if (Log::level < level)
    return;

  const __FlashStringHelper* levelName;
  switch (level) {
    case LOG_LEVEL_DEBUG:
      levelName = F("DEBUG");
      break;
    case LOG_LEVEL_INFO:
      levelName = F("INFO");
      break;
    case LOG_LEVEL_WARNING:
      levelName = F("WARNING");
      break;
    case LOG_LEVEL_ERROR:
      levelName = F("ERROR");
      break;
    case LOG_LEVEL_CRITICAL:
      levelName = F("CRITICAL");
      break;
    default:
      return;
  }

  LOG_PORT.print('[');
  LOG_PORT.print(levelName);
  LOG_PORT.print(F(", "));
  LOG_PORT.print(millis(), DEC);
  LOG_PORT.print(F("]: "));
  LOG_PORT.print(message);

  if (value)
    LOG_PORT.print(F(" -> "));
  else
    LOG_PORT.println();
}

void Log::debug(const __FlashStringHelper* message) {
  log(LOG_LEVEL_DEBUG, message, false);
}

template <class T>
void Log::debug(const __FlashStringHelper* message, T value) {
  log(LOG_LEVEL_DEBUG, message, true);
  LOG_PORT.println(value);
}

template <class T>
void Log::debug(const __FlashStringHelper* message, T value, int format) {
  log(LOG_LEVEL_DEBUG, message, true);
  LOG_PORT.println(value, format);
}

void Log::info(const __FlashStringHelper* message) {
  log(LOG_LEVEL_INFO, message, false);
}

template <class T>
void Log::info(const __FlashStringHelper* message, T value) {
  log(LOG_LEVEL_INFO, message, true);
  LOG_PORT.println(value);
}

template <class T>
void Log::info(const __FlashStringHelper* message, T value, int format) {
  log(LOG_LEVEL_INFO, message, true);
  LOG_PORT.println(value, format);
}

void Log::warning(const __FlashStringHelper* message) {
  log(LOG_LEVEL_WARNING, message, false);
}

template <class T>
void Log::warning(const __FlashStringHelper* message, T value) {
  log(LOG_LEVEL_WARNING, message, true);
  LOG_PORT.println(value);
}

template <class T>
void Log::warning(const __FlashStringHelper* message, T value, int format) {
  log(LOG_LEVEL_WARNING, message, true);
  LOG_PORT.println(value, format);
}

void Log::error(const __FlashStringHelper* message) {
  log(LOG_LEVEL_ERROR, message, false);
}

template <class T>
void Log::error(const __FlashStringHelper* message, T value) {
  log(LOG_LEVEL_ERROR, message, true);
  LOG_PORT.println(value);
}

template <class T>
void Log::error(const __FlashStringHelper* message, T value, int format) {
  log(LOG_LEVEL_ERROR, message, true);
  LOG_PORT.println(value, format);
}

void Log::critical(const __FlashStringHelper* message) {
  log(LOG_LEVEL_CRITICAL, message, false);
}

template <class T>
void Log::critical(const __FlashStringHelper* message, T value) {
  log(LOG_LEVEL_CRITICAL, message, true);
  LOG_PORT.println(value);
}

template <class T>
void Log::critical(const __FlashStringHelper* message, T value, int format) {
  log(LOG_LEVEL_CRITICAL, message, true);
  LOG_PORT.println(value, format);
}
