#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "serializer.h"

int iso8601_time(char* buf, int len)
{
  time_t t;

  t = time(NULL);
  return strftime(buf, len, "%Y-%m-%dT%H:%M:%SZ", gmtime(&t));
}

int main()
{
  json_context *json = NULL;
  char *json_str, buf[128];
  double v;

  json = json_start_object();

  iso8601_time(buf, 128);
  json = json_pack_key(json, "at");
  json = json_pack_string(json, buf);

  json = json_pack_key(json, "booleanValue");
  json = json_pack_boolean(json, 1);

  json = json_pack_key(json, "nullValue");
  json = json_pack_null(json);

  json = json_pack_key(json, "fixnumValue");
  json = json_pack_fixnum(json, 1234);

  v = 3.1415926535897932;
  sprintf(buf, "%.3f", v);
  json = json_pack_key(json, "floatValue");
  json = json_pack_string(json, buf);

  json = json_pack_key(json, "arrayValue");
  json = json_pack_array_start(json);
  json = json_pack_fixnum(json, 1);
  json = json_pack_fixnum(json, 2);
  json = json_pack_fixnum(json, 3);
  json = json_pack_fixnum(json, 4);
  json = json_pack_array_end(json);

  json = json_pack_key(json, "objectValue");
  json = json_pack_object_start(json);
  json = json_pack_key(json, "a");
  json = json_pack_fixnum(json, 1);
  json = json_pack_key(json, "b");
  json = json_pack_fixnum(json, 2);
  json = json_pack_object_end(json);

  json_str = json_end_object(json);

  printf("JSON String: %s", json_str);
  free(json_str);
  return 0;
}
