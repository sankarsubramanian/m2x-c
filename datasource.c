#include <string.h>

#include "m2x.h"
#include "client.h"
#include "datasource.h"
#include "utility.h"

int m2x_datasource_list(m2x_context *ctx, char **out)
{
  return m2x_client_get(ctx, "/datasources", out);
}

int m2x_datasource_view(m2x_context *ctx, const char *datasource_id,
                        char **out)
{
  int ret, len;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/datasources/%s", datasource_id) + 1;
  path = (char *) m2x_malloc(ctx, len);
  m2x_internal_encoded_sprintf(path, "/datasources/%s", datasource_id);

  ret = m2x_client_get(ctx, path, out);
  m2x_free(path);
  return ret;
}

int m2x_datasource_create(m2x_context *ctx, const char *data, char **out)
{
  return m2x_client_post(ctx, "/datasources", data, out);
}

int m2x_datasource_update(m2x_context *ctx, const char *datasource_id,
                          const char *data)
{
  int ret, len;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/datasources/%s", datasource_id) + 1;
  path = (char *) m2x_malloc(ctx, len);
  m2x_internal_encoded_sprintf(path, "/datasources/%s", datasource_id);

  ret = m2x_client_put(ctx, path, data, NULL);
  m2x_free(path);
  return ret;
}

int m2x_datasource_delete(m2x_context *ctx, const char *datasource_id)
{
  int ret, len;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/datasources/%s", datasource_id) + 1;
  path = (char *) m2x_malloc(ctx, len);
  m2x_internal_encoded_sprintf(path, "/datasources/%s", datasource_id);

  ret = m2x_client_delete(ctx, path, NULL);
  m2x_free(path);
  return ret;
}

int m2x_json_datasource_list(m2x_context *ctx, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_datasource_list(ctx, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_datasource_view(m2x_context *ctx, const char *datasource_id,
                             JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_datasource_view(ctx, datasource_id, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_datasource_create(m2x_context *ctx, const char *data,
                               JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_datasource_create(ctx, data, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}
