#include <stdio.h>

#include "m2x.h"
#include "feed.h"

const char *M2X_KEY="";

int main()
{
  m2x_context *ctx = NULL;
  JSON_Value *val = NULL;
  JSON_Array *feeds = NULL;
  size_t i;

  ctx = m2x_open(M2X_KEY);
  if (m2x_json_feed_list(ctx, "", &val) == 0) {
    feeds = json_object_get_array(json_value_get_object(val), "feeds");
    for (i = 0; i < json_array_get_count(feeds); i++) {
      JSON_Object* feed = json_array_get_object(feeds, i);
      printf("Feed id: %s\n", json_object_get_string(feed, "id"));

      printf("   name: %s\n", json_object_get_string(feed, "name"));
      printf("Contains %ld streams\n\n",
             json_array_get_count(json_object_get_array(feed, "streams")));
    }
    json_value_free(val);
  }
  m2x_close(ctx);
  return 0;
}
