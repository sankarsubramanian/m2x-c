#include <string.h>

#include "m2x.h"
#include "client.h"
#include "batch.h"
#include "utility.h"

int m2x_batch_list(m2x_context *ctx, const char *query, char **out)
{
  int ret;
  char *path;

  path = m2x_internal_create_query_path(ctx, "/batches", query);

  ret = m2x_client_get(ctx, path, out);
  m2x_free(path);
  return ret;
}

int m2x_batch_view(m2x_context *ctx, const char *batch_id, char **out)
{
  int ret;
  char *path;

  path = m2x_internal_create_format_string(ctx, "/batches/%s", batch_id);

  ret = m2x_client_get(ctx, path, out);
  m2x_free(path);
  return ret;
}

int m2x_batch_list_datasources(m2x_context *ctx, const char *batch_id,
                               const char *query, char **out)
{
  int ret;
  char *base_path, *path;

  base_path = m2x_internal_create_format_string(ctx, "/batches/%s/datasources", batch_id);
  path = m2x_internal_create_query_path(ctx, base_path, query);
  m2x_free(base_path);

  ret = m2x_client_get(ctx, path, out);
  m2x_free(path);
  return ret;
}

int m2x_batch_create(m2x_context *ctx, const char *data, char **out)
{
  return m2x_client_post(ctx, "/batches", data, out);
}

int m2x_batch_update(m2x_context *ctx, const char *batch_id,
                     const char *data, char **out)
{
  int ret;
  char *path;

  path = m2x_internal_create_format_string(ctx, "/batches/%s", batch_id);

  ret = m2x_client_put(ctx, path, data, out);
  m2x_free(path);
  return ret;
}

int m2x_batch_add_datasource(m2x_context *ctx, const char *batch_id,
                             const char *data, char **out)
{
  int ret;
  char *path;

  path = m2x_internal_create_format_string(ctx, "/batches/%s/datasources",
                                           batch_id);

  ret = m2x_client_post(ctx, path, data, out);
  m2x_free(path);
  return ret;
}

int m2x_batch_delete(m2x_context *ctx, const char *batch_id,
                     char **out)
{
  int ret;
  char *path;

  path = m2x_internal_create_format_string(ctx, "/batches/%s", batch_id);

  ret = m2x_client_delete(ctx, path, out);
  m2x_free(path);
  return ret;
}

int m2x_json_batch_list(m2x_context *ctx, const char *query,
                        JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_batch_list(ctx, query, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_batch_view(m2x_context *ctx, const char *batch_id,
                        JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_batch_view(ctx, batch_id, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_batch_list_datasources(m2x_context *ctx, const char *batch_id,
                                    const char *query, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_batch_list_datasources(ctx, batch_id, query, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_batch_create(m2x_context *ctx, const char *data,
                          JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_batch_create(ctx, data, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_batch_update(m2x_context *ctx, const char *batch_id,
                          const char *data, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_batch_update(ctx, batch_id, data, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_batch_add_datasource(m2x_context *ctx, const char *batch_id,
                                  const char *data, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_batch_add_datasource(ctx, batch_id, data, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_batch_delete(m2x_context *ctx, const char *batch_id,
                          JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_batch_delete(ctx, batch_id, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}
