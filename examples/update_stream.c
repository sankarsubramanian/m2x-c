#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "m2x.h"
#include "feed.h"

const char *M2X_KEY="";
const char *FEED_ID="";
const char *STREAM_NAME="";

int main()
{
  m2x_context *ctx = NULL;
  char buf[1024], *str = NULL;
  srand(time(NULL));

  sprintf(buf, "{\"value\":\"%d\"}", rand());
  ctx = m2x_open(M2X_KEY);
  if ((m2x_feed_update_stream(ctx, FEED_ID, STREAM_NAME, buf, NULL) == 0) &&
      (m2x_feed_stream(ctx, FEED_ID, STREAM_NAME, &str) == 0)) {
    printf("%s\n", str);
    m2x_free(str);
  }
  m2x_close(ctx);

  return 0;
}
