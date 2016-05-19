#include <stdio.h>

#include "m2x.h"
#include "collection.h"

const char *M2X_KEY = "";
const char *device_id = "";
const char *collection_id = "";

int main()
{
  m2x_context *ctx = NULL;
  m2x_response response;

  ctx = m2x_open(M2X_KEY);
                    
  printf("Adding device to collection: %s...\n", collection_id);
  
  response = m2x_collection_add_device(ctx, collection_id, device_id, NULL);
  
  printf("Status code: %d\n", response.status);

  m2x_release_response(&response);
  m2x_close(ctx);
  return 0;
}
