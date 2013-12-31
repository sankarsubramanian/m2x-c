#ifndef M2X_DATASOURCE_H
#define M2X_DATASOURCE_H

#include "third_party/parson/parson.h"

#if defined(__cplusplus)
extern "C" {
#endif

int m2x_datasource_list(m2x_context *ctx, const char *query, char **out);
int m2x_datasource_view(m2x_context *ctx, const char *datasource_id,
                        char **out);

int m2x_datasource_create(m2x_context *ctx, const char *data, char **out);
int m2x_datasource_update(m2x_context *ctx, const char *datasource_id,
                          const char *data, char **out);
int m2x_datasource_delete(m2x_context *ctx, const char *datasource_id,
                          char **out);

int m2x_json_datasource_list(m2x_context *ctx, const char * query,
                             JSON_Value **out);
int m2x_json_datasource_view(m2x_context *ctx, const char *datasource_id,
                             JSON_Value **out);

int m2x_json_datasource_create(m2x_context *ctx, const char *data,
                               JSON_Value **out);
int m2x_json_datasource_update(m2x_context *ctx, const char *datasource_id,
                               const char *data, JSON_Value **out);
int m2x_json_datasource_delete(m2x_context *ctx, const char *datasource_id,
                               JSON_Value **out);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_DATASOURCE_H */
