#include <stdio.h>

#include "m2x.h"
#include "datasource.h"

const char *M2X_KEY = "";
const char *name = "";
const char *description = "";
const char *tags = "";
const char *visibility = "";

int main()
{
  m2x_context *ctx = NULL;
  char buf[2048], *str = NULL;

  ctx = m2x_open(M2X_KEY);
  m2x_set_verbose(ctx, 1);

  sprintf(buf, "{\"name\": \"%s\", \"description\": \"%s\", \"tags\": \"%s\", \"visibility\": \"%s\"}",
          name, description, tags, visibility);
  printf("\nCreate datasource:\n");
  if (m2x_datasource_create(ctx, buf, &str) == 0) {
    printf("%s\n", str);
    m2x_free(str);
  }

  str = NULL;
  printf("\nList datasource:\n");
  if (m2x_datasource_list(ctx, NULL, &str) == 0) {
    printf("%s\n", str);
    m2x_free(str);
  }

  m2x_close(ctx);
  return 0;
}
