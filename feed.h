#ifndef M2X_FEED_H
#define M2X_FEED_H

#include "third_party/parson/parson.h"

#if defined(__cplusplus)
extern "C" {
#endif

int m2x_feed_list(m2x_context *ctx, const char *query, char **out);
int m2x_feed_view(m2x_context *ctx, const char *feed_id, char **out);
int m2x_feed_log(m2x_context *ctx, const char *feed_id, char **out);
int m2x_feed_location(m2x_context *ctx, const char *feed_id, char **out);
int m2x_feed_streams(m2x_context *ctx, const char *feed_id, char **out);
int m2x_feed_stream(m2x_context *ctx, const char *feed_id,
                    const char *stream_name, char **out);
int m2x_feed_stream_values(m2x_context *ctx, const char *feed_id,
                           const char *stream_name, char **out);

int m2x_json_feed_list(m2x_context *ctx, const char *query, JSON_Value **out);
int m2x_json_feed_view(m2x_context *ctx, const char *feed_id, JSON_Value **out);
int m2x_json_feed_log(m2x_context *ctx, const char *feed_id, JSON_Value **out);
int m2x_json_feed_location(m2x_context *ctx, const char *feed_id, JSON_Value **out);
int m2x_json_feed_streams(m2x_context *ctx, const char *feed_id, JSON_Value **out);
int m2x_json_feed_stream(m2x_context *ctx, const char *feed_id,
                         const char *stream_name, JSON_Value **out);
int m2x_json_feed_stream_values(m2x_context *ctx, const char *feed_id,
                                const char *stream_name, JSON_Value **out);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_FEED_H */
