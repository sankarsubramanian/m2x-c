#include <string.h>

#include "m2x.h"
#include "client.h"
#include "feed.h"

int m2x_feed_list(m2x_context *ctx, const char *query, char **out)
{
  int ret, query_len, needs_question, len, index;
  char *path;

  query_len = query ? strlen(query) : 0;
  needs_question = (query_len > 0) ? (query[0] != '?') : 0;
  len = 6 + query_len + 1;
  if (needs_question) { len++; }

  path = (char *) m2x_malloc(ctx, len);
  strcpy(path, "/feeds");
  index = 6;
  if (needs_question) { path[index++] = '?'; }
  if (query_len > 0) { strcpy(path + index, query); }

  ret = m2x_client_get(ctx, path, out);
  m2x_free(path);
  return ret;
}

static int m2x_feed_get1(m2x_context *ctx, const char *feed_id,
                         const char *suffix, char **out)
{
  int ret, len, index;
  char *path;

  len = 7 + strlen(feed_id) + 1;
  if (suffix) { len += strlen(suffix); }

  path = (char *) m2x_malloc(ctx, len);
  strcpy(path, "/feeds/");
  index = 7;
  strcpy(path + index, feed_id);
  index += strlen(feed_id);
  if (suffix) { strcpy(path + index, suffix); }

  ret = m2x_client_get(ctx, path, out);
  m2x_free(path);
  return ret;
}

static int m2x_feed_get2(m2x_context *ctx, const char *feed_id,
                         const char *stream_name,
                         const char *suffix, char **out)
{
  int ret, len, index;
  char *path;

  len = 7 + strlen(feed_id) + 9 + strlen(stream_name) + 1;
  if (suffix) { len += strlen(suffix); }

  path = (char *) m2x_malloc(ctx, len);
  strcpy(path, "/feeds/");
  index = 7;
  strcpy(path + index, feed_id);
  index += strlen(feed_id);
  strcpy(path + index, "/streams/");
  index += 9;
  strcpy(path + index , stream_name);
  index += strlen(stream_name);
  if (suffix) { strcpy(path + index, suffix); }

  ret = m2x_client_get(ctx, path, out);
  m2x_free(path);
  return ret;
}

int m2x_feed_view(m2x_context *ctx, const char *feed_id, char **out)
{
  return m2x_feed_get1(ctx, feed_id, NULL, out);
}

int m2x_feed_log(m2x_context *ctx, const char *feed_id, char **out)
{
  return m2x_feed_get1(ctx, feed_id, "/log", out);
}

int m2x_feed_location(m2x_context *ctx, const char *feed_id, char **out)
{
  return m2x_feed_get1(ctx, feed_id, "/location", out);
}

int m2x_feed_streams(m2x_context *ctx, const char *feed_id, char **out)
{
  return m2x_feed_get1(ctx, feed_id, "/streams", out);
}

int m2x_feed_stream(m2x_context *ctx, const char *feed_id,
                    const char *stream_name, char **out)
{
  return m2x_feed_get2(ctx, feed_id, stream_name, NULL, out);
}

int m2x_feed_stream_values(m2x_context *ctx, const char *feed_id,
                           const char *stream_name, char **out)
{
  return m2x_feed_get2(ctx, feed_id, stream_name, "/values", out);
}

int m2x_feed_update_location(m2x_context *ctx, const char *feed_id,
                             const char *data)
{
  int ret, len;
  char *path;

  len = 7 + strlen(feed_id) + 9 + 1;
  path = (char *) m2x_malloc(ctx, len);
  snprintf(path, len, "/feeds/%s/location", path);

  ret = m2x_client_put(ctx, path, data, NULL);
  m2x_free(path);
  return ret;
}

int m2x_feed_update_stream(m2x_context *ctx, const char *feed_id,
                           const char *stream_name, const char *data)
{
  int ret, len;
  char *path;

  len = 7 + strlen(feed_id) + 9 + strlen(stream_name) + 1;
  path = (char *) m2x_malloc(ctx, len);
  snprintf(path, len, "/feeds/%s/streams/%s", feed_id, stream_name);

  ret = m2x_client_put(ctx, path, data, NULL);
  m2x_free(path);
  return ret;
}

int m2x_feed_delete_stream(m2x_context *ctx, const char *feed_id,
                           const char *stream_name)
{
  int ret, len;
  char *path;

  len = 7 + strlen(feed_id) + 9 + strlen(stream_name) + 1;
  path = (char *) m2x_malloc(ctx, len);
  snprintf(path, len, "/feeds/%s/streams/%s", feed_id, stream_name);

  ret = m2x_client_delete(ctx, path, NULL);
  m2x_free(path);
  return ret;
}

int m2x_feed_post_multiple(m2x_context *ctx, const char *feed_id,
                           const char *data)
{
  int ret, len;
  char *path;

  len = 7 + strlen(feed_id) + 1;
  path = (char *) m2x_malloc(ctx, len);
  snprintf(path, len, "/feeds/%s", feed_id);

  ret = m2x_client_post(ctx, path, data, NULL);
  m2x_free(path);
  return ret;
}

int m2x_json_feed_list(m2x_context *ctx, const char *query, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_feed_list(ctx, query, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_feed_view(m2x_context *ctx, const char *feed_id, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_feed_view(ctx, feed_id, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_feed_log(m2x_context *ctx, const char *feed_id, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_feed_log(ctx, feed_id, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_feed_location(m2x_context *ctx, const char *feed_id, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_feed_location(ctx, feed_id, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_feed_streams(m2x_context *ctx, const char *feed_id, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_feed_streams(ctx, feed_id, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_feed_stream(m2x_context *ctx, const char *feed_id,
                         const char *stream_name, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_feed_stream(ctx, feed_id, stream_name, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_feed_stream_values(m2x_context *ctx, const char *feed_id,
                                const char *stream_name, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_feed_stream_values(ctx, feed_id, stream_name, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}
