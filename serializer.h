#ifndef M2X_SERIALIZER_H
#define M2X_SERIALIZER_H

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct json_context {
  char* buf;
  int index;
  int length;
} json_context;

json_context *json_start_array();
json_context *json_start_object();

json_context *json_pack_key(json_context *json, const char *key);
json_context *json_pack_null(json_context *json);
json_context *json_pack_boolean(json_context *json, int b);
json_context *json_pack_fixnum(json_context *json, int n);
json_context *json_pack_string(json_context *json, const char *str);
json_context *json_pack_value(json_context *json, const char *value);
json_context *json_pack_array_start(json_context *json);
json_context *json_pack_array_end(json_context *json);
json_context *json_pack_object_start(json_context *json);
json_context *json_pack_object_end(json_context *json);

char *json_end_array(json_context *json);
char *json_end_object(json_context *json);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_SERIALIZER_H */

