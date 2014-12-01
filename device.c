#include "client.h"
#include "device.h"
#include "utility.h"

m2x_response m2x_device_catalog(m2x_context *ctx, const char *query)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_query_path(ctx, "/devices/catalog", query);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_list(m2x_context *ctx, const char *query)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_query_path(ctx, "/devices", query);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_groups(m2x_context *ctx)
{
  int status;
  char *out = NULL;

  status = m2x_client_get(ctx, "/devices/groups", &out);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_create(m2x_context *ctx, const char *data)
{
  int status;
  char *out = NULL;

  status = m2x_client_post(ctx, "/devices", data, &out);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_update(m2x_context *ctx, const char *device_id,
                               const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s", device_id);

  status = m2x_client_put(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_view(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s", device_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_location(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/location", device_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_location_update(m2x_context *ctx, const char *device_id,
                                        const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/location", device_id);

  status = m2x_client_put(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_streams(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams", device_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_create(m2x_context *ctx, const char *device_id,
                                      const char *stream_name, const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s", device_id, stream_name);

  status = m2x_client_put(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_value_update(m2x_context *ctx, const char *device_id,
                                            const char *stream_name, const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/value",
                                           device_id, stream_name);

  status = m2x_client_put(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_view(m2x_context *ctx, const char *device_id,
                                    const char *stream_name)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s", device_id, stream_name);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_list_values(m2x_context *ctx, const char *device_id,
                                           const char *stream_name, const char *query)
{
  int status;
  char *path, *path2, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/values.json", device_id, stream_name);
  path2 = m2x_internal_create_query_path(ctx, path, query);
  m2x_free(path);

  status = m2x_client_get(ctx, path2, &out);
  m2x_free(path2);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_sampling(m2x_context *ctx, const char *device_id,
                                        const char *stream_name, const char *query)
{
  int status;
  char *path, *path2, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/sampling.json", device_id, stream_name);
  path2 = m2x_internal_create_query_path(ctx, path, query);
  m2x_free(path);

  status = m2x_client_get(ctx, path2, &out);
  m2x_free(path2);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_stats(m2x_context *ctx, const char *device_id,
                                     const char *stream_name, const char *query)
{
  int status;
  char *path, *path2, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/stats", device_id, stream_name);
  path2 = m2x_internal_create_query_path(ctx, path, query);
  m2x_free(path);

  status = m2x_client_get(ctx, path2, &out);
  m2x_free(path2);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_post_values(m2x_context *ctx, const char *device_id,
                                           const char *stream_name, const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/values", device_id, stream_name);

  status = m2x_client_post(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_delete_values(m2x_context *ctx, const char *device_id,
                                             const char *stream_name, const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/values", device_id, stream_name);

  status = m2x_client_delete(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_delete(m2x_context *ctx, const char *device_id,
                                      const char *stream_name)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s", device_id, stream_name);

  status = m2x_client_delete(ctx, path, NULL, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_post_updates(m2x_context *ctx, const char *device_id,
                                     const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/updates", device_id);

  status = m2x_client_post(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_trigger_list(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/triggers", device_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_trigger_create(m2x_context *ctx, const char *device_id,
                                       const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/triggers", device_id);

  status = m2x_client_post(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_trigger_view(m2x_context *ctx, const char *device_id,
                                     const char *trigger_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/triggers/%s", device_id, trigger_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_trigger_update(m2x_context *ctx, const char *device_id,
                                       const char *trigger_id, const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/triggers/%s", device_id, trigger_id);

  status = m2x_client_put(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_trigger_test(m2x_context *ctx, const char *device_id,
                                     const char *trigger_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/triggers/%s/test", device_id, trigger_id);

  status = m2x_client_post(ctx, path, NULL, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_trigger_delete(m2x_context *ctx, const char *device_id,
                                       const char *trigger_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/triggers/%s", device_id, trigger_id);

  status = m2x_client_delete(ctx, path, NULL, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_view_log(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/log", device_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_delete(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s", device_id);

  status = m2x_client_delete(ctx, path, NULL, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}
