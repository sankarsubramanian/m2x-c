#include <stdio.h>

#include "m2x.h"
#include "device.h"

const char *M2X_KEY="";

int main()
{
  m2x_context *ctx = NULL;
  m2x_response response;
  ctx = m2x_open(M2X_KEY);
  response = m2x_device_list(ctx, NULL);
  printf("Response code: %d\n", response.status);
  if (m2x_is_success(&response)) {
    JSON_Array *devices = json_object_get_array(json_value_get_object(
        response.json), "devices");
    size_t i;
    for (i = 0; i < json_array_get_count(devices); i++) {
      JSON_Object *device = json_array_get_object(devices, i);
      const char *description = json_object_get_string(device, "description");
      printf("Feed ID    : %s\n", json_object_get_string(device, "id"));
      printf("Name       : %s\n", json_object_get_string(device, "name"));
      if (description) {
        printf("Description: %s\n", description);
      }
      printf("\n");
    }
  }
  m2x_release_response(&response);
  m2x_close(ctx);
  return 0;
}
