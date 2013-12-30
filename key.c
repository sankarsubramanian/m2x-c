#include <string.h>

#include "m2x.h"
#include "client.h"
#include "key.h"

int m2x_key_list(m2x_context *ctx, const char *optional_feed_id, char **out)
{
  int ret, len;
  char *path;

  len = 5 + 1;
  if (optional_feed_id) { len += 6 + strlen(optional_feed_id); }
  path = (char *) m2x_malloc(ctx, len);

  strcpy(path, "/keys");
  if (optional_feed_id) {
    strcpy(path + 5, "?feed=");
    strcpy(path + 11, optional_feed_id);
  }

  ret = m2x_client_get(ctx, path, out);
  m2x_free(path);
  return ret;
}

int m2x_key_view(m2x_context *ctx, const char *key, char **out)
{
  int ret, len;
  char *path;

  len = 6 + strlen(key) + 1;
  path = (char *) m2x_malloc(ctx, len);
  sprintf(path, "/keys/%s", key);

  ret = m2x_client_get(ctx, path, out);
  m2x_free(path);
  return ret;
}

int m2x_key_create(m2x_context *ctx, const char *data, char **out)
{
  return m2x_client_post(ctx, "/keys", data, out);
}

int m2x_key_update(m2x_context *ctx, const char *key, const char *data)
{
  int ret, len;
  char *path;

  len = 6 + strlen(key) + 1;
  path = (char *) m2x_malloc(ctx, len);
  sprintf(path, "/keys/%s", key);

  ret = m2x_client_put(ctx, path, data, NULL);
  m2x_free(path);
  return ret;
}

int m2x_key_regenerate(m2x_context *ctx, const char *key, char **out)
{
  int ret, len;
  char *path;

  len = 6 + strlen(key) + 11 + 1;
  path = (char *) m2x_malloc(ctx, len);
  sprintf(path, "/keys/%s/regenerate", key);

  ret = m2x_client_post(ctx, path, NULL, out);
  m2x_free(path);
  return ret;
}

int m2x_key_delete(m2x_context *ctx, const char *key)
{
  int ret, len;
  char *path;

  len = 6 + strlen(key) + 1;
  path = (char *) m2x_malloc(ctx, len);
  sprintf(path, "/keys/%s", key);

  ret = m2x_client_delete(ctx, path, NULL);
  m2x_free(path);
  return ret;
}

int m2x_json_key_list(m2x_context *ctx, const char *optional_feed_id,
                      JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_key_list(ctx, optional_feed_id, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_key_view(m2x_context *ctx, const char *key, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_key_view(ctx, key, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_key_create(m2x_context *ctx, const char *data, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_key_create(ctx, data, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_key_regenerate(m2x_context *ctx, const char *key,
                            JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_key_regenerate(ctx, key, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}
