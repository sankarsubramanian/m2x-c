#include <stdio.h>
#include <time.h>

#include "m2x.h"
#include "feed.h"
#include "serializer.h"

const char *M2X_KEY = "";
const char *FEED_ID = "";

int iso8601_time(char* buf, int len)
{
  time_t t;

  t = time(NULL);
  return strftime(buf, len, "%Y-%m-%dT%H:%M:%SZ", gmtime(&t));
}

int main()
{
  m2x_context *ctx = NULL;
  json_context *json = NULL;
  char *str = NULL, *json_str = NULL, buf[128];

  iso8601_time(buf, 128);
  json = json_start_object();

  json = json_pack_key(json, "values");
  json = json_pack_object_start(json);  /* object 1 */

  json = json_pack_key(json, "temperature");
  json = json_pack_array_start(json);   /* array 1.1 */

  json = json_pack_object_start(json);  /* object 1.1.1 */

  json = json_pack_key(json, "at");
  json = json_pack_string(json, buf);

  json = json_pack_key(json, "value");
  json = json_pack_string(json, "30.11");

  json = json_pack_object_end(json);    /* object 1.1.1 */

  json = json_pack_array_end(json);     /* array 1.1 */

  json = json_pack_key(json, "humidity");
  json = json_pack_array_start(json);   /* array 1.2 */

  json = json_pack_object_start(json);  /* object 1.2.1 */

  json = json_pack_key(json, "value");
  json = json_pack_string(json, "7.98");

  json = json_pack_object_end(json);    /* object 1.2.1 */

  json = json_pack_array_end(json);     /* array 1.2 */

  json = json_pack_object_end(json);    /* object 1 */

  json_str = json_end_object(json);

  ctx = m2x_open(M2X_KEY);

  printf("\nPosting multiple value:\n");
  if (m2x_feed_post_multiple(ctx, FEED_ID, json_str, &str) == 0) {
    printf("%s\n", str);
    m2x_free(str);
  }
  m2x_free(json_str);

  printf("\nList streams:\n");
  if (m2x_feed_streams(ctx, FEED_ID, &str) == 0) {
    printf("%s\n", str);
    m2x_free(str);
  }

  m2x_close(ctx);

  return 0;
}
