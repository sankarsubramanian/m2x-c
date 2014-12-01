#include <stdio.h>

#include "m2x.h"
#include "device.h"

const char *M2X_KEY = "";
const char *feed_id = "";
const char *stream_name = "";
const char *from = "";
const char *end = "";

int main()
{
  m2x_context *ctx = NULL;
  char buf[2048];
  m2x_response response;

  ctx = m2x_open(M2X_KEY);

  sprintf(buf, "{\"from\": \"%s\", \"end\": \"%s\"}",
          from, end);
  printf("Delete device %s stream %s values: %s\n", feed_id, stream_name, buf);
  response = m2x_device_stream_delete_values(ctx, feed_id, stream_name, buf);
  printf("Status code: %d\n", response.status);
  if (m2x_is_success(&response) && response.raw) {
    printf("%s\n", response.raw);
  }
  m2x_release_response(&response);
  m2x_close(ctx);
  return 0;
}

