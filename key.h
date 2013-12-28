#ifndef M2X_KEY_H
#define M2X_KEY_H

#include "third_party/parson/parson.h"

#if defined(__cplusplus)
extern "C" {
#endif

int m2x_key_list(m2x_context *ctx, const char *optional_feed_id, char **out);
int m2x_key_view(m2x_context *ctx, const char *key, char **out);

int m2x_key_create(m2x_context *ctx, const char *data, char **out);
int m2x_key_update(m2x_context *ctx, const char *key, const char *data);
int m2x_key_regenerate(m2x_context *ctx, const char *key, char **out);
int m2x_key_delete(m2x_context *ctx, const char *key);

int m2x_json_key_list(m2x_context *ctx, const char *optional_feed_id,
                      JSON_Value **out);
int m2x_json_key_view(m2x_context *ctx, const char *key, JSON_Value **out);

int m2x_json_key_create(m2x_context *ctx, const char *data, JSON_Value **out);
int m2x_json_key_regenerate(m2x_context *ctx, const char *key,
                            JSON_Value **out);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_KEY_H */
