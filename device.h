/** @file device.h
 *  @brief Wrapper for AT&T M2X <a href="https://m2x.att.com/developer/documentation/v2/device">Device API</a>
 */

#ifndef M2X_DEVICE_H
#define M2X_DEVICE_H

#include "response.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#List-Public-Devices-Catalog">List/Search Public Devices Catalog</a> endpoint
 * @param ctx - m2x_context structure
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_catalog(m2x_context *ctx, const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#List-Devices">List Devices</a> endpoint
 * @param ctx m2x_context structure.
 * @param query Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_list(m2x_context *ctx, const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Search-Devices">Search Devices</a> endpoint
 * @param ctx - m2x_context structure.
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_search(m2x_context *ctx, const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#List-Device-Tags">List Device-Tags</a> endpoint
 * @param ctx - m2x_context structure.
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_tags(m2x_context *ctx);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Create-Device">Create Device</a> endpoint
 * @param ctx - m2x_context structure
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_create(m2x_context *ctx, const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Update-Device-Details">Update Device Details</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device being to Update
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_update(m2x_context *ctx, const char *device_id,
                               const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#View-Device-Details">View Device Details</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to get device details
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_view(m2x_context *ctx, const char *device_id);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#View-Request-Log">View Request Log</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to get log
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_view_log(m2x_context *ctx, const char *device_id);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Delete-Device">Delete Device</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to delete
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_delete(m2x_context *ctx, const char *device_id);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Export-Values-from-all-Data-Streams-of-a-Device">Export Values from all Data Streams of a Device</a> endpoint
 * @param ctx - m2x_context structure.
 * @param device_id (str) - ID of the Device to export values
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_export_values(m2x_context *ctx, const char *device_id,
                                      const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Read-Device-Location">Read Device Location</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to get location
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_location(m2x_context *ctx, const char *device_id);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Update-Device-Location">Update Device Location</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to update location
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_location_update(m2x_context *ctx, const char *device_id,
                                        const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Read-Device-Location-History">Read Device Location History</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to get location history
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_location_history(m2x_context *ctx, const char *device_id,
                                         const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Delete-Location-History">Delete Location History</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to delete location history
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_delete_location_history(m2x_context *ctx, const char *device_id,
					const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Search-Values-from-all-Data-Streams-of-a-Device">Search Values from all Data Streams of a Device</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to search values
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_search_values(m2x_context *ctx, const char *device_id,
                                      const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#List-Data-Streams">List Data Streams</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to retrieve the list of data streams
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_streams(m2x_context *ctx, const char *device_id);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Create-Update-Data-Stream">Create/Update Data Stream</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to create/update stream
 * @param stream_name (str) - Name of the stream to be created
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_stream_create(m2x_context *ctx, const char *device_id,
                                      const char *stream_name, const char *data);
#define m2x_device_stream_update m2x_device_stream_create
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Update-Data-Stream-Value">Update Data Stream Value</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to update the current value of specified stream
 * @param stream_name (str) - Name of the stream to be updated
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_stream_value_update(m2x_context *ctx, const char *device_id,
                                            const char *stream_name, const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#View-Data-Stream">View Data Stream</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to get the details of a specific data stream
 * @param stream_name (str) - Name of the stream to get details
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_stream_view(m2x_context *ctx, const char *device_id,
                                    const char *stream_name);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#List-Data-Stream-Values">List Data Stream Values</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to list the details of a specific data stream
 * @param stream_name (str) - Name of the stream to list the details
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters.
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_stream_list_values(m2x_context *ctx, const char *device_id,
                                           const char *stream_name, const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Data-Stream-Sampling">Data Stream Sampling</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to get sample values from an existing data stream
 * @param stream_name (str) - Name of the data stream to get the sample values
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters.
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_stream_sampling(m2x_context *ctx, const char *device_id,
                                        const char *stream_name, const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Data-Stream-Stats">Data Stream Stats</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to get the standard deviation stats for the values on an existing data stream
 * @param stream_name (str) - Name of the data stream to get the standard deviation stats
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_stream_stats(m2x_context *ctx, const char *device_id,
                                     const char *stream_name, const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Post-Data-Stream-Values">Post Data Stream Values</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to post the timestamped values on an existing data stream
 * @param stream_name (str) - Name of the data stream to post the timestamped values
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_stream_post_values(m2x_context *ctx, const char *device_id,
                                           const char *stream_name, const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Delete-Data-Stream-Values">Delete Data Stream Values</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to delete values in a stream
 * @param stream_name (str) - Name of the data stream to delete values
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_stream_delete_values(m2x_context *ctx, const char *device_id,
                                             const char *stream_name, const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Delete-Data-Stream">Delete-Data-Stream</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to delete an existing data stream
 * @param stream_name (str) - Name of the data stream to delete
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_stream_delete(m2x_context *ctx, const char *device_id,
                                      const char *stream_name);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Post-Device-Updates--Multiple-Values-to-Multiple-Streams-">Post Device Updates (Multiple Values to Multiple Streams)</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to post values to multiple streams
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_post_updates(m2x_context *ctx, const char *device_id,
                                     const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Post-Device-Update--Single-Values-to-Multiple-Streams-">Post Device Updates (Single Values to Multiple Streams)</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to post single values to multiple streams
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_post_update(m2x_context *ctx, const char *device_id,
                                    const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/commands#Device-s-List-of-Received-Commands">Device's List of Received Commands</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to list received commands
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_command_list(m2x_context *ctx, const char *device_id,
                                     const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/commands#Device-s-View-of-Command-Details">Device's View of Command Details</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to view command details
 * @param command_id (str) - ID of the Command to view details
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_command_view(m2x_context *ctx, const char *device_id,
                                     const char *command_id);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/commands#Device-Marks-a-Command-as-Processed">Device Marks a Command as Processed</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to marks a command as processed
 * @param command_id (str) - ID of the Command to marks as processed
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_command_process(m2x_context *ctx, const char *device_id,
                                        const char *command_id, const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/commands#Device-Marks-a-Command-as-Rejected">Device Marks a Command as Rejected</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to marks a command as rejected
 * @param command_id (str) - ID of the Command to marks as rejected
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_command_reject(m2x_context *ctx, const char *device_id,
                                       const char *command_id, const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Read-Device-Metadata">Read Device Metadata</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to read metadata
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_metadata(m2x_context *ctx, const char *device_id);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Update-Device-Metadata">Update Device Metadata</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to update metadata
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_metadata_update(m2x_context *ctx,
                                        const char *device_id,
                                        const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Read-Device-Metadata-Field">Read Device Metadata Field</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to read metadata field
 * @param field (str) - Field to read metadata
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_metadata_field(m2x_context *ctx,
                                       const char *device_id,
                                       const char *field);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/device#Update-Device-Metadata-Field">Update Device Metadata Field</a> endpoint
 * @param ctx - m2x_context structure
 * @param device_id (str) - ID of the Device to update metadata field
 * @param field (str) - Field to update metadata
 * @param data (str) - The value to update
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_device_metadata_field_update(m2x_context *ctx,
                                              const char *device_id,
                                              const char *field,
                                              const char *data);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_DEVICE_H */
