#include "http_parser.h"
#include "stdio.h"
#include "string.h"

int handle_on_message_complete(http_parser *parser) {
  fprintf(stdout, "Message completed!\n");
  return 0;
}

int on_url(http_parser *parser, const char *at, size_t length) {
  fprintf(stdout, "on_url callback: '%s' with length '%zu' \n", at, length);
  return 0;
}

int main() {
  http_parser parser;
  http_parser_settings settings;

  /*Initialize user callbacks and settings */
  http_parser_settings_init(&settings);

  /*Set user callback */
  settings.on_message_complete = handle_on_message_complete;
  settings.on_url = on_url;

  /*Initialize the parser in HTTP_BOTH mode, meaning that it will select between
   *HTTP_REQUEST and HTTP_RESPONSE parsing automatically while reading the first
   *input.
   */
  http_parser_init(&parser, HTTP_BOTH);

  /*Parse request! */
  const char *request = "GET / HTTP/1.1\r\n\r\n";
  int request_len = strlen(request);

  size_t size = http_parser_execute(&parser, &settings, request, request_len);
}