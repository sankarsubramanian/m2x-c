#include <stdio.h>

#include "m2x.h"
#include "device.h"

const char *M2X_KEY = "";
const char *device_id = "";

int main()
{
  m2x_context *ctx = NULL;
  m2x_response response;

  ctx = m2x_open(M2X_KEY);

  response = m2x_device_export_values(ctx, device_id, NULL);
  printf("Status code: %d\n", response.status);
  if (m2x_is_success(&response) && response.location) {
    printf("Location: %s\n", response.location);
  }
  m2x_release_response(&response);
  m2x_close(ctx);
  return 0;
}
