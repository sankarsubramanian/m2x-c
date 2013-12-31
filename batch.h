#ifndef M2X_BATCH_H
#define M2X_BATCH_H

#include "third_party/parson/parson.h"

#if defined(__cplusplus)
extern "C" {
#endif

int m2x_batch_list(m2x_context *ctx, const char *query, char **out);
int m2x_batch_view(m2x_context *ctx, const char *batch_id, char **out);
int m2x_batch_list_datasources(m2x_context *ctx, const char *batch_id,
                               const char *query, char **out);

int m2x_batch_create(m2x_context *ctx, const char *data, char **out);
int m2x_batch_update(m2x_context *ctx, const char *batch_id,
                     const char *data, char **out);
int m2x_batch_add_datasource(m2x_context *ctx, const char *batch_id,
                             const char *data, char **out);
int m2x_batch_delete(m2x_context *ctx, const char *batch_id,
                     char **out);

int m2x_json_batch_list(m2x_context *ctx, const char *query,
                        JSON_Value **out);
int m2x_json_batch_view(m2x_context *ctx, const char *batch_id,
                        JSON_Value **out);
int m2x_json_batch_list_datasources(m2x_context *ctx, const char *batch_id,
                                    const char *query, JSON_Value **out);

int m2x_json_batch_create(m2x_context *ctx, const char *data,
                          JSON_Value **out);
int m2x_json_batch_update(m2x_context *ctx, const char *batch_id,
                          const char *data, JSON_Value **out);
int m2x_json_batch_add_datasource(m2x_context *ctx, const char *batch_id,
                                  const char *data, JSON_Value **out);
int m2x_json_batch_delete(m2x_context *ctx, const char *batch_id,
                          JSON_Value **out);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_BATCH_H */
