#include <stdio.h>

#include "m2x.h"
#include "device.h"

const char *M2X_KEY = "";
const char *feed_id = "";
const char *name = "";
const char *description = "";
const char *groups = "";
const char *visibility = "";

int main()
{
  m2x_context *ctx = NULL;
  char buf[2048];
  m2x_response response;

  ctx = m2x_open(M2X_KEY);

  sprintf(buf, "{\"name\": \"%s\", \"description\": \"%s\", \"groups\": \"%s\", \"visibility\": \"%s\"}",
          name, description, groups, visibility);
  printf("Update device %s: %s\n", feed_id, buf);
  response = m2x_device_update(ctx, feed_id, buf);
  printf("Status code: %d\n", response.status);
  if (m2x_is_success(&response) && response.raw) {
    printf("%s\n", response.raw);
  }
  m2x_release_response(&response);
  m2x_close(ctx);
  return 0;
}
