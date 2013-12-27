#ifndef M2X_BLUEPRINT_H
#define M2X_BLUEPRINT_H

#include "third_party/parson/parson.h"

#if defined(__cplusplus)
extern "C" {
#endif

int m2x_blueprint_list(m2x_context *ctx, char **out);
int m2x_blueprint_view(m2x_context *ctx, const char *blueprint_id, char **out);

int m2x_blueprint_create(m2x_context *ctx, const char *data, char **out);
int m2x_blueprint_update(m2x_context *ctx, const char *blueprint_id,
                         const char *data);
int m2x_blueprint_delete(m2x_context *ctx, const char *blueprint_id);

int m2x_json_blueprint_list(m2x_context *ctx, JSON_Value **out);
int m2x_json_blueprint_view(m2x_context *ctx, const char *blueprint_id,
                            JSON_Value **out);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_BLUEPRINT_H */
