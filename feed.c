#include <string.h>

#include "m2x.h"
#include "client.h"
#include "feed.h"
#include "utility.h"

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

  len = m2x_internal_encoded_sprintf(NULL, "/feeds/%s", feed_id) + 1;
  if (suffix) { len += strlen(suffix); }

  path = (char *) m2x_malloc(ctx, len);
  index = m2x_internal_encoded_sprintf(path, "/feeds/%s", feed_id);
  if (suffix) { strcpy(path + index, suffix); }

  ret = m2x_client_get(ctx, path, out);
  m2x_free(path);
  return ret;
}

static int m2x_feed_get2(m2x_context *ctx, const char *feed_id,
                         const char* midix, const char *item,
                         const char *suffix, char **out)
{
  int ret, len, index;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/feeds/%s/%s/%s",
                                     feed_id, midix, item) + 1;
  if (suffix) { len += strlen(suffix); }

  path = (char *) m2x_malloc(ctx, len);
  index = m2x_internal_encoded_sprintf(path, "/feeds/%s/%s/%s",
                                       feed_id, midix, item);
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
  return m2x_feed_get2(ctx, feed_id, "streams", stream_name, NULL, out);
}

int m2x_feed_stream_values(m2x_context *ctx, const char *feed_id,
                           const char *stream_name, char **out)
{
  return m2x_feed_get2(ctx, feed_id, "streams", stream_name, "/values", out);
}

int m2x_feed_triggers(m2x_context *ctx, const char *feed_id, char **out)
{
  return m2x_feed_get1(ctx, feed_id, "/triggers", out);
}

int m2x_feed_trigger(m2x_context *ctx, const char *feed_id,
                     const char *trigger_id, char **out)
{
  return m2x_feed_get2(ctx, feed_id, "triggers", trigger_id, NULL, out);
}

int m2x_feed_update_location(m2x_context *ctx, const char *feed_id,
                             const char *data)
{
  int ret, len;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/feeds/%s/location", feed_id) + 1;
  path = (char *) m2x_malloc(ctx, len);
  m2x_internal_encoded_sprintf(path, "/feeds/%s/location", feed_id);

  ret = m2x_client_put(ctx, path, data, NULL);
  m2x_free(path);
  return ret;
}

int m2x_feed_update_stream(m2x_context *ctx, const char *feed_id,
                           const char *stream_name, const char *data)
{
  int ret, len;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/feeds/%s/streams/%s",
                                     feed_id, stream_name) + 1;
  path = (char *) m2x_malloc(ctx, len);
  m2x_internal_encoded_sprintf(path, "/feeds/%s/streams/%s",
                               feed_id, stream_name);

  ret = m2x_client_put(ctx, path, data, NULL);
  m2x_free(path);
  return ret;
}

int m2x_feed_delete_stream(m2x_context *ctx, const char *feed_id,
                           const char *stream_name)
{
  int ret, len;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/feeds/%s/streams/%s",
                                     feed_id, stream_name) + 1;
  path = (char *) m2x_malloc(ctx, len);
  m2x_internal_encoded_sprintf(path, "/feeds/%s/streams/%s",
                               feed_id, stream_name);

  ret = m2x_client_delete(ctx, path, NULL);
  m2x_free(path);
  return ret;
}

int m2x_feed_post_multiple(m2x_context *ctx, const char *feed_id,
                           const char *data)
{
  int ret, len;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/feeds/%s", feed_id) + 1;
  path = (char *) m2x_malloc(ctx, len);
  m2x_internal_encoded_sprintf(path, "/feeds/%s", feed_id);

  ret = m2x_client_post(ctx, path, data, NULL);
  m2x_free(path);
  return ret;
}

int m2x_feed_create_trigger(m2x_context *ctx, const char *feed_id,
                            const char *data)
{
  int ret, len;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/feeds/%s/triggers", feed_id) + 1;
  path = (char *) m2x_malloc(ctx, len);
  m2x_internal_encoded_sprintf(path, "/feeds/%s/triggers", feed_id);

  ret = m2x_client_post(ctx, path, data, NULL);
  m2x_free(path);
  return ret;
}

int m2x_feed_update_trigger(m2x_context *ctx, const char *feed_id,
                            const char *trigger_id, const char *data)
{
  int ret, len;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/feeds/%s/triggers/%s", feed_id, trigger_id) + 1;
  path = (char *) m2x_malloc(ctx, len);
  m2x_internal_encoded_sprintf(path, "/feeds/%s/triggers/%s", feed_id, trigger_id);

  ret = m2x_client_put(ctx, path, data, NULL);
  m2x_free(path);
  return ret;
}

int m2x_feed_test_trigger(m2x_context *ctx, const char *feed_id,
                          const char *trigger_id)
{
  int ret, len;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/feeds/%s/triggers/%s/test", feed_id, trigger_id) + 1;
  path = (char *) m2x_malloc(ctx, len);
  m2x_internal_encoded_sprintf(path, "/feeds/%s/triggers/%s/test", feed_id, trigger_id);

  ret = m2x_client_post(ctx, path, NULL, NULL);
  m2x_free(path);
  return ret;
}

int m2x_feed_delete_trigger(m2x_context *ctx, const char *feed_id,
                            const char *trigger_id)
{
  int ret, len;
  char *path;

  len = m2x_internal_encoded_sprintf(NULL, "/feeds/%s/triggers/%s", feed_id, trigger_id) + 1;
  path = (char *) m2x_malloc(ctx, len);
  m2x_internal_encoded_sprintf(path, "/feeds/%s/triggers/%s", feed_id, trigger_id);

  ret = m2x_client_delete(ctx, path, NULL);
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

int m2x_json_feed_triggers(m2x_context *ctx, const char *feed_id,
                           JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_feed_triggers(ctx, feed_id, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}

int m2x_json_feed_trigger(m2x_context *ctx, const char *feed_id,
                          const char *trigger_id, JSON_Value **out)
{
  int ret;
  char *str;

  ret = m2x_feed_trigger(ctx, feed_id, trigger_id, &str);
  if (ret == 0) {
    if (out) { *out = json_parse_string(str); }
    m2x_free(str);
  }
  return ret;
}
