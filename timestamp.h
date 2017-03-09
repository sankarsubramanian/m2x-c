/** @file timestamp.h
 *  @brief Wrapper for AT&T M2X <a href="https://m2x.att.com/developer/documentation/v2/time">Time API</a>
 */

#ifndef M2X_TIMESTAMP_H
#define M2X_TIMESTAMP_H

#include <time.h>

#include "response.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/time">Time</a> endpoint.
 * Get time in seconds, millis & iso8601 in JSON format.
 * @param ctx - m2x_context structure
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_timestamp_json(m2x_context *ctx);

/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/time">Time</a> endpoint.
 * Get time in seconds. For this function no JSON object will be generated since the response is in RAW text.
 * @param ctx - m2x_context structure
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_timestamp_seconds_raw(m2x_context *ctx);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/time">Time</a> endpoint.
 * Get time in milliseconds. For this function no JSON object will be generated since the response is in RAW text.
 * @param ctx - m2x_context structure
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_timestamp_millis_raw(m2x_context *ctx);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/time">Time</a> endpoint.
 * Get time in iso8601 format. For this function no JSON object will be generated since the response is in RAW text.
 * @param ctx - m2x_context structure
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_timestamp_iso8601_raw(m2x_context *ctx);

#ifdef M2X_ENABLE_LONG_LONG
typedef long long m2x_time_t;
#else  /* M2X_ENABLE_LONG_LONG */
typedef long m2x_time_t;
#endif  /* M2X_ENABLE_LONG_LONG */

/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/time">Time</a> endpoint.
 * Get time in seconds. This function can be used to fetch numeric timestamp directly from M2X server.
 * @param ctx - m2x_context structure
 * @return m2x_time_t - Timestamp in seconds
 */
m2x_time_t m2x_timestamp_seconds_i(m2x_context *ctx);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/time">Time</a> endpoint.
 * Get time in milliseconds. This function can be used to fetch numeric timestamp directly from M2X server.
 * @param ctx - m2x_context structure
 * @return m2x_time_t - Timestamp in millis
 */
m2x_time_t m2x_timestamp_millis_i(m2x_context *ctx);

/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/time">Time</a> endpoint.
 * Get time in iso8601 format. This function can be used to fetch numeric timestamp directly from M2X server.
 * @param ctx - m2x_context structure
 * @return charpointer - Timestamp in iso8601
 */
char *m2x_timestamp_to_iso8601(m2x_context *ctx, m2x_time_t seconds, m2x_time_t millis);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_TIMESTAMP_H */
