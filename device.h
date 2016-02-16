#ifndef M2X_DEVICE_H
#define M2X_DEVICE_H

#include "response.h"

#if defined(__cplusplus)
extern "C" {
#endif

m2x_response m2x_device_catalog(m2x_context *ctx, const char *query);
m2x_response m2x_device_list(m2x_context *ctx, const char *query);
m2x_response m2x_device_search(m2x_context *ctx, const char *query);
m2x_response m2x_device_tags(m2x_context *ctx);
m2x_response m2x_device_create(m2x_context *ctx, const char *data);
m2x_response m2x_device_update(m2x_context *ctx, const char *device_id,
                               const char *data);
m2x_response m2x_device_view(m2x_context *ctx, const char *device_id);
m2x_response m2x_device_view_log(m2x_context *ctx, const char *device_id);
m2x_response m2x_device_delete(m2x_context *ctx, const char *device_id);

m2x_response m2x_device_location(m2x_context *ctx, const char *device_id);
m2x_response m2x_device_location_update(m2x_context *ctx, const char *device_id,
                                        const char *data);
m2x_response m2x_device_search_values(m2x_context *ctx, const char *device_id,
                                      const char *query);

m2x_response m2x_device_streams(m2x_context *ctx, const char *device_id);
m2x_response m2x_device_stream_create(m2x_context *ctx, const char *device_id,
                                      const char *stream_name, const char *data);
#define m2x_device_stream_update m2x_device_stream_create
m2x_response m2x_device_stream_value_update(m2x_context *ctx, const char *device_id,
                                            const char *stream_name, const char *data);
m2x_response m2x_device_stream_view(m2x_context *ctx, const char *device_id,
                                    const char *stream_name);
m2x_response m2x_device_stream_list_values(m2x_context *ctx, const char *device_id,
                                           const char *stream_name, const char *query);
m2x_response m2x_device_stream_sampling(m2x_context *ctx, const char *device_id,
                                        const char *stream_name, const char *query);
m2x_response m2x_device_stream_stats(m2x_context *ctx, const char *device_id,
                                     const char *stream_name, const char *query);
m2x_response m2x_device_stream_post_values(m2x_context *ctx, const char *device_id,
                                           const char *stream_name, const char *data);
m2x_response m2x_device_stream_delete_values(m2x_context *ctx, const char *device_id,
                                             const char *stream_name, const char *data);
m2x_response m2x_device_stream_delete(m2x_context *ctx, const char *device_id,
                                      const char *stream_name);
m2x_response m2x_device_post_updates(m2x_context *ctx, const char *device_id,
                                     const char *data);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_DEVICE_H */
